import { Download, ChevronDown, Loader2 } from "lucide-react";
import { Button } from "@/components/ui/button";
import {
  DropdownMenu,
  DropdownMenuContent,
  DropdownMenuItem,
  DropdownMenuTrigger,
} from "@/components/ui/dropdown-menu";
import useExport from "@/hooks/useExport";
import { cn } from "@/lib/utils";

const FORMAT_LABELS = {
  csv: { label: 'CSV', description: 'Spreadsheet-friendly' },
  xlsx: { label: 'Excel (XLSX)', description: 'Formatted workbook' },
  json: { label: 'JSON', description: 'Raw data' },
};

/**
 * ExportDropdown
 *
 * Shared section-scoped export control for the canonical export API. Wires
 * useExport internally and downloads the selected format for a domain.
 *
 * Disabled when `disabled` is set or `sectionId` is missing. While an export
 * is in flight the trigger shows a spinner and the menu items are disabled.
 */
export default function ExportDropdown({
  sectionId,
  domain,
  formats = ["csv", "xlsx", "json"],
  fileName,
  label = "Export",
  align = "end",
  disabled,
  className,
  studentId,
}) {
  const { startExport, status } = useExport();
  const loading = status === "loading";

  return (
    <DropdownMenu>
      <DropdownMenuTrigger asChild>
        <Button
          variant="ghost"
          size="sm"
          className={cn("font-medium text-muted-foreground", className)}
          disabled={disabled || !sectionId}
        >
          {loading ? (
            <Loader2 className="h-3.5 w-3.5 mr-1.5 animate-spin" strokeWidth={1.5} />
          ) : (
            <Download className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
          )}
          {label}
          <ChevronDown className="ml-1 h-3 w-3" strokeWidth={1.5} />
        </Button>
      </DropdownMenuTrigger>
      <DropdownMenuContent align={align}>
        {formats.map((format) => (
          <DropdownMenuItem
            key={format}
            disabled={loading}
            onClick={() => startExport({ domain, sectionId, format, studentId, fileName })}
          >
            <Download className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
            {FORMAT_LABELS[format].label}
            <span className="ml-2 text-xs text-muted-foreground">
              <span aria-hidden="true">— </span>
              {FORMAT_LABELS[format].description}
            </span>
          </DropdownMenuItem>
        ))}
      </DropdownMenuContent>
    </DropdownMenu>
  );
}
