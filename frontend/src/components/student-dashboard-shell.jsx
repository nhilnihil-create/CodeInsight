import { Link } from "react-router-dom";
import { ArrowLeft } from "lucide-react";
import { cn } from "@/lib/utils";
import PageBreadcrumb from "@/components/ui/page-breadcrumb";
import MotionContainer from "@/components/ui/motion-container";

/**
 * StudentDashboardShell
 * Fluid layout wrapper for student dashboard sub-pages.
 *
 * Updated for glassmorphic redesign:
 *   - MotionContainer wraps children for staggered page-load animation
 *   - Relaxed vertical spacing with varied rhythm
 *   - No padding — Layout.jsx provides scroll context + padding rails
 *
 * Props
 *   - breadcrumb      Array<{ label, href? }>
 *   - subtitle        string
 *   - action          ReactNode
 *   - backToClasses   boolean (default true) — renders an "All classes" link
 *   - className       string
 *   - children        ReactNode
 */
export default function StudentDashboardShell({
  breadcrumb = [],
  subtitle,
  action,
  backToClasses = true,
  className,
  children,
}) {
  const hasHeader = breadcrumb.length > 0 || subtitle || action || backToClasses;

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
        <header className="space-y-2 mb-6">
          {backToClasses ? (
            <Link
              to="/student/select-section"
              className="inline-flex items-center gap-1.5 text-xs text-muted-foreground transition-colors hover:text-primary"
            >
              <ArrowLeft className="h-3.5 w-3.5" strokeWidth={2} />
              All classes
            </Link>
          ) : null}
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
      <MotionContainer stagger={0.05} delay={0.05}>
        {children}
      </MotionContainer>
    </div>
  );
}
