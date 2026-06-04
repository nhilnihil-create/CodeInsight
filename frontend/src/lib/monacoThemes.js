/**
 * Monaco theme registration — see spec §5.6.
 *
 * Monaco doesn't read CSS custom properties at runtime, so the 3 themes are
 * hand-mapped to mirror the 3 app palettes in index.css (data-theme overrides).
 * Call registerMonacoThemes(monaco) once on editor mount; the returned
 * MONACO_THEMES map lets CodeEditor pick the right name for the current theme.
 *
 * Idempotent: monaco.editor.defineTheme is happy to redefine a name.
 */

export const MONACO_THEMES = {
  light: 'ci-light',
  dark: 'ci-dark-teal',
  psu: 'ci-psu',
};

export function registerMonacoThemes(monaco) {
  if (!monaco || !monaco.editor) return;
  monaco.editor.defineTheme('ci-light', {
    base: 'vs',
    inherit: true,
    rules: [
      { token: 'comment', foreground: '6a737d', fontStyle: 'italic' },
      { token: 'keyword', foreground: 'd73a49' },
      { token: 'string', foreground: '032f62' },
      { token: 'number', foreground: '005cc5' },
    ],
    colors: {
      'editor.background': '#ffffff',
      'editor.foreground': '#24292e',
      'editorLineNumber.foreground': '#959da5',
      'editorCursor.foreground': '#044289',
      'editor.selectionBackground': '#c8c8fa',
    },
  });

  monaco.editor.defineTheme('ci-dark-teal', {
    base: 'vs-dark',
    inherit: true,
    rules: [
      { token: 'comment', foreground: '6a85a8', fontStyle: 'italic' },
      { token: 'keyword', foreground: '85D2D0' },
      { token: 'string', foreground: 'a99dd4' },
      { token: 'number', foreground: 'fbbf24' },
    ],
    colors: {
      'editor.background': '#0a1018',
      'editor.foreground': '#dce8f5',
      'editorLineNumber.foreground': '#3a4860',
      'editorCursor.foreground': '#85D2D0',
      'editor.selectionBackground': '#1e304d',
    },
  });

  monaco.editor.defineTheme('ci-psu', {
    base: 'vs',
    inherit: true,
    rules: [
      { token: 'comment', foreground: '888888', fontStyle: 'italic' },
      { token: 'keyword', foreground: '7B0F1B' },
      { token: 'string', foreground: '0F4D2E' },
      { token: 'number', foreground: 'B45309' },
    ],
    colors: {
      'editor.background': '#ffffff',
      'editor.foreground': '#7B0F1B',
      'editorLineNumber.foreground': '#B7A6A8',
      'editorCursor.foreground': '#7B0F1B',
      'editor.selectionBackground': '#FFC72C66',
    },
  });
}
