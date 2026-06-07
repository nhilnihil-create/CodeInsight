/**
 * EmptyState
 * EATS formula container: Explanation + Action + Time/Status + Symbol.
 *
 * Props
 *   - icon       ReactNode (pre-rendered lucide icon, e.g. <Sparkles />)
 *   - title      string
 *   - description string
 *   - action     ReactNode (typically <Button>)
 *   - footnote   optional string
 *
 * Tokens only.
 */
export default function EmptyState({
  icon,
  title,
  description,
  action,
  footnote,
}) {
  return (
    <div
      role="status"
      className="flex flex-col items-center justify-center text-center py-16 px-6 rounded-xl border border-dashed border-border bg-card/50"
    >
      {icon ? (
        <div className="h-10 w-10 rounded-full bg-muted flex items-center justify-center mb-4 text-muted-foreground">
          {icon}
        </div>
      ) : null}
      {title ? (
        <p className="text-sm font-semibold text-foreground mt-2">{title}</p>
      ) : null}
      {description ? (
        <p className="text-sm text-muted-foreground max-w-xs">{description}</p>
      ) : null}
      {action ? <div className="mt-4">{action}</div> : null}
      {footnote ? (
        <p className="text-xs text-muted-foreground mt-3">{footnote}</p>
      ) : null}
    </div>
  );
}
