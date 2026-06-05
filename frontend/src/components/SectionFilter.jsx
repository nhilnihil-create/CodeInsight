import { useEffect, useState } from 'react';
import { useAuth } from '../context/AuthContext';
import api from '../services/api';
import {
  Select,
  SelectContent,
  SelectItem,
  SelectTrigger,
  SelectValue,
} from '@/components/ui/select';
import { cn } from '@/lib/utils';

/**
 * SectionFilter
 * Shared "All Sections / per-section" picker for the 8 instructor sidebar
 * pages (Dashboard, Heatmap, Students, Exercises, Warnings, Reports,
 * Violations, Integrity). The Section Management page (My Sections) and the
 * Developer page are excluded per user directive.
 *
 * Props
 *   - value:        currently selected sectionId (number|string) or 'all'.
 *                   'all' is the default initial value.
 *   - onChange:     (next: 'all' | number) => void
 *   - className:    optional wrapper className passthrough
 *   - placeholder:  trigger placeholder when value is empty (default "All Sections")
 *
 * Fetches /api/sections once on mount (cached) and exposes a shadcn
 * Select. The label is humanized from the section's `name` field and
 * `course_code` is appended when present for clarity.
 */
export default function SectionFilter({
  value = 'all',
  onChange,
  className,
  placeholder = 'All Sections',
}) {
  const { user } = useAuth();
  const [sections, setSections] = useState([]);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    let cancelled = false;
    const load = async () => {
      try {
        // Try instructor endpoint first; fall back to generic list.
        let res;
        try {
          res = await api.get('/api/instructor/sections');
        } catch {
          res = await api.get('/api/sections');
        }
        const list = Array.isArray(res.data) ? res.data : [];
        if (!cancelled) {
          setSections(list);
          setLoading(false);
        }
      } catch {
        if (!cancelled) {
          setSections([]);
          setLoading(false);
        }
      }
    };
    load();
    return () => { cancelled = true; };
  }, [user?.id]);

  const triggerValue = value === 'all' || value === null || value === undefined
    ? 'all'
    : String(value);

  return (
    <div className={cn('flex items-center gap-2', className)}>
      <span className="text-xs font-medium uppercase tracking-wider text-muted-foreground">
        Section
      </span>
      <Select
        value={triggerValue}
        onValueChange={(v) => onChange?.(v === 'all' ? 'all' : Number(v))}
        disabled={loading}
      >
        <SelectTrigger className="h-9 min-w-[200px] bg-background text-foreground">
          <SelectValue placeholder={placeholder} />
        </SelectTrigger>
        <SelectContent>
          <SelectItem value="all">All Sections</SelectItem>
          {sections.map((sec) => (
            <SelectItem key={sec.id} value={String(sec.id)}>
              {sec.name}
              {sec.course_code ? ` · ${sec.course_code}` : ''}
            </SelectItem>
          ))}
        </SelectContent>
      </Select>
    </div>
  );
}
