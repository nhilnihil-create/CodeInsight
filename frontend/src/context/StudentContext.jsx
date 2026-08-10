import { createContext, useCallback, useContext, useEffect, useMemo, useRef, useState } from 'react';
import { useAuth } from './AuthContext';
import api from '@/services/api';

const STORAGE_KEY = 'codeinsight:activeSection';

function readStored() {
  try {
    const v = localStorage.getItem(STORAGE_KEY);
    if (v && Number.isFinite(Number(v))) return Number(v);
  } catch { /* ignore */ }
  return null;
}

function persist(id) {
  try {
    localStorage.setItem(STORAGE_KEY, String(id));
  } catch { /* ignore */ }
}

/**
 * StudentContext
 *
 * Single source of truth for the student's enrolled sections and the
 * currently active section (used to scope every /api/student/* request
 * via the ?sectionId= query param).
 *
 * Backed by GET /api/sections, which for a student returns only their
 * active enrollments (dropped_at IS NULL). The active section id is
 * persisted to localStorage and validated against the enrolled list on
 * every load — a valid stored id is kept (returning users land directly
 * in their section), while a missing/stale id is left null so the
 * RequireSection gate can show the section picker first.
 */
const StudentContext = createContext(null);

export function StudentProvider({ children }) {
  const { user } = useAuth();
  const isStudent = user?.role === 'student';

  const activeRef = useRef(readStored());
  const [sections, setSections] = useState([]);
  const [loading, setLoading] = useState(true);
  const [activeSectionId, setActiveSectionIdState] = useState(activeRef.current);

  const applyActiveId = useCallback((id) => {
    activeRef.current = id;
    setActiveSectionIdState(id);
    if (id !== null && id !== undefined) persist(id);
  }, []);

  const recheck = useCallback(async () => {
    if (!isStudent) {
      setSections([]);
      setLoading(false);
      return false;
    }
    setLoading(true);
    try {
      const res = await api.get('/api/sections');
      const list = Array.isArray(res.data) ? res.data : [];
      setSections(list);

      // Resolve the active section in the same update as the list so pages
      // never observe a stale/stored id that is no longer enrolled. A valid
      // stored id is kept; a missing/stale id stays null — never auto-select
      // the first section, because the section picker must be the entry
      // point for students who haven't chosen a section yet.
      if (list.length === 0) {
        if (activeRef.current !== null) applyActiveId(null);
      } else if (!list.some((s) => Number(s.id) === activeRef.current)) {
        if (activeRef.current !== null) applyActiveId(null);
      }
      setLoading(false);
      return list.length > 0;
    } catch {
      setSections([]);
      if (activeRef.current !== null) applyActiveId(null);
      setLoading(false);
      return false;
    }
  }, [isStudent, applyActiveId]);

  useEffect(() => {
    recheck();
  }, [recheck]);

  const setActiveSectionId = useCallback((id) => {
    applyActiveId(id === null || id === undefined ? null : Number(id));
  }, [applyActiveId]);

  const value = useMemo(() => ({
    sections,
    loading,
    checking: loading,
    activeSectionId,
    setActiveSectionId,
    hasSections: !loading && sections.length > 0,
    recheck,
  }), [sections, loading, activeSectionId, setActiveSectionId, recheck]);

  return <StudentContext.Provider value={value}>{children}</StudentContext.Provider>;
}

export function useStudentContext() {
  const ctx = useContext(StudentContext);
  if (!ctx) throw new Error('useStudentContext must be used within a StudentProvider');
  return ctx;
}
