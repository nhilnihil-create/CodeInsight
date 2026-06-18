import { useState, useEffect, useCallback } from 'react';
import api from '@/services/api';

export default function useHasSections() {
  const [hasSections, setHasSections] = useState(null);
  const [checking, setChecking] = useState(true);

  const check = useCallback(async () => {
    setChecking(true);
    try {
      const res = await api.get('/api/sections');
      const sections = Array.isArray(res.data) ? res.data : [];
      setHasSections(sections.length > 0);
      return sections.length > 0;
    } catch {
      setHasSections(false);
      return false;
    } finally {
      setChecking(false);
    }
  }, []);

  useEffect(() => { check(); }, [check]);

  return { hasSections, checking, recheck: check };
}
