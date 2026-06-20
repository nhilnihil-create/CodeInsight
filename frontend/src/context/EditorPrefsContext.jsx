import { createContext, useContext, useState, useCallback } from 'react';

const STORAGE_KEY = 'codeinsight:editorPrefs';
const DEFAULTS = { fontSize: 14, tabSize: 4, wordWrap: false };

function loadSaved() {
  try {
    const raw = localStorage.getItem(STORAGE_KEY);
    if (raw) return { ...DEFAULTS, ...JSON.parse(raw) };
  } catch { /* ignore */ }
  return { ...DEFAULTS };
}

const EditorPrefsContext = createContext();

export function EditorPrefsProvider({ children }) {
  const [prefs, setPrefs] = useState(loadSaved);

  const updatePref = useCallback((key, value) => {
    setPrefs(prev => {
      const next = { ...prev, [key]: value };
      try { localStorage.setItem(STORAGE_KEY, JSON.stringify(next)); } catch { /* ignore */ }
      return next;
    });
  }, []);

  return (
    <EditorPrefsContext.Provider value={{ ...prefs, updatePref }}>
      {children}
    </EditorPrefsContext.Provider>
  );
}

export function useEditorPrefs() {
  const ctx = useContext(EditorPrefsContext);
  if (!ctx) throw new Error('useEditorPrefs must be used within EditorPrefsProvider');
  return ctx;
}
