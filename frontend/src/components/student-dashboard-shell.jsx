import { cn } from "@/lib/utils";
import PageBreadcrumb from "@/components/ui/page-breadcrumb";

/**
 * StudentDashboardShell
 * Unified layout wrapper for every student dashboard sub-page.
 *
 * Contract
 *   - Padding       px-6 py-6 md:px-8 md:py-8
 *   - Width         w-full max-w-7xl mx-auto
 *   - Vertical gap  space-y-6
 *   - Header        optional breadcrumb + subtitle + action row
 *
 * Layout.jsx's content wrapper still applies max-w-7xl mx-auto p-6 lg:p-8
 * to every non-code-editor page. The shell cancels that padding with
 * -m-6 lg:-m-8 so the total visible padding is exactly the shell's
 * own padding (not doubled). Instructor / admin pages that don't use
 * the shell keep the Layout padding as before.
 *
 * Header approach: Option A — keep the breadcrumb (nav context),
 * remove the duplicate h1. The breadcrumb's last item IS the page
 * title, styled as text-sm text-foreground font-medium (see
 * PageBreadcrumb). No h1 in the shell. If a page needs a larger
 * visual header (e.g. Dashboard's dynamic date), it renders its own
 * <header> block inside the shell's children and omits the shell's
 * breadcrumb/header props.
 *
 * Props
 *   - breadcrumb  Array<{ label, href? }>  trail; last item = current page
 *   - subtitle    string                   optional one-line subtitle
 *   - action      ReactNode                optional action button(s)
 *   - className   string                   optional extra classes
 *   - children    ReactNode                page content
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
        "-m-6 lg:-m-8",
        "w-full max-w-7xl mx-auto",
        "px-6 py-6 md:px-8 md:py-8",
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
