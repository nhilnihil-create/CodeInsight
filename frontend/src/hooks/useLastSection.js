import { useState, useEffect } from 'react';
import api from '@/services/api';

const STORAGE_KEY = 'codeinsight:lastSection';

function readStored() {
  try {
    const v = localStorage.getItem(STORAGE_KEY);
    if (v && v !== 'all') return Number(v);
  } catch { /* ignore */ }
  return null;
}

function persist(id) {
  try {
    localStorage.setItem(STORAGE_KEY, String(id));
  } catch { /* ignore */ }
}

/**
 * useLastSection
 *
 * Persisted section selector backed by localStorage.
 * Returns [sectionId, setSectionId] where sectionId is always a number.
 * On first mount, reads localStorage; falls back to fetching the
 * instructor's sections and picking the first one.
 */
export default function useLastSection() {
  const [sectionId, setSectionId] = useState(() => readStored() ?? null);
  const [ready, setReady] = useState(() => readStored() !== null);

  useEffect(() => {
    if (ready) return;
    let cancelled = false;
    api.get('/api/sections')
      .then(({ data }) => {
        if (cancelled) return;
        const list = Array.isArray(data) ? data : [];
        const first = list.length > 0 ? list[0].id : null;
        setSectionId(first);
        if (first != null) persist(first);
        setReady(true);
      })
      .catch(() => {
        if (!cancelled) setReady(true);
      });
    return () => { cancelled = true; };
  }, [ready]);

  const update = (id) => {
    setSectionId(id);
    if (id != null) persist(id);
  };

  return [sectionId, update];
}
