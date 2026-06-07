import { ScrollArea } from "@/components/ui/scroll-area";
import { Sparkles, Lightbulb } from "lucide-react";
import { cn } from "@/lib/utils";

/**
 * InstructionsPanel
 * Body for the Instructions section of the left panel. Renders:
 *   - Markdown exercise description
 *   - Function signature (if provided)
 *   - I/O format
 *   - Examples table (if provided)
 *   - Concepts
 *   - Peer benchmark
 *
 * When `bare` is true, the outer chrome (border + header) is skipped
 * so the body can be embedded inside the ProblemPanel section card.
 *
 * Scrollable; fills parent panel height.
 * Tokens only.
 */
export default function InstructionsPanel({ exercise, bare = false }) {
  if (!exercise) return null;

  return (
    <div
      className={cn(
        "flex flex-col h-full min-h-0",
        !bare && "bg-card border-r border-border",
      )}
    >
      <ScrollArea className="flex-1 min-h-0">
        <div className="px-4 py-4 sm:px-5 space-y-5">
          {/* Description */}
          <section className="space-y-2">
            <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
              Description
            </p>
            <Markdown text={exercise.description} />
          </section>

          {/* Function signature */}
          {exercise.functionSignature ? (
            <section className="space-y-1.5">
              <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
                Function signature
              </p>
              <pre className="font-mono text-xs leading-relaxed whitespace-pre-wrap text-foreground rounded-md border border-border bg-muted/30 px-3 py-2">
                {exercise.functionSignature}
              </pre>
            </section>
          ) : null}

          {/* I/O format */}
          {(exercise.inputFormat || exercise.outputFormat) ? (
            <section className="grid gap-3 sm:grid-cols-2">
              {exercise.inputFormat ? <FormatBlock label="Input" body={exercise.inputFormat} /> : null}
              {exercise.outputFormat ? <FormatBlock label="Output" body={exercise.outputFormat} /> : null}
            </section>
          ) : null}

          {/* Examples table */}
          {Array.isArray(exercise.examples) && exercise.examples.length > 0 ? (
            <section className="space-y-1.5">
              <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
                Examples
              </p>
              <div className="rounded-md border border-border overflow-hidden">
                <table className="w-full text-xs font-mono">
                  <thead>
                    <tr className="bg-muted/40 text-muted-foreground">
                      <th className="text-left font-medium px-3 py-1.5 border-b border-border">Input</th>
                      <th className="text-left font-medium px-3 py-1.5 border-b border-border">Output</th>
                    </tr>
                  </thead>
                  <tbody>
                    {exercise.examples.map((ex, i) => (
                      <tr key={i} className="border-b border-border last:border-b-0">
                        <td className="px-3 py-1.5 align-top text-foreground">{ex.input}</td>
                        <td className="px-3 py-1.5 align-top text-foreground">{ex.output}</td>
                      </tr>
                    ))}
                  </tbody>
                </table>
              </div>
            </section>
          ) : null}

          {/* Constraints */}
          {Array.isArray(exercise.constraints) && exercise.constraints.length > 0 ? (
            <section className="space-y-1.5">
              <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
                Constraints
              </p>
              <ul className="list-disc pl-5 space-y-1 text-sm text-foreground">
                {exercise.constraints.map((c, i) => (
                  <li key={i}>{c}</li>
                ))}
              </ul>
            </section>
          ) : null}

          {/* Concepts */}
          {Array.isArray(exercise.concepts) && exercise.concepts.length > 0 ? (
            <section className="space-y-2">
              <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground inline-flex items-center gap-1.5">
                <Sparkles className="h-3 w-3" strokeWidth={1.5} aria-hidden="true" />
                Concepts
              </p>
              <div className="flex flex-wrap items-center gap-1.5">
                {exercise.concepts.map((c) => (
                  <span
                    key={c.code}
                    title={c.name}
                    className="inline-flex items-center rounded-full bg-primary/10 text-primary border border-primary/20 px-2 py-0.5 text-[11px] font-semibold"
                  >
                    {c.code}
                    <span className="ml-1.5 text-primary/70 font-normal normal-case tracking-normal">
                      {c.name}
                    </span>
                  </span>
                ))}
              </div>
            </section>
          ) : null}

          {/* Peer benchmark — opt-in */}
          {exercise.peerBenchmark ? (
            <section className="rounded-md border border-border bg-muted/30 p-3 space-y-1">
              <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground inline-flex items-center gap-1.5">
                <Lightbulb className="h-3 w-3" strokeWidth={1.5} aria-hidden="true" />
                Peer benchmark
              </p>
              <p className="text-xs text-muted-foreground leading-relaxed">
                {exercise.peerBenchmark}
              </p>
            </section>
          ) : null}
        </div>
      </ScrollArea>
    </div>
  );
}

