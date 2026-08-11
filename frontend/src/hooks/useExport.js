import { useCallback, useEffect, useRef, useState } from 'react';
import { toast } from 'sonner';
import { fetchExportBlob, triggerDownload } from '@/services/exportApi';

const RESET_MS = 2000;

/**
 * useExport
 *
 * Orchestrates the canonical export flow for a section-scoped domain:
 * fetch blob → trigger download → success toast → brief "done" state.
 *
 * Returns { startExport, status, error, fileName }.
 * status ∈ 'idle' | 'loading' | 'done' | 'error'.
 *
 * startExport is guarded against missing sectionIds and re-entrancy while a
 * previous export is in flight. After a successful export the status resets
 * to 'idle' after RESET_MS so the triggering control re-enables.
 */
export default function useExport() {
  const [status, setStatus] = useState('idle');
  const [error, setError] = useState(null);
  const [fileName, setFileName] = useState(null);
  const busyRef = useRef(false);
  const resetTimer = useRef(null);

  useEffect(
    () => () => {
      if (resetTimer.current) clearTimeout(resetTimer.current);
    },
    []
  );

  const startExport = useCallback(
    async ({ domain, sectionId, format = 'csv', studentId, fileName: preferredName } = {}) => {
      // eslint-disable-next-line eqeqeq -- intentional nullish guard (null or undefined)
      if (sectionId == null || busyRef.current) return;
      busyRef.current = true;
      setStatus('loading');
      setError(null);
      try {
        const { blob, fileName: serverFileName } = await fetchExportBlob(domain, sectionId, {
          format,
          // eslint-disable-next-line eqeqeq -- intentional nullish guard (null or undefined)
          ...(studentId != null ? { studentId } : {}),
        });
        const finalName = preferredName || serverFileName;
        triggerDownload(blob, finalName);
        toast.success(`Export ready: ${finalName}`);
        setFileName(finalName);
        setStatus('done');
        if (resetTimer.current) clearTimeout(resetTimer.current);
        resetTimer.current = setTimeout(() => {
          busyRef.current = false;
          setStatus('idle');
        }, RESET_MS);
      } catch (err) {
        busyRef.current = false;
        const message = err.response?.data?.error || err.message || 'Export failed';
        setError(message);
        setStatus('error');
        toast.error(message);
      }
    },
    []
  );

  return { startExport, status, error, fileName };
}
