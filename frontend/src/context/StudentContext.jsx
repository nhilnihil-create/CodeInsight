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
 *
 * A failed recheck (network/API error) preserves the last-known sections
 * and the active section and sets `error` to true so pages can show a
 * retry screen instead of silently treating the student as unenrolled.
 */
const StudentContext = createContext(null);

export function StudentProvider({ children }) {
  const { user } = useAuth();
  const isStudent = user?.role === 'student';

  const activeRef = useRef(readStored());
  const [sections, setSections] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(false);
  const [activeSectionId, setActiveSectionIdState] = useState(activeRef.current);

  const applyActiveId = useCallback((id) => {
    activeRef.current = id;
    setActiveSectionIdState(id);
    if (id !== null && id !== undefined) persist(id);
  }, []);

  const recheck = useCallback(async () => {
    if (!isStudent) {
      setError(false);
      setSections([]);
      setLoading(false);
      return false;
    }
    setLoading(true);
    setError(false);
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
      // Keep the last-known-good sections and active section on failure so
      // an enrolled student is never stranded by a transient network error.
      // `error` lets the gates show a retry screen instead of pretending
      // the student has no sections.
      setError(true);
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
    error,
    activeSectionId,
    setActiveSectionId,
    hasSections: !loading && sections.length > 0,
    recheck,
  }), [sections, loading, error, activeSectionId, setActiveSectionId, recheck]);

  return <StudentContext.Provider value={value}>{children}</StudentContext.Provider>;
}

export function useStudentContext() {
  const ctx = useContext(StudentContext);
  if (!ctx) throw new Error('useStudentContext must be used within a StudentProvider');
  return ctx;
}
