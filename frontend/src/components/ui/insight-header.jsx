/**
 * InsightHeader
 * Top-of-page banner with glowing accent line.
 *
 * Props
 *   - eyebrow     optional overline text
 *   - insight     required 1-sentence insight (≤120 chars)
 *   - description optional supporting text
 *   - action      optional ReactNode (typically <Button>)
 *   - secondary   optional ReactNode
 *   - tone        accent line + eyebrow color: 'emerald' | 'amber' | 'rose' (default 'emerald')
 */
export default function InsightHeader({
  eyebrow,
  insight,
  description,
  action,
  secondary,
  tone = 'emerald',
}) {
  // Full literal class names so the Tailwind v4 scanner picks them up
  // (never via-${tone} concatenation).
  const via = tone === 'rose' ? 'via-rose-400/60' : tone === 'amber' ? 'via-amber-400/60' : 'via-emerald-400/60';
  // Color utility must live on an INNER span: `.metric-label` is unlayered
  // custom CSS (index.css) and would beat a layered utility on the same element.
  const eyebrowColor = tone === 'rose' ? 'text-rose-400' : tone === 'amber' ? 'text-amber-400' : null;
  return (
    <section className="relative overflow-hidden rounded-2xl border border-white/[0.06] bg-white/[0.02] backdrop-blur-xl">
      {/* Glowing accent line at top */}
      <div className={`absolute top-0 inset-x-0 h-px bg-gradient-to-r from-transparent ${via} to-transparent`} />
      <div className="relative z-10 flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between px-6 py-5">
        <div className="min-w-0 flex-1 space-y-1.5">
          {eyebrow ? (
            <p className="metric-label">
              {eyebrowColor ? <span className={eyebrowColor}>{eyebrow}</span> : eyebrow}
            </p>
          ) : null}
          <h2 className="text-lg font-semibold text-foreground leading-snug">
            {insight}
          </h2>
          {description ? (
            <p className="text-sm text-muted-foreground/60">{description}</p>
          ) : null}
        </div>
        {(action || secondary) ? (
          <div className="relative z-10 flex items-center gap-2 shrink-0">
            {secondary}
            {action}
          </div>
        ) : null}
      </div>
    </section>
  );
}
