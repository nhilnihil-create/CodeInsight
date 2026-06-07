/**
 * InsightHeader
 * Top-of-page: eyebrow + 1-line insight + 1 PrimaryAction (+ optional secondary).
 *
 * Props
 *   - eyebrow     optional overline text
 *   - insight     required 1-sentence insight (≤120 chars)
 *   - description optional supporting text
 *   - action      optional ReactNode (typically <Button>)
 *   - secondary   optional ReactNode
 *
 * Reference: DESIGN_SYSTEM.md §11.1
 */
export default function InsightHeader({
  eyebrow,
  insight,
  description,
  action,
  secondary,
}) {
  return (
    <section className="flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between rounded-lg border border-border bg-card px-4 py-4 sm:px-5 sm:py-4">
      <div className="min-w-0 flex-1 space-y-1">
        {eyebrow ? (
          <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
            {eyebrow}
          </p>
        ) : null}
        <h2 className="text-lg font-semibold text-foreground">
          {insight}
        </h2>
        {description ? (
          <p className="text-sm text-muted-foreground">{description}</p>
        ) : null}
      </div>
      {(action || secondary) ? (
        <div className="flex items-center gap-2 shrink-0">
          {secondary}
          {action}
        </div>
      ) : null}
    </section>
  );
}
