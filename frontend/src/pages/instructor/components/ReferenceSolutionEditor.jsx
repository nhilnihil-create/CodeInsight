import { useEffect, useRef } from 'react';
import { useTheme } from '@/context/ThemeContext';
import { registerMonacoThemes, MONACO_THEMES } from '@/lib/monacoThemes';
import Editor from '@monaco-editor/react';

/**
 * ReferenceSolutionEditor — Monaco Editor for instructor reference solutions.
 *
 * Props:
 *   value    — string, the current reference solution code
 *   onChange — (code: string) => void
 *   height   — string, editor height (default '250px')
 */
export default function ReferenceSolutionEditor({ value, onChange, height = '250px' }) {
  const { theme } = useTheme();
  const monacoRef = useRef(null);

  function handleEditorDidMount(_editor, monaco) {
    monacoRef.current = monaco;
    registerMonacoThemes(monaco);
  }

  return (
    <Editor
      height={height}
      defaultLanguage="cpp"
      language="cpp"
      value={value}
      onChange={(v) => onChange(v || '')}
      theme={MONACO_THEMES[theme === 'dark' ? 'dark' : 'light']}
      onMount={handleEditorDidMount}
      options={{
        minimap: { enabled: false },
        fontSize: 13,
        lineNumbers: 'on',
        scrollBeyondLastLine: false,
        automaticLayout: true,
        wordWrap: 'on',
        tabSize: 2,
        renderWhitespace: 'selection',
      }}
    />
  );
}
