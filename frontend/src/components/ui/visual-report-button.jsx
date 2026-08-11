import { FileText, Loader2 } from 'lucide-react';
import { Button } from '@/components/ui/button';
import useExport from '@/hooks/useExport';
import { cn } from '@/lib/utils';

/**
 * VisualReportButton
 *
 * Section-scoped download control for the visual report (PDF) endpoint.
 * Downloads the full-class report by default; pass `studentId` to download a
 * single-student dossier. Wires useExport internally and shares its status
 * machine, so the button shows a spinner and disables while a report is in
 * flight.
 *
 * Disabled when `disabled` is set or `sectionId` is missing.
 */
export default function VisualReportButton({
  sectionId,
  studentId,
  label = 'Visual Report (PDF)',
  size = 'sm',
  variant = 'outline',
  className,
  disabled,
}) {
  const { startExport, status } = useExport();
  const loading = status === 'loading';

  return (
    <Button
      variant={variant}
      size={size}
      className={cn('font-medium text-muted-foreground', className)}
      disabled={disabled || !sectionId || loading}
      onClick={() => startExport({ kind: 'visual-report', sectionId, studentId })}
    >
      {loading ? (
        <Loader2 className="h-3.5 w-3.5 mr-1.5 animate-spin" strokeWidth={1.5} />
      ) : (
        <FileText className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
      )}
      {label}
    </Button>
  );
}
