export default function Logo({ size = 32, showText = false, className = '' }) {
  return (
    <div className={`inline-flex items-center gap-2.5 ${className}`}>
      <svg
        width={size}
        height={size}
        viewBox="0 0 100 100"
        fill="none"
        xmlns="http://www.w3.org/2000/svg"
        aria-label="CodeInsight logo"
      >
        {/* Lens — bold circle (analysis / insight) */}
        <circle
          cx="40"
          cy="40"
          r="30"
          stroke="currentColor"
          strokeWidth="7"
        />

        {/* Handle — thick diagonal (makes it unmistakably a magnifying glass) */}
        <line
          x1="62"
          y1="62"
          x2="88"
          y2="88"
          stroke="currentColor"
          strokeWidth="9"
          strokeLinecap="round"
        />

        {/* Code bracket inside the lens */}
        <path
          d="M34 30 L22 42 L34 54"
          stroke="currentColor"
          strokeWidth="5"
          strokeLinecap="round"
          strokeLinejoin="round"
        />

        {/* Insight dot inside the lens */}
        <circle cx="48" cy="42" r="4.5" fill="currentColor" />
      </svg>
      {showText && (
        <span className="font-bold tracking-tight text-foreground">
          Code<span className="text-primary">Insight</span>
        </span>
      )}
    </div>
  );
}
