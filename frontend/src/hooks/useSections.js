import { useState, useEffect } from 'react';
import api from '@/services/api';

export default function useSections() {
  const [sections, setSections] = useState([]);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    let cancelled = false;
    api.get('/api/sections')
      .then(res => { if (!cancelled) setSections(Array.isArray(res.data) ? res.data : []); })
      .catch(() => { if (!cancelled) setSections([]); })
      .finally(() => { if (!cancelled) setLoading(false); });
    return () => { cancelled = true; };
  }, []);

  return { sections, loading };
}
