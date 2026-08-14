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
 * Section picker for instructor pages. No "All Sections" option —
 * always requires a specific section selection.
 *
 * Props
 *   - value:        currently selected sectionId (number).
 *   - onChange:     (next: number) => void
 *   - className:    optional wrapper className passthrough
 *   - placeholder:  trigger placeholder when value is empty (default "Select section")
 */
export default function SectionFilter({
  value,
  onChange,
  className,
  placeholder = 'Select section',
}) {
  const { user } = useAuth();
  const [sections, setSections] = useState([]);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    let cancelled = false;
    const load = async () => {
      try {
        const res = await api.get('/api/sections');
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

  const triggerValue = value != null ? String(value) : '';

  return (
    <div className={cn('flex items-center gap-2', className)}>
      <span className="text-xs font-medium uppercase tracking-wider text-muted-foreground">
        Section
      </span>
      <Select
        value={triggerValue}
        onValueChange={(v) => onChange?.(Number(v))}
        disabled={loading || sections.length === 0}
      >
        <SelectTrigger className="h-9 w-full sm:w-auto sm:min-w-[200px] bg-background text-foreground">
          <SelectValue placeholder={placeholder} />
        </SelectTrigger>
        <SelectContent>
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