function FormatBlock({ label, body }) {
  return (
    <div className="rounded-md border border-border bg-muted/30 p-3 space-y-1">
      <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
        {label}
      </p>
      <pre className="font-mono text-xs leading-relaxed whitespace-pre-wrap text-foreground">
        {body}
      </pre>
    </div>
  );
}

// ---------------------------------------------------------------------------
// Minimal inline markdown renderer. Handles h1-h3, paragraphs, unordered + 
// ordered lists, inline code, bold, italic, and fenced code blocks.
// Sufficient for the exercise description mock; not a full markdown parser.
// ---------------------------------------------------------------------------
function Markdown({ text }) {
  const blocks = parseBlocks(text);
  return (
    <div className="space-y-3 text-sm leading-relaxed text-foreground">
      {blocks.map((b, i) => renderBlock(b, i))}
    </div>
  );
}

function parseBlocks(text) {
  const lines = text.replace(/\r\n/g, "\n").split("\n");
  const blocks = [];
  let i = 0;

  while (i < lines.length) {
    const line = lines[i];

    if (line.startsWith("```")) {
      const code = [];
      i++;
      while (i < lines.length && !lines[i].startsWith("```")) {
        code.push(lines[i]);
        i++;
      }
      i++;
      blocks.push({ type: "code", content: code.join("\n") });
      continue;
    }

    const h = line.match(/^(#{1,3})\s+(.*)$/);
    if (h) {
      blocks.push({ type: `h${h[1].length}`, content: h[2] });
      i++;
      continue;
    }

    if (/^\s*[-*]\s+/.test(line)) {
      const items = [];
      while (i < lines.length && /^\s*[-*]\s+/.test(lines[i])) {
        items.push(lines[i].replace(/^\s*[-*]\s+/, ""));
        i++;
      }
      blocks.push({ type: "ul", items });
      continue;
    }

    if (/^\s*\d+\.\s+/.test(line)) {
      const items = [];
      while (i < lines.length && /^\s*\d+\.\s+/.test(lines[i])) {
        items.push(lines[i].replace(/^\s*\d+\.\s+/, ""));
        i++;
      }
      blocks.push({ type: "ol", items });
      continue;
    }

    if (!line.trim()) {
      i++;
      continue;
    }

    const para = [line];
    i++;
    while (
      i < lines.length &&
      lines[i].trim() &&
      !/^(#{1,3})\s+/.test(lines[i]) &&
      !/^\s*[-*]\s+/.test(lines[i]) &&
      !/^\s*\d+\.\s+/.test(lines[i]) &&
      !lines[i].startsWith("```")
    ) {
      para.push(lines[i]);
      i++;
    }
    blocks.push({ type: "p", content: para.join(" ") });
  }

  return blocks;
}

function renderBlock(block, i) {
  switch (block.type) {
    case "h1":
      return <h1 key={i} className="text-base font-semibold tracking-tight">{inline(block.content)}</h1>;
    case "h2":
      return <h2 key={i} className="text-sm font-semibold tracking-tight">{inline(block.content)}</h2>;
    case "h3":
      return <h3 key={i} className="text-sm font-semibold">{inline(block.content)}</h3>;
    case "ul":
      return (
        <ul key={i} className="list-disc pl-5 space-y-1">
          {block.items.map((it, j) => <li key={j}>{inline(it)}</li>)}
        </ul>
      );
    case "ol":
      return (
        <ol key={i} className="list-decimal pl-5 space-y-1">
          {block.items.map((it, j) => <li key={j}>{inline(it)}</li>)}
        </ol>
      );
    case "code":
      return (
        <pre key={i} className="rounded-md bg-muted/40 border border-border p-3 text-xs font-mono leading-relaxed overflow-x-auto">
          {block.content}
        </pre>
      );
    case "p":
    default:
      return <p key={i} className="text-sm leading-relaxed">{inline(block.content)}</p>;
  }
}

function inline(text) {
  const segments = [];
  const re = /(`[^`]+`|\*\*[^*]+\*\*|\*[^*]+\*)/g;
  let last = 0;
  let m;
  while ((m = re.exec(text)) !== null) {
    if (m.index > last) segments.push({ kind: "text", value: text.slice(last, m.index) });
    const tok = m[0];
    if (tok.startsWith("`")) {
      segments.push({ kind: "code", value: tok.slice(1, -1) });
    } else if (tok.startsWith("**")) {
      segments.push({ kind: "strong", value: tok.slice(2, -2) });
    } else {
      segments.push({ kind: "em", value: tok.slice(1, -1) });
    }
    last = m.index + tok.length;
  }
  if (last < text.length) segments.push({ kind: "text", value: text.slice(last) });

  return segments.map((s, i) => {
    if (s.kind === "code") {
      return (
        <code key={i} className="rounded bg-muted/60 border border-border px-1 py-0.5 text-[12px] font-mono">
          {s.value}
        </code>
      );
    }
    if (s.kind === "strong") return <strong key={i}>{s.value}</strong>;
    if (s.kind === "em") return <em key={i}>{s.value}</em>;
    return s.value;
  });
}
