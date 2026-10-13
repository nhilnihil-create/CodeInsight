import { useEffect } from "react";
import Editor from "@monaco-editor/react";
import { Skeleton } from "@/components/ui/skeleton";
import { useTheme } from "@/lib/theme";
import { useEditorPrefs } from "@/context/EditorPrefsContext";
import { registerMonacoThemes, MONACO_THEMES } from "@/lib/monacoThemes";

/**
 * CodeEditorSurface
 * Thin wrapper around @monaco-editor/react.
 *
 * Theme wiring: LIGHT app theme → registered 'ci-light' Monaco theme;
 * DARK app theme → builtin "vs-dark", exactly as before (the registered
 * 'ci-dark-teal' exists for opted-in use but is NOT the default, so dark
 * rendering is pixel-identical to the pre-theme build).
 *
 * We still read the app theme + editor prefs from context so the font /
 * tab size / minimap / word-wrap continue to follow the user's settings.
 */
const MONACO_BG_CSS = `
  .monaco-editor, .monaco-editor-background, .monaco-editor .margin {
    background-color: hsl(var(--background)) !important;
  }
`;

export default function CodeEditorSurface({
  value,
  onChange,
  onMount,
  onAutocompleteAccept,
  language = "cpp",
  readOnly = false,
}) {
  const { theme } = useTheme();
  const { fontSize, tabSize, wordWrap } = useEditorPrefs();

  // Inject scoped Monaco background override on mount; clean up on unmount.
  useEffect(() => {
    const style = document.createElement("style");
    style.setAttribute("data-codeinsight-monaco-bg", "true");
    style.textContent = MONACO_BG_CSS;
    document.head.appendChild(style);
    return () => {
      document.head.removeChild(style);
    };
  }, []);

  // Re-apply the matching Monaco theme when the app theme changes so
  // Monaco doesn't get stuck in the wrong theme after a toggle.
  useEffect(() => {
    if (typeof window === "undefined" || !window.monaco) return;
    window.monaco.editor.setTheme(theme === "light" ? MONACO_THEMES.light : "vs-dark");
  }, [theme]);

  // Wire the autocomplete-accept signal to the caller, then forward the
  // mount so the editor instance reaches the page as before.
  //
  // Monaco removed `editor.onDidAcceptSuggestion` in v0.45 (the CDN loads
  // 0.55.1) — calling it unconditionally crashed the editor on mount. We
  // feature-detect it, and otherwise watch for the accept gesture directly
  // with capture-phase DOM listeners on the editor root: those fire BEFORE
  // Monaco's own keybinding handler (bubble phase), so the suggest widget
  // is still visible when we check.
  const handleEditorMount = (editor, monaco) => {
    try {
      registerMonacoThemes(monaco);
    } catch (err) {
      console.warn("CodeEditorSurface: monaco theme registration skipped", err);
    }
    if (editor && typeof onAutocompleteAccept === "function") {
      try {
        if (typeof editor.onDidAcceptSuggestion === "function") {
          editor.onDidAcceptSuggestion(() => onAutocompleteAccept());
        } else {
          const domNode = editor.getDomNode?.();
          const acceptIfWidgetVisible = () => {
            if (domNode?.querySelector(".suggest-widget.visible")) {
              onAutocompleteAccept();
            }
          };
          const onKeyDown = (e) => {
            if (e.key === "Tab" || e.key === "Enter") {
              acceptIfWidgetVisible();
            }
          };
          const onPointerDown = (e) => {
            if (e.target instanceof Element && e.target.closest(".suggest-widget")) {
              onAutocompleteAccept();
            }
          };
          domNode?.addEventListener("keydown", onKeyDown, true);
          domNode?.addEventListener("pointerdown", onPointerDown, true);
          editor.onDidDispose?.(() => {
            domNode?.removeEventListener("keydown", onKeyDown, true);
            domNode?.removeEventListener("pointerdown", onPointerDown, true);
          });
        }
      } catch (err) {
        // Never let autocomplete wiring crash the editor again.
        console.warn("CodeEditorSurface: autocomplete wiring skipped", err);
      }
    }
    onMount?.(editor, monaco);
  };

  // DARK renders builtin "vs-dark" exactly as before the theme work;
  // LIGHT renders the registered 'ci-light' theme (see lib/monacoThemes.js).
  const monacoTheme = theme === "light" ? MONACO_THEMES.light : "vs-dark";

  return (
    <div
      className="h-full w-full bg-background overflow-hidden"
      data-theme={theme}
    >
      <Editor
        height="100%"
        width="100%"
        language={language}
        value={value}
        onChange={onChange}
        beforeMount={(monaco) => {
          try {
            registerMonacoThemes(monaco);
          } catch (err) {
            console.warn("CodeEditorSurface: monaco theme registration skipped", err);
          }
        }}
        onMount={handleEditorMount}
        theme={monacoTheme}
        loading={<EditorSkeleton />}
        options={{
          theme: monacoTheme,
          fontSize,
          fontFamily: '"JetBrains Mono", ui-monospace, SFMono-Regular, Menlo, Monaco, Consolas, monospace',
          fontLigatures: true,
          tabSize,
          wordWrap: wordWrap ? "on" : "off",
          // Minimap is disabled because it adds visual width on the
          // right edge and Monaco's layout calculations can leave a
          // small blank strip below the last line when it's on.
          minimap: { enabled: false },
          scrollBeyondLastLine: false,
          scrollBeyondLastColumn: 0,
          smoothScrolling: true,
          cursorBlinking: "smooth",
          // "on" adds a phantom line below the last line for the
          // caret animation; "off" pins the caret to the actual
          // last line so the editor ends exactly there.
          cursorSmoothCaretAnimation: "off",
          renderLineHighlight: "gutter",
          // Padding: top 12px gives a small breathing margin from
          // the panel border; bottom MUST be 0 so the editor ends
          // exactly at the last line with no visible empty space.
          padding: { top: 12, bottom: 0 },
          readOnly,
          automaticLayout: true,
          // Render the final newline (cursor) at the actual end of
          // the document, not on a phantom line below it.
          fixedOverflowWidgets: true,
        }}
      />
    </div>
  );
}

function EditorSkeleton() {
  return (
    <div className="h-full w-full p-3 space-y-2 bg-background">
      <Skeleton className="h-4 w-1/3" />
      <Skeleton className="h-4 w-1/2" />
      <Skeleton className="h-4 w-2/3" />
      <Skeleton className="h-4 w-1/4" />
      <Skeleton className="h-4 w-3/5" />
    </div>
  );
}
