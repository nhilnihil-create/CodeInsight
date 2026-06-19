import { useMemo, useRef, useLayoutEffect } from "react";
import { cn } from "@/lib/utils";

const C_KEYWORDS = new Set([
  "auto", "break", "case", "catch", "class", "const", "continue",
  "default", "delete", "do", "else", "enum", "explicit", "extern",
  "false", "finally", "for", "friend", "goto", "if", "include",
  "inline", "namespace", "new", "operator", "private", "protected",
  "public", "return", "signed", "sizeof", "static", "struct",
  "switch", "template", "this", "throw", "true", "try", "typedef",
  "typename", "union", "unsigned", "using", "virtual", "void",
  "volatile", "while", "int", "float", "double", "char", "bool",
  "long", "short", "string", "nullptr", "define", "ifdef",
  "endif", "pragma", "include", "import",
]);

const C_PREPROCESSOR = /^#\s*\w+/;

function tokenizeLine(line) {
  const tokens = [];
  let i = 0;

  while (i < line.length) {
    // String literal
    if (line[i] === '"' || line[i] === "'") {
      const quote = line[i];
      let str = quote;
      i++;
      while (i < line.length && line[i] !== quote) {
        if (line[i] === "\\") { str += line[i] + (line[i + 1] || ""); i += 2; }
        else { str += line[i]; i++; }
      }
      if (i < line.length) { str += line[i]; i++; }
      tokens.push({ text: str, type: "string" });
      continue;
    }

    // Comment
    if (line[i] === "/" && line[i + 1] === "/") {
      tokens.push({ text: line.slice(i), type: "comment" });
      break;
    }

    // Preprocessor
    if (i === 0 && line[i] === "#") {
      tokens.push({ text: line, type: "preprocessor" });
      break;
    }

    // Number literal
    if (/\d/.test(line[i]) && (i === 0 || /[\s,;=<>!+\-*/%()\[\]{}&|^~?:]/.test(line[i - 1]))) {
      let num = "";
      while (i < line.length && /[\d.xXa-fA-F]/.test(line[i])) { num += line[i]; i++; }
      tokens.push({ text: num, type: "number" });
      continue;
    }

    // Word (identifier or keyword)
    if (/[a-zA-Z_]/.test(line[i])) {
      let word = "";
      while (i < line.length && /[a-zA-Z0-9_]/.test(line[i])) { word += line[i]; i++; }
      const type = C_KEYWORDS.has(word) ? "keyword" : /^[A-Z]/.test(word) ? "type" : "identifier";
      tokens.push({ text: word, type });
      continue;
    }

    // Punctuation / operators
    if (/[{}()\[\];,.<>+\-*/=!&|^~?:]/.test(line[i])) {
      tokens.push({ text: line[i], type: "punctuation" });
      i++;
      continue;
    }

    // Whitespace and everything else
    let rest = "";
    while (i < line.length && !/[a-zA-Z0-9_{}\])(\[\];,.<>+\-*/=!&|^~?:"'#\s]/.test(line[i])) {
      rest += line[i]; i++;
    }
    if (rest) { tokens.push({ text: rest, type: "plain" }); continue; }

    tokens.push({ text: line[i], type: "plain" });
    i++;
  }

  return tokens;
}

const COLORS = {
  keyword: "text-purple-400",
  string: "text-emerald-400",
  comment: "text-muted-foreground/50 italic",
  number: "text-amber-400",
  preprocessor: "text-cyan-400",
  type: "text-blue-400",
  punctuation: "text-muted-foreground/70",
  identifier: "text-foreground",
  plain: "text-foreground",
};

export default function CodeViewer({ code, className }) {
  const scrollRef = useRef(null);

  const lines = useMemo(() => {
    if (!code) return [];
    return code.split("\n").map((line) => ({
      lineNumber: true,
      tokens: tokenizeLine(line),
    }));
  }, [code]);

  useLayoutEffect(() => {
    if (scrollRef.current) {
      scrollRef.current.scrollTop = 0;
      // Double-reset after paint to override any browser scroll restoration
      requestAnimationFrame(() => {
        if (scrollRef.current) scrollRef.current.scrollTop = 0;
      });
    }
  }, [code]);

  if (!code) {
    return (
      <div className="flex items-center justify-center h-full text-sm text-muted-foreground">
        No code to display.
      </div>
    );
  }

  return (
    <div ref={scrollRef} className={cn("h-full w-full overflow-auto bg-background font-mono text-sm leading-relaxed", className)}>
      <table className="border-collapse w-full">
        <tbody>
          {lines.map((line, idx) => (
            <tr key={idx} className="hover:bg-muted/20">
              <td className="select-none text-right text-[11px] text-muted-foreground/40 w-12 px-3 py-0 align-top">
                {idx + 1}
              </td>
              <td className="whitespace-pre px-1 py-0">
                {line.tokens.map((t, ti) => (
                  <span key={ti} className={COLORS[t.type] || "text-foreground"}>
                    {t.text}
                  </span>
                ))}
              </td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
}
