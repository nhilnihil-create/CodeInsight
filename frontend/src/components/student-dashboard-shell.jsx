import { cn } from "@/lib/utils";
import PageBreadcrumb from "@/components/ui/page-breadcrumb";

/**
 * StudentDashboardShell
 * Unified layout wrapper for every student dashboard sub-page.
 *
 * Contract
 *   - Width         w-full (fills parent content wrapper edge-to-edge)
 *   - Padding       Inherited from Layout wrapper (p-6 lg:p-8)
 *   - Vertical gap  space-y-6
 *   - Header        optional breadcrumb + subtitle + action row
 *
 * No padding or negative margins here — Layout.jsx's content wrapper
 * provides the scroll context and padding rails. The shell is purely
 * a structural container with vertical spacing for its children.
 */
export default function StudentDashboardShell({
  breadcrumb = [],
  subtitle,
  action,
  className,
  children,
}) {
  const hasHeader = breadcrumb.length > 0 || subtitle || action;

  return (
    <div
      className={cn(
        "w-full",
        "px-0 py-0",
        "space-y-6",
        className
      )}
    >
      {hasHeader ? (
        <header className="space-y-2">
          {breadcrumb.length > 0 ? (
            <PageBreadcrumb crumbs={breadcrumb} />
          ) : null}
          {subtitle || action ? (
            <div className="flex flex-col gap-3 sm:flex-row sm:items-end sm:justify-between">
              {subtitle ? (
                <p className="text-sm text-muted-foreground">{subtitle}</p>
              ) : null}
              {action ? (
                <div className="flex items-center gap-2 shrink-0">{action}</div>
              ) : null}
            </div>
          ) : null}
        </header>
      ) : null}
      {children}
    </div>
  );
}
