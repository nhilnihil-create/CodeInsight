import { useStudentContext } from '@/context/StudentContext';
import {
  Select,
  SelectContent,
  SelectItem,
  SelectTrigger,
  SelectValue,
} from '@/components/ui/select';
import { cn } from '@/lib/utils';

/**
 * SectionPicker
 * Section switcher for the student — bound to the active section stored in
 * StudentContext. Replaces the static enrolled-section list in the sidebar
 * so students can switch the section that scopes every /api/student/* call.
 *
 * Props
 *   - className:   optional wrapper className passthrough
 *   - placeholder: trigger placeholder when no section is active
 */
export default function SectionPicker({
  className,
  placeholder = 'Select section',
}) {
  const { sections, loading, activeSectionId, setActiveSectionId } = useStudentContext();

  const value = activeSectionId !== null && activeSectionId !== undefined ? String(activeSectionId) : '';

  return (
    <Select
      value={value}
      onValueChange={(v) => setActiveSectionId(Number(v))}
      disabled={loading || sections.length === 0}
    >
      <SelectTrigger
        className={cn(
          'h-8 w-full bg-white/[0.03] border-white/[0.08] text-foreground text-[11px]',
          className
        )}
      >
        <SelectValue placeholder={placeholder} />
      </SelectTrigger>
      <SelectContent>
        {sections.map((sec) => (
          <SelectItem key={sec.id} value={String(sec.id)}>
            {sec.name || sec.course_code || `Section ${sec.id}`}
            {sec.course_code ? ` · ${sec.course_code}` : ''}
          </SelectItem>
        ))}
      </SelectContent>
    </Select>
  );
}
