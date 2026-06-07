import { Link } from "react-router-dom";
import { ChevronRight } from "lucide-react";

/**
 * PageBreadcrumb
 * Horizontal breadcrumb trail for non-landing pages.
 *
 * Props
 *   - crumbs: Array<{ label: string, href?: string }>
 *
 * Separator  lucide ChevronRight h-3 w-3 text-muted-foreground
 * Link       text-sm text-muted-foreground hover:text-foreground transition-colors
 * Current    text-sm text-foreground font-medium (not a link)
 *
 * Tokens only.
 */
export default function PageBreadcrumb({ crumbs = [] }) {
  if (!Array.isArray(crumbs) || crumbs.length === 0) {
    return null;
  }

  return (
    <nav aria-label="Breadcrumb">
      <ol className="flex items-center gap-1.5 text-sm">
        {crumbs.map((crumb, i) => {
          const isLast = i === crumbs.length - 1;
          const key = `${crumb.label}-${i}`;
          return (
            <li
              key={key}
              className="flex items-center gap-1.5 min-w-0"
            >
              {isLast ? (
                <span
                  className="text-sm text-foreground font-medium truncate"
                  aria-current="page"
                >
                  {crumb.label}
                </span>
              ) : (
                <Link
                  to={crumb.href || "#"}
                  className="text-sm text-muted-foreground hover:text-foreground transition-colors truncate"
                >
                  {crumb.label}
                </Link>
              )}
              {!isLast ? (
                <ChevronRight
                  className="h-3 w-3 text-muted-foreground shrink-0"
                  aria-hidden="true"
                />
              ) : null}
            </li>
          );
        })}
      </ol>
    </nav>
  );
}
