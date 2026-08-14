import { cn } from "@/lib/utils";
import PageBreadcrumb from "@/components/ui/page-breadcrumb";
import MotionContainer from "@/components/ui/motion-container";

/**
 * InstructorDashboardShell
 * Fluid layout wrapper for instructor dashboard sub-pages.
 *
 * Updated for glassmorphic redesign:
 *   - Negative margin cancels Layout padding (no doubling)
 *   - Max width relaxed to max-w-[1400px] for breathing room
 *   - MotionContainer wraps children for staggered page-load animation
 *   - Vertical rhythm uses varied spacing (not uniform space-y-6)
 *
 * Props
 *   - breadcrumb  Array<{ label, href? }>
 *   - subtitle    string
 *   - action      ReactNode
 *   - className   string
 *   - children    ReactNode
 */
export default function InstructorDashboardShell({
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
        "w-full max-w-[1400px] mx-auto",
        "px-6 py-6 md:px-8 md:py-8",
        "space-y-6",
        className
      )}
    >
      {hasHeader ? (
        <header className="space-y-2 mb-6">
          {breadcrumb.length > 0 ? (
            <PageBreadcrumb crumbs={breadcrumb} />
          ) : null}
          {subtitle || action ? (
            <div className="flex flex-col gap-3 sm:flex-row sm:items-end sm:justify-between">
              {subtitle ? (
                <p className="text-sm text-muted-foreground">{subtitle}</p>
              ) : null}
              {action ? (
                <div className="flex flex-wrap items-center gap-2 shrink-0">{action}</div>
              ) : null}
            </div>
          ) : null}
        </header>
      ) : null}
      <MotionContainer stagger={0.05} delay={0.05}>
        {children}
      </MotionContainer>
    </div>
  );
}
