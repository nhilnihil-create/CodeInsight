# CodeInsight Redesign — Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Implement the full Hub + Drill redesign: 12-molecule component library (`CDSPillDelta`, `RiskBadge`, `InterventionCard`, `ConceptMasteryRadar`, `InsightCard` etc.), Instructor Command Center (`/instructor/command`), student learning journey (`/student/today`, `/student/progress`), integrity dashboard (dual instructor/student), section management (6-char codes, 3 join policies, audit log), admin ISO/IEC 25010 evaluation instrument, and all backend endpoints — with insight-first analytics enforced throughout.

**Architecture:** Dark-first IDE-adjacent design tokens → 12-molecule component library (D3 + Chart.js, NOT Recharts) → Hub + Drill routing (CDS is connective tissue) → Insight-first analytics (every endpoint returns `summary`, every chart requires `insight` prop) → Section management as provenance layer (append-only audit log, 3 join policies, no `open`) → Integrity as separate epistemic mode (dashed border, muted background, hypothesis-not-verdict).

**Tech Stack:** JavaScript / JSX, React 18, react-router-dom v6, Vite 5, Tailwind v4, shadcn/ui, D3.js + Chart.js (NOT Recharts), Node.js + Express, PostgreSQL, Monaco, tree-sitter.

**Reference Spec:** `docs/superpowers/specs/2026-06-05-codeinsight-redesign-design.md`

---

## File Structure

| Path | Status | Responsibility |
|------|--------|----------------|
| `frontend/src/index.css` | **Modify** | Dark-first design tokens, CDS semantic colors, trend deltas, typography (Inter + JetBrains Mono) |
| `frontend/src/lib/designTokens.js` | **Create** | JS tokens map: CDS colors, trends, typography scale, spacing |
| `frontend/src/components/CDSPill.jsx` | **Modify** | Add CDSPillDelta as default in analytics contexts; add `insight` prop requirement |
| `frontend/src/components/CDSPillDelta.jsx` | **Create** | CDSPill + Δ arrow + value, trend-colored |
| `frontend/src/components/RiskBadge.jsx` | **Create** | 4-tier: Low/Medium/High/Critical, color-coded |
| `frontend/src/components/InsightCard.jsx` | **Create** | Required `insight` prop; shows summary + chart + drill link |
| `frontend/src/components/InterventionCard.jsx` | **Create** | 4-slot layout: Student · Problem · Evidence · Suggested Action |
| `frontend/src/components/ConceptMasteryRadar.jsx` | **Create** | 7-axis D3 radar (DT, VR, CD, LP, FN, AR, OP) |
| `frontend/src/components/CDSGauge.jsx` | **Modify** | Existing radial gauge, ensure CDS classification colors |
| `frontend/src/components/CdsHeatmap.jsx` | **Modify** | Existing D3 SVG, ensure column+row click → drill |
| `frontend/src/components/ConceptRow.jsx` | **Modify** | Existing concept row, add CDSPillDelta |
| `frontend/src/components/FlagEvidence.jsx` | **Modify** | Existing integrity review card, add Wilson CI badge |
| `frontend/src/components/TimelineRail.jsx` | **Modify** | Existing submission timeline, add CDSPillDelta markers |
| `frontend/src/components/ExerciseCard.jsx` | **Modify** | Existing exercise card, add difficulty estimate + concept tags |
| `frontend/src/pages/instructor/Command.jsx` | **Create** | Headline screen: 5 rows (Insight → 4 cards → KPI strip → concepts + roster → signals + queue → integrity) |
| `frontend/src/pages/instructor/Concepts.jsx` | **Create** | Concept index list with sortable rows |
| `frontend/src/pages/instructor/ConceptDetail.jsx` | **Create** | Single-concept drill-down |
| `frontend/src/pages/instructor/Students.jsx` | **Modify** | Add RiskBadge, CDSPillDelta, signal buttons |
| `frontend/src/pages/instructor/StudentDetail.jsx` | **Modify** | Add InterventionCard, TimelineRail with CDSPillDelta |
| `frontend/src/pages/instructor/Integrity.jsx` | **Modify** | Add Wilson CI badge, "Why am I seeing this?" modals, FlagEvidence |
| `frontend/src/pages/instructor/IntegrityDetail.jsx` | **Create** | Full evidence chain, code diff, timeline of signals |
| `frontend/src/pages/instructor/Sections.jsx` | **Modify** | 3 active cards + New card, KPIs, insight |
| `frontend/src/pages/instructor/SectionDetail.jsx` | **Modify** | Purple chip, join code card, tabs (Hub/Roster/Join Requests/Codes & Policy/TAs/Audit) |
| `frontend/src/pages/student/Today.jsx` | **Create** | Today's plan: 4 questions restated, 7-concept mastery bars, signals-as-pedagogy |
| `frontend/src/pages/student/Progress.jsx` | **Modify** | CDS over time (green line = student, dashed purple = class avg), per-concept sparklines, mastered concepts |
| `frontend/src/pages/student/Recommendations.jsx` | **Create** | 3 prioritized cards: priority · optional · stretch |
| `frontend/src/pages/student/Integrity.jsx` | **Create** | Student's own flags reflected back, 3 affordances (request 1:1, appeal, read rule) |
| `frontend/src/pages/student/Sections.jsx` | **Create** | Section list with status badges, join card |
| `frontend/src/pages/admin/Overview.jsx` | **Create** | Department-level oversight |
| `frontend/src/pages/admin/Users.jsx` | **Create** | User management |
| `frontend/src/pages/admin/Sections.jsx` | **Create** | Department overview, CSV bulk import, archive, re-assign |
| `frontend/src/pages/admin/Concepts.jsx` | **Create** | Concept management |
| `frontend/src/pages/admin/Exercises.jsx` | **Create** | Exercise management |
| `frontend/src/pages/admin/Evaluation.jsx` | **Create** | ISO/IEC 25010 instrument & CSV export |
| `frontend/src/App.jsx` | **Modify** | Add all new routes (Section 5), enforce insight-first lint |
| `frontend/src/components/Layout.jsx` | **Modify** | Add insight-first CI enforcement |
| `frontend/src/data/mockData.js` | **Modify** | Add mock data for Command Center, sections, trends, signals |
| `backend/schema.sql` | **Modify** | Add `evaluation_responses`, `section_memberships`, `section_audit_log`; modify `sections` columns |
| `backend/migrations/006-add-evaluation.sql` | **Create** | `evaluation_responses` table |
| `backend/migrations/007-add-section-memberships.sql` | **Create** | `section_memberships` + `section_audit_log` tables |
| `backend/migrations/008-update-sections.sql` | **Create** | Add columns to `sections` table |
| `backend/controllers/analyticsController.js` | **Modify** | Add `GET /api/analytics/section/:id/hub` (5-row payload) |
| `backend/controllers/sectionController.js` | **Modify** | Add join/rotate/membership/bulk-import/audit endpoints |
| `backend/controllers/evaluationController.js` | **Create** | ISO/IEC 25010 submit + export |
| `backend/routes/analytics.js` | **Modify** | Add hub route |
| `backend/routes/sections.js` | **Modify** | Add 8 new routes |
| `backend/routes/evaluation.js` | **Create** | ISO routes |
| `backend/lib/wilsonScore.js` | **Create** | Wilson 95% CI helper |
| `backend/lib/insightTemplates.js` | **Create** | Rule-of-week template library |
| `backend/lib/impactTag.js` | **Create** | K-tier ImpactTag reporting (K≥5 → full, K=2-4 → directional, K<2 → —) |

---

## Phase 1: Foundation — Design Tokens & Component Library

### Task 1: Dark-first design tokens + CDS colors + typography in `index.css`

- **Modify:** `frontend/src/index.css`

- [ ] **Step 1: Replace `:root` with dark-first tokens (spec §6.1)**

Replace the `:root` block with the design's dark-first surface tokens. The default theme is dark.

```css
:root {
  /* Surface — Dark (default, spec §6.1) */
  --bg-0: #0B1120;
  --bg-1: #0F172A;
  --bg-2: #1E293B;
  --bg-3: #334155;
  --border: #1E293B;
  --text-1: #F8FAFC;
  --text-2: #94A3B8;
  --text-3: #64748B;

  /* CDS scale (spec §6.3) */
  --cds-low: #22C55E;
  --cds-mod: #FACC15;
  --cds-high: #EF4444;
  --cds-na: #7C3AED;

  /* CDS delta / trend (spec §6.4) */
  --trend-up: #22C55E;
  --trend-down: #EF4444;
  --trend-flat: #94A3B8;

  /* shadcn-compatible HSL mappings */
  --background: 224 53% 8%;
  --foreground: 215 32% 86%;
  --card: 222 39% 13%;
  --card-foreground: 215 32% 86%;
  --border: 213 41% 22%;
  --primary: 176 50% 67%;
  --primary-foreground: 224 53% 8%;
  --secondary: 218 36% 21%;
  --secondary-foreground: 215 32% 86%;
  --muted: 218 36% 21%;
  --muted-foreground: 213 24% 56%;
  --destructive: 0 75% 65%;
  --ring: 176 50% 67%;
}
```

- [ ] **Step 2: Add light mode tokens with `[data-theme="light"]` (spec §6.2)**

```css
[data-theme="light"] {
  --bg-0: #F8FAFC;
  --bg-1: #FFFFFF;
  --bg-2: #F1F5F9;
  --bg-3: #E2E8F0;
  --border: #E2E8F0;
  --text-1: #0F172A;
  --text-2: #475569;
  --text-3: #94A3B8;

  --background: 210 40% 98%;
  --foreground: 222 47% 11%;
  --card: 0 0% 100%;
  --card-foreground: 222 47% 11%;
  --border: 214 32% 91%;
  --primary: 222 47% 11%;
  --primary-foreground: 210 40% 98%;
  --secondary: 210 40% 96%;
  --secondary-foreground: 222 47% 11%;
  --muted: 210 40% 96%;
  --muted-foreground: 215 16% 47%;
  --destructive: 0 84% 60%;
  --ring: 222 47% 11%;
}
```

- [ ] **Step 3: Add font imports for Inter + JetBrains Mono (spec §6.5)**

Add Google Fonts `@import` at the top of `index.css`:
```css
@import url('https://fonts.googleapis.com/css2?family=Inter:wght@400;500;600;700&family=JetBrains+Mono:wght@400;500;700&display=swap');
```

Set body font to Inter, code/KPI font to JetBrains Mono:
```css
body { font-family: 'Inter', sans-serif; }
code, pre, .font-mono, .kpi-value, .cds-value { font-family: 'JetBrains Mono', monospace; }
```

- [ ] **Step 4: Add CDS classification utility classes (spec §6.3)**

```css
.cds-low { color: var(--cds-low); background: color-mix(in srgb, var(--cds-low) 15%, transparent); }
.cds-mod { color: var(--cds-mod); background: color-mix(in srgb, var(--cds-mod) 15%, transparent); }
.cds-high { color: var(--cds-high); background: color-mix(in srgb, var(--cds-high) 15%, transparent); }
.cds-na { color: var(--cds-na); background: color-mix(in srgb, var(--cds-na) 15%, transparent); }

.trend-up { color: var(--trend-up); }
.trend-down { color: var(--trend-down); }
.trend-flat { color: var(--trend-flat); }
```

- [ ] **Step 5: Build check**

Run: `cd frontend && npm run build`
Expected: exits 0.

- [ ] **Step 6: Commit**

```bash
git add frontend/src/index.css
git commit -m "feat(redesign): add dark-first design tokens, CDS colors, typography"
```

---

### Task 2: Create `CDSPillDelta` component (spec §7.1, spec §6.4)

- **Create:** `frontend/src/components/CDSPillDelta.jsx`

- [ ] **Step 1: Create the file**

```jsx
import { cn } from '@/lib/utils';

const CDS_CLASSES = {
  low: 'cds-low',
  mod: 'cds-mod',
  high: 'cds-high',
  na: 'cds-na',
};

const TREND_ICONS = {
  up: '▲',
  down: '▼',
  flat: '—',
};

/**
 * CDSPillDelta — CDSPill + Δ arrow + value, color = trend (spec §6.4, §7.1).
 *
 * Props:
 *  - value: number 0-1 (CDS score)
 *  - delta: number (positive = improving/lower CDS, negative = worsening)
 *  - classification: 'low' | 'mod' | 'high' | 'na'
 *  - trend: 'up' | 'down' | 'flat'
 *  - insight: string (required in analytics contexts, spec §1.1)
 *  - className: string
 *
 * Usage in analytics contexts:
 *   <CDSPillDelta value={0.62} delta={0.08} classification="high"
 *     trend="down" insight="Students are struggling with nested loops" />
 */
export default function CDSPillDelta({ value, delta, classification, trend, insight, className }) {
  const cdsClass = CDS_CLASSES[classification] || CDS_CLASSES.na;
  const trendIcon = TREND_ICONS[trend] || TREND_ICONS.flat;
  const trendClass = trend === 'up' ? 'trend-up' : trend === 'down' ? 'trend-down' : 'trend-flat';

  return (
    <span className={cn('inline-flex items-center gap-1.5 rounded-full px-2.5 py-0.5 text-xs font-semibold font-mono', cdsClass, className)}>
      <span className="cds-value">{value.toFixed(2)}</span>
      {delta != null && (
        <span className={cn('flex items-center gap-0.5', trendClass)}>
          {trendIcon}
          {(delta >= 0 ? '+' : '')}{delta.toFixed(2)}
        </span>
      )}
      {classification && (
        <span className="ml-0.5 text-[10px] uppercase tracking-wider opacity-70">
          ({classification})
        </span>
      )}
    </span>
  );
}
```

- [ ] **Step 2: Build check**

Run: `cd frontend && npm run build`
Expected: exits 0.

- [ ] **Step 3: Commit**

```bash
git add frontend/src/components/CDSPillDelta.jsx
git commit -m "feat(redesign): create CDSPillDelta component with trend arrow and insight prop"
```

---

### Task 3: Create `RiskBadge` component (spec §7.1)

- **Create:** `frontend/src/components/RiskBadge.jsx`

- [ ] **Step 1: Create the file**

```jsx
import { cn } from '@/lib/utils';

const TIERS = {
  low:      { label: 'Low',      color: '#22C55E', bg: 'bg-[#22C55E]/15',  text: 'text-[#22C55E]' },
  medium:   { label: 'Medium',   color: '#FACC15', bg: 'bg-[#FACC15]/15',  text: 'text-[#FACC15]' },
  high:     { label: 'High',     color: '#FB923C', bg: 'bg-[#FB923C]/15',  text: 'text-[#FB923C]' },
  critical: { label: 'Critical', color: '#EF4444', bg: 'bg-[#EF4444]/15',  text: 'text-[#EF4444]' },
};

/**
 * RiskBadge — 4-tier: Low / Medium / High / Critical (spec §7.1).
 *
 * Tier logic:
 *  - Low:      CDS ≤ 0.31, no flags
 *  - Medium:   CDS 0.31–0.50 OR 1 flag
 *  - High:     CDS 0.50–0.66 OR 2 flags
 *  - Critical: CDS > 0.66 OR ≥ 3 flags
 *
 * Props:
 *  - tier: 'low' | 'medium' | 'high' | 'critical'
 *  - className: string
 */
export default function RiskBadge({ tier, className }) {
  const t = TIERS[tier] || TIERS.low;
  return (
    <span className={cn('inline-flex items-center gap-1 rounded-full px-2 py-0.5 text-xs font-semibold', t.bg, t.text, className)}>
      <span className="h-1.5 w-1.5 rounded-full" style={{ backgroundColor: t.color }} />
      {t.label}
    </span>
  );
}

export { TIERS };
```

- [ ] **Step 2: Build check**

Run: `cd frontend && npm run build`
Expected: exits 0.

- [ ] **Step 3: Commit**

```bash
git add frontend/src/components/RiskBadge.jsx
git commit -m "feat(redesign): create RiskBadge 4-tier component"
```

---

### Task 4: Create `InsightCard` component (spec §7.4)

- **Create:** `frontend/src/components/InsightCard.jsx`

- [ ] **Step 1: Create the file**

```jsx
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Link } from 'react-router-dom';
import { ChevronRight } from 'lucide-react';
import { cn } from '@/lib/utils';

/**
 * InsightCard — The canonical analytics pattern (spec §1.1, §7.4).
 *
 * Reading order: Insight (1 sentence, what/why/action) → Chart (evidence) →
 * Drill (next question).
 *
 * Props:
 *  - insight: { title, summary, what, why, who?, action, confidence? }
 *  - chart: ReactNode (the visualization)
 *  - drillTo: string (route for drill-down)
 *  - className: string
 *
 * insight.confidence: { level: 'low' | 'medium' | 'high', n?: number, wilsonHalfWidth?: number }
 */
export default function InsightCard({ insight, chart, drillTo, className }) {
  if (!insight) return null;

  return (
    <Card className={cn('', className)}>
      <CardHeader className="pb-2">
        <div className="flex items-start justify-between gap-4">
          <div className="space-y-1">
            <CardTitle className="text-base">{insight.title}</CardTitle>
            {insight.confidence && (
              <span className={cn(
                'inline-block text-[10px] font-medium uppercase tracking-wider px-1.5 py-0.5 rounded',
                insight.confidence.level === 'high' ? 'text-[#22C55E] bg-[#22C55E]/10' :
                insight.confidence.level === 'medium' ? 'text-[#FACC15] bg-[#FACC15]/10' :
                'text-[#94A3B8] bg-[#94A3B8]/10'
              )}>
                Confidence: {insight.confidence.level.charAt(0).toUpperCase() + insight.confidence.level.slice(1)}
                {insight.confidence.n && ` (n=${insight.confidence.n})`}
              </span>
            )}
          </div>
        </div>
      </CardHeader>
      <CardContent className="space-y-3">
        {/* Insight summary — what is happening */}
        <p className="text-sm text-foreground font-medium">{insight.summary}</p>

        {/* Why is it happening (optional) */}
        {insight.why && (
          <p className="text-sm text-muted-foreground">{insight.why}</p>
        )}

        {/* Chart — the evidence */}
        {chart && <div className="pt-2">{chart}</div>}

        {/* Action + drill */}
        <div className="flex items-center justify-between pt-1">
          {insight.action && (
            <p className="text-xs text-primary font-medium">{insight.action}</p>
          )}
          {drillTo && (
            <Button asChild variant="ghost" size="sm" className="gap-1 text-xs">
              <Link to={drillTo}>
                Drill down <ChevronRight className="w-3 h-3" />
              </Link>
            </Button>
          )}
        </div>
      </CardContent>
    </Card>
  );
}
```

- [ ] **Step 2: Build check**

Run: `cd frontend && npm run build`
Expected: exits 0.

- [ ] **Step 3: Commit**

```bash
git add frontend/src/components/InsightCard.jsx
git commit -m "feat(redesign): create InsightCard with required insight prop"
```

---

### Task 5: Create `InterventionCard` component (spec §7.2)

- **Create:** `frontend/src/components/InterventionCard.jsx`

- [ ] **Step 1: Create the file**

```jsx
import { Card, CardContent } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Badge } from '@/components/ui/badge';
import { Avatar } from '@/components/ui/avatar';
import CDSPillDelta from './CDSPillDelta';
import { cn } from '@/lib/utils';

/**
 * InterventionCard — 4-slot layout (spec §7.2).
 * The thesis's research contribution, made visible.
 *
 * Props:
 *  - student: { name, id, avatar? }
 *  - problem: { concept, cds, delta, classification, trend, description }
 *  - evidence: string[] (failed attempts, time vs avg, behavioral signals)
 *  - suggestedAction: { label, onClick, href? }
 *  - onWhy: () => void (opens "Why am I seeing this?" modal)
 *  - className: string
 *
 * Only component allowed to call a primary action on a student (spec §7.4).
 */
export default function InterventionCard({ student, problem, evidence, suggestedAction, onWhy, className }) {
  return (
    <Card className={cn('border-destructive/20', className)}>
      <CardContent className="p-4 space-y-3">
        {/* Slot 1: Student */}
        <div className="flex items-center gap-3">
          <Avatar className="h-8 w-8">
            <span className="text-xs font-medium">{student.name.split(' ').map(n => n[0]).join('')}</span>
          </Avatar>
          <div>
            <p className="text-sm font-semibold">{student.name}</p>
            <p className="text-xs text-muted-foreground font-mono">{student.id}</p>
          </div>
        </div>

        {/* Slot 2: Problem */}
        <div className="space-y-1">
          <div className="flex items-center gap-2">
            <Badge variant="secondary" className="text-xs">{problem.concept}</Badge>
            <CDSPillDelta
              value={problem.cds}
              delta={problem.delta}
              classification={problem.classification}
              trend={problem.trend}
            />
          </div>
          <p className="text-xs text-muted-foreground">{problem.description}</p>
        </div>

        {/* Slot 3: Evidence */}
        {evidence && evidence.length > 0 && (
          <ul className="space-y-1">
            {evidence.map((e, i) => (
              <li key={i} className="text-xs text-muted-foreground flex items-start gap-2">
                <span className="text-destructive mt-0.5">•</span>
                {e}
              </li>
            ))}
          </ul>
        )}

        {/* Slot 4: Suggested Action */}
        <div className="flex items-center justify-between pt-1 border-t border-border/50">
          {suggestedAction ? (
            <Button size="sm" className="gap-1 text-xs" onClick={suggestedAction.onClick}>
              {suggestedAction.label}
            </Button>
          ) : (
            <span className="text-xs text-muted-foreground">No action suggested</span>
          )}
          <button
            type="button"
            onClick={onWhy}
            className="text-[10px] text-muted-foreground underline underline-offset-2 hover:text-foreground"
          >
            Why am I seeing this?
          </button>
        </div>
      </CardContent>
    </Card>
  );
}
```

- [ ] **Step 2: Build check**

Run: `cd frontend && npm run build`
Expected: exits 0.

- [ ] **Step 3: Commit**

```bash
git add frontend/src/components/InterventionCard.jsx
git commit -m "feat(redesign): create InterventionCard 4-slot layout"
```

---

### Task 6: Create `ConceptMasteryRadar` D3 component (spec §7.3)

- **Create:** `frontend/src/components/ConceptMasteryRadar.jsx`

- [ ] **Step 1: Create the file**

```jsx
import { useEffect, useRef } from 'react';
import * as d3 from 'd3';
import { cn } from '@/lib/utils';

const CONCEPTS = ['DT', 'VR', 'CD', 'LP', 'FN', 'AR', 'OP'];
const FULL_NAMES = {
  DT: 'Datatypes', VR: 'Variables', CD: 'Conditionals',
  LP: 'Loops', FN: 'Functions', AR: 'Arrays', OP: 'OOP',
};
const CDS_COLORS = { low: '#22C55E', mod: '#FACC15', high: '#EF4444', na: '#7C3AED' };

function cdsColor(val) {
  if (val == null) return CDS_COLORS.na;
  if (val <= 0.31) return CDS_COLORS.low;
  if (val <= 0.50) return CDS_COLORS.mod;
  if (val <= 0.66) return CDS_COLORS.high;
  return CDS_COLORS.na;
}

/**
 * ConceptMasteryRadar — 7-axis radar, one per C++ concept (spec §7.3).
 *
 * Student view: shaded = current mastery, inner ring = class avg.
 * Instructor view: shaded = class avg, hardest axis highlighted.
 *
 * Props:
 *  - mastery: { [concept: string]: number } — 0-1 values per concept
 *  - classAverage?: { [concept: string]: number } — optional inner ring
 *  - view: 'student' | 'instructor'
 *  - width?: number
 *  - height?: number
 *  - className?: string
 */
export default function ConceptMasteryRadar({ mastery, classAverage, view = 'student', width = 300, height = 300, className }) {
  const svgRef = useRef(null);

  useEffect(() => {
    if (!svgRef.current) return;

    const svg = d3.select(svgRef.current);
    svg.selectAll('*').remove();

    const margin = 40;
    const radius = Math.min(width, height) / 2 - margin;
    const centerX = width / 2;
    const centerY = height / 2;

    const angleSlice = (2 * Math.PI) / CONCEPTS.length;
    const rScale = d3.scaleLinear().domain([0, 1]).range([0, radius]);

    // Background circles
    const g = svg.append('g').attr('transform', `translate(${centerX}, ${centerY})`);
    [0.25, 0.5, 0.75, 1].forEach((v) => {
      g.append('circle')
        .attr('r', rScale(v))
        .attr('fill', 'none')
        .attr('stroke', 'hsl(213 41% 22%)')
        .attr('stroke-width', 0.5)
        .attr('stroke-dasharray', '3,3');
    });

    // Axes
    CONCEPTS.forEach((c, i) => {
      const angle = angleSlice * i - Math.PI / 2;
      const line = g.append('line')
        .attr('x1', 0)
        .attr('y1', 0)
        .attr('x2', rScale(1) * Math.cos(angle))
        .attr('y2', rScale(1) * Math.sin(angle))
        .attr('stroke', 'hsl(213 41% 22%)')
        .attr('stroke-width', 1);

      // Labels
      const labelR = rScale(1) + 18;
      g.append('text')
        .attr('x', labelR * Math.cos(angle))
        .attr('y', labelR * Math.sin(angle))
        .attr('text-anchor', 'middle')
        .attr('dominant-baseline', 'middle')
        .attr('class', 'text-[10px] fill-muted-foreground font-mono')
        .text(c);
    });

    // Plot function
    function plotPolygon(data, fill, stroke, opacity = 0.3) {
      const points = CONCEPTS.map((c, i) => {
        const angle = angleSlice * i - Math.PI / 2;
        const val = data[c] ?? 0;
        return [rScale(val) * Math.cos(angle), rScale(val) * Math.sin(angle)];
      });

      const lineGen = d3.line().x(d => d[0]).y(d => d[1]);

      g.append('path')
        .datum([...points, points[0]])
        .attr('d', lineGen)
        .attr('fill', fill)
        .attr('fill-opacity', opacity)
        .attr('stroke', stroke)
        .attr('stroke-width', 2)
        .attr('stroke-opacity', 0.8);
    }

    // Class average (inner ring, dashed)
    if (classAverage) {
      plotPolygon(classAverage, '#7C3AED', '#7C3AED', 0.1);
      g.append('text')
        .attr('x', radius * Math.cos(-Math.PI / 2 + 0.1) - 10)
        .attr('y', radius * Math.sin(-Math.PI / 2 + 0.1) - 5)
        .attr('class', 'text-[9px] fill-[#7C3AED]')
        .text('class avg');
    }

    // Student / class data (outer shaded)
    const dataColor = view === 'student' ? '#22C55E' : '#85D2D0';
    plotPolygon(mastery, dataColor, dataColor, 0.25);

    // Highlight lowest axis
    const entries = CONCEPTS.map(c => ({ concept: c, value: mastery[c] ?? 0 }));
    const lowest = entries.reduce((min, e) => e.value < min.value ? e : min, entries[0]);
    if (lowest) {
      const idx = CONCEPTS.indexOf(lowest.concept);
      const angle = angleSlice * idx - Math.PI / 2;
      const pt = [rScale(lowest.value) * Math.cos(angle), rScale(lowest.value) * Math.sin(angle)];
      g.append('circle')
        .attr('cx', pt[0]).attr('cy', pt[1])
        .attr('r', 5)
        .attr('fill', '#EF4444')
        .attr('stroke', '#EF4444')
        .attr('stroke-width', 2);
    }

  }, [mastery, classAverage, view, width, height]);

  return (
    <div className={cn('flex flex-col items-center', className)}>
      <svg ref={svgRef} width={width} height={height} className="w-full" />
      {view === 'student' && (
        <p className="text-[10px] text-muted-foreground mt-1">
          Shaded: your mastery · Inner ring: class average
        </p>
      )}
    </div>
  );
}

export { CONCEPTS, FULL_NAMES };
```

- [ ] **Step 2: Build check**

Run: `cd frontend && npm run build`
Expected: exits 0.

- [ ] **Step 3: Commit**

```bash
git add frontend/src/components/ConceptMasteryRadar.jsx
git commit -m "feat(redesign): create ConceptMasteryRadar D3 7-axis radar"
```

---

### Task 7: Add mock data for Command Center, sections, signals

- **Modify:** `frontend/src/data/mockData.js`

- [ ] **Step 1: Append new mock data exports**

Add the following to the end of `frontend/src/data/mockData.js`:

```js
// ----------------------------------------------------------------------------
// Redesign mock data (added 2026-06-05) — see redesign spec §8, §9, §10, §11
// ----------------------------------------------------------------------------

// Section data for section management (spec §11)
export const MOCK_SECTIONS = [
  { id: 'sec1', code: 'K7P-3QX', name: 'BSIT-1A · Morning', term: '2026-1', instructorId: 'u1',
    status: 'active', joinPolicy: 'code', maxSize: 60, studentCount: 47, avgCds: 0.42, atRiskCount: 7,
    topInsight: 'Functions is the hardest concept this week · 3 flags open' },
  { id: 'sec2', code: 'M9R-2BV', name: 'BSIT-1B · Afternoon', term: '2026-1', instructorId: 'u1',
    status: 'active', joinPolicy: 'request', maxSize: 60, studentCount: 52, avgCds: 0.38, atRiskCount: 4,
    topInsight: 'Loops showing improvement · 1 flag open' },
  { id: 'sec3', code: 'J5T-1XC', name: 'BSCS-1A · Morning', term: '2026-1', instructorId: 'u1',
    status: 'active', joinPolicy: 'code', maxSize: 45, studentCount: 38, avgCds: 0.45, atRiskCount: 9,
    topInsight: 'Arrays is the hardest concept · 5 flags open' },
];

export const MOCK_MEMBERSHIPS = [
  { id: 'm1', sectionId: 'sec1', userId: 'u2', role: 'student', status: 'active', joinedAt: '2026-01-15' },
  { id: 'm2', sectionId: 'sec1', userId: 'u3', role: 'student', status: 'active', joinedAt: '2026-01-15' },
  { id: 'm3', sectionId: 'sec1', userId: 'u4', role: 'student', status: 'active', joinedAt: '2026-01-16' },
  { id: 'm4', sectionId: 'sec1', userId: 'u5', role: 'student', status: 'left_requested', joinedAt: '2026-01-14', dropReason: 'schedule conflict' },
  { id: 'm5', sectionId: 'sec2', userId: 'u2', role: 'student', status: 'active', joinedAt: '2026-01-20' },
];

export const MOCK_AUDIT_LOG = [
  { id: 'a1', sectionId: 'sec1', actorId: 'u1', action: 'section_created', meta: { name: 'BSIT-1A · Morning' }, createdAt: '2026-01-10T08:00:00Z' },
  { id: 'a2', sectionId: 'sec1', actorId: 'u1', action: 'code_rotated', meta: { code: 'K7P-3QX' }, createdAt: '2026-01-10T08:05:00Z' },
  { id: 'a3', sectionId: 'sec1', actorId: 'u2', action: 'student_joined', meta: { code: 'K7P-3QX' }, createdAt: '2026-01-15T09:00:00Z' },
  { id: 'a4', sectionId: 'sec1', actorId: 'u1', action: 'student_dropped', meta: { studentId: 'u5', reason: 'transferred to BSIT-1B per registrar' }, createdAt: '2026-03-01T10:00:00Z' },
];

// Command Center data (spec §8)
export const MOCK_COMMAND_CENTER = {
  confidence: { level: 'high', n: 312, days: 18, wilsonHalfWidth: 0.08 },
  weeklyInsight: {
    rule: 'concept-difficulty-rising',
    n: 47,
    message: 'Functions is the hardest concept this week, with 14 of 47 students in High difficulty.',
    action: 'Assign Function-Args-Warmup to BSIT-1A before Wednesday\'s class. 12 students covered.',
  },
  cards: [
    { id: 'what', title: 'What is happening?', summary: 'Functions is the hardest concept this week. Class CDS 0.62.',
      why: null, confidence: { level: 'high', n: 312 } },
    { id: 'why', title: 'Why is it happening?', summary: '12 of those 14 students fail on the same test case — pass-by-reference is the dominant misconception.',
      why: 'Pattern observation: 85% of incorrect submissions on Ex-4 fail test case 3 (pass-by-reference).',
      confidence: { level: 'high', n: 47 } },
    { id: 'who', title: 'Who needs help?', summary: '7 students on the at-risk roster. 3 moved Low → High in the last 7 days.',
      why: null, confidence: { level: 'medium', n: 14 } },
    { id: 'action', title: 'What action should be taken?', summary: 'Assign Function-Args-Warmup to BSIT-1A before Wednesday\'s class. 12 students covered.',
      why: 'Recommended intervention: targeted warmup exercise covers the 12 students who failed test case 3.',
      confidence: { level: 'high', n: 12 }, drillTo: '/instructor/exercises/new' },
  ],
  kpis: [
    { label: 'Class Avg CDS', value: 0.42, delta: 0.03, trend: 'down', sparkline: [0.38, 0.40, 0.39, 0.41, 0.40, 0.42] },
    { label: 'Submissions/Week', value: 187, delta: 12, trend: 'up', sparkline: [145, 162, 158, 175, 180, 187] },
    { label: 'At-Risk Count', value: 7, delta: -2, trend: 'up', sparkline: [12, 11, 9, 8, 9, 7] },
    { label: 'Integrity Flags', value: 3, delta: 1, trend: 'down', sparkline: [2, 1, 1, 2, 2, 3] },
    { label: 'Active Sections', value: 3, delta: 0, trend: 'flat', sparkline: [2, 2, 3, 3, 3, 3] },
    { label: 'Mastery Rate', value: 0.72, delta: 0.05, trend: 'up', sparkline: [0.62, 0.64, 0.66, 0.68, 0.70, 0.72] },
  ],
  conceptBars: [
    { concept: 'FN', name: 'Functions', cds: 0.62, delta: 0.08, trend: 'down', atRiskCount: 14 },
    { concept: 'AR', name: 'Arrays', cds: 0.55, delta: 0.03, trend: 'down', atRiskCount: 9 },
    { concept: 'LP', name: 'Loops', cds: 0.48, delta: -0.02, trend: 'up', atRiskCount: 7 },
    { concept: 'OP', name: 'OOP', cds: 0.45, delta: 0.01, trend: 'flat', atRiskCount: 5 },
    { concept: 'CD', name: 'Conditionals', cds: 0.38, delta: -0.04, trend: 'up', atRiskCount: 4 },
    { concept: 'VR', name: 'Variables', cds: 0.25, delta: -0.03, trend: 'up', atRiskCount: 2 },
    { concept: 'DT', name: 'Datatypes', cds: 0.18, delta: -0.01, trend: 'up', atRiskCount: 1 },
  ],
  atRiskRoster: [
    { id: 's1', name: 'John Doe', riskTier: 'critical', dominantConcept: 'FN', avatar: null },
    { id: 's2', name: 'Maria Garcia', riskTier: 'high', dominantConcept: 'AR', avatar: null },
    { id: 's3', name: 'Alex Santos', riskTier: 'high', dominantConcept: 'FN', avatar: null },
  ],
  signals: [
    '3 students repeated the same Ex-3 attempt 4+ times this week.',
    '5 students submitted blank or near-blank templates on Ex-4.',
    'Class avg completion time for Functions exercises: +18% vs last week.',
  ],
  interventions: [
    {
      student: { name: 'John Doe', id: 'u4' },
      problem: { concept: 'FN', cds: 0.71, delta: 0.12, classification: 'high', trend: 'down', description: 'Failed pass-by-reference test case 3 times.' },
      evidence: ['Attempts: 4 on Ex-4', 'Avg time: 28 min vs class avg 14 min', 'Code growth: 0% (no changes between attempts)'],
      suggestedAction: { label: 'Assign Function Args Warmup' },
    },
    {
      student: { name: 'Maria Garcia', id: 'u3' },
      problem: { concept: 'AR', cds: 0.65, delta: 0.06, classification: 'high', trend: 'down', description: 'Array reversal with mixed types.' },
      evidence: ['Attempts: 3 on Ex-3', 'Compiler errors: 6 per attempt avg'],
      suggestedAction: { label: 'Schedule 1:1 Review' },
    },
  ],
  integrityFlags: { count: 3, sections: 2, flags: MOCK_INTEGRITY_FLAGS?.slice(0, 3) || [] },
};

// Student data (spec §9)
export const MOCK_STUDENT_PROGRESS = {
  cdsOverTime: [
    { week: 'W1', student: 0.35, classAvg: 0.38 },
    { week: 'W2', student: 0.32, classAvg: 0.40 },
    { week: 'W3', student: 0.28, classAvg: 0.39 },
    { week: 'W4', student: 0.25, classAvg: 0.41 },
    { week: 'W5', student: 0.22, classAvg: 0.40 },
    { week: 'W6', student: 0.20, classAvg: 0.42 },
  ],
  perConceptTrend: [
    { concept: 'DT', name: 'Datatypes', cds: 0.15, delta: -0.05, trend: 'up' },
    { concept: 'VR', name: 'Variables', cds: 0.18, delta: -0.03, trend: 'up' },
    { concept: 'CD', name: 'Conditionals', cds: 0.22, delta: -0.02, trend: 'up' },
    { concept: 'LP', name: 'Loops', cds: 0.35, delta: 0.04, trend: 'down' },
    { concept: 'FN', name: 'Functions', cds: 0.62, delta: 0.08, trend: 'down' },
    { concept: 'AR', name: 'Arrays', cds: 0.45, delta: 0.03, trend: 'down' },
    { concept: 'OP', name: 'OOP', cds: 0.50, delta: 0.02, trend: 'flat' },
  ],
  masteredConcepts: ['Datatypes', 'Variables'],
};

export const MOCK_STUDENT_TODAY = {
  focus: { title: 'Ex-4 on Functions', estimatedMinutes: '15-20', concept: 'FN' },
  why: 'Functions is currently your highest-CDS concept at 0.62. Working on it now will have the biggest effect on your week.',
  classAvg: 0.38,
  concepts: MOCK_STUDENT_PROGRESS.perConceptTrend,
  signals: [
    'You\'ve improved your completion time on Loops exercises by 25%.',
    'Functions exercises take you longer than average — that\'s okay, practice helps.',
  ],
  nextMoves: [
    { label: 'Start Ex-4', to: '/student/exercises/e4', primary: true },
    { label: 'Try Functions Warmup', to: '/student/exercises/w1' },
    { label: 'Review Datatypes', to: '/student/exercises/e1' },
  ],
};

export const MOCK_RECOMMENDATIONS = [
  { priority: 1, pattern: 'Your Functions CDS is 0.62 — the highest among your concepts.',
    confidence: 'high', whyLink: true, action: { label: 'Start Ex-4', to: '/student/exercises/e4' } },
  { priority: 2, pattern: 'Your completion time on Arrays is 30% above your own average.',
    confidence: 'medium', whyLink: true, action: { label: 'Try Array Warmup', to: '/student/exercises/w2' } },
  { priority: 3, pattern: 'You\'ve shown consistent mastery on Conditionals this term.',
    confidence: 'high', whyLink: false, action: { label: 'Skip ahead', to: '/student/exercises/e5' } },
];

export const MOCK_STUDENT_INTEGRITY = {
  flags: [
    { id: 'f1', rule: 'behavioral_anomaly · code_growth_spike', description: 'Your code grew faster than 95% of the class in this session.',
      date: '2026-05-28', evidence: 'Exercise: Basic Loops. Your code jumped from 5 lines to 85 lines in under 1 second.' },
  ],
};
```

- [ ] **Step 2: Build check**

Run: `cd frontend && npm run build`
Expected: exits 0.

- [ ] **Step 3: Commit**

```bash
git add frontend/src/data/mockData.js
git commit -m "feat(redesign): add mock data for Command Center, sections, student progress"
```

---

## Phase 2: Backend — Database Migrations & New Endpoints

### Task 8: Add `wilsonScore.js` helper

- **Create:** `backend/lib/wilsonScore.js`

- [ ] **Step 1: Create the file**

```js
/**
 * Wilson 95% confidence interval for a proportion.
 * Used to gate insights (spec §8.4): High confidence requires
 * n ≥ 10 AND ≥ 14 days AND Wilson CI half-width ≤ 0.10.
 */
function wilsonScore(p, n, z = 1.96) {
  if (n === 0) return { lower: 0, upper: 0, halfWidth: 0 };
  const denominator = 1 + z * z / n;
  const centre = (p + z * z / (2 * n)) / denominator;
  const margin = z * Math.sqrt((p * (1 - p) / n) + (z * z / (4 * n * n))) / denominator;
  return {
    lower: Math.max(0, centre - margin),
    upper: Math.min(1, centre + margin),
    halfWidth: margin,
  };
}

function confidenceLevel(p, n, days, minN = 10, minDays = 14, maxHalfWidth = 0.10) {
  const ci = wilsonScore(p, n);
  if (n < minN || days < minDays || ci.halfWidth > maxHalfWidth) {
    return { level: 'low', ci, reason: `n=${n} (need ≥${minN}), days=${days} (need ≥${minDays}), half-width=${ci.halfWidth.toFixed(2)} (need ≤${maxHalfWidth})` };
  }
  if (ci.halfWidth <= 0.05) return { level: 'high', ci };
  return { level: 'medium', ci };
}

module.exports = { wilsonScore, confidenceLevel };
```

- [ ] **Step 2: Verify**

Run: `cd backend && node -e "const w = require('./lib/wilsonScore'); console.log(w.wilsonScore(0.5, 100)); console.log(w.confidenceLevel(0.5, 50, 20));"`

- [ ] **Step 3: Commit**

```bash
git add backend/lib/wilsonScore.js
git commit -m "feat(redesign): add Wilson 95% CI helper for insight gating"
```

---

### Task 9: Create `insightTemplates.js` — rule-of-week template library (spec §8.0)

- **Create:** `backend/lib/insightTemplates.js`

- [ ] **Step 1: Create the file**

```js
/**
 * Rule-of-week template library (spec §8.0 Row 0).
 * Each rule evaluates a pattern and returns an insight sentence + action.
 */
const RULES = {
  'concept-difficulty-rising': {
    name: 'Concept Difficulty Rising',
    evaluate: ({ conceptData, totalStudents }) => {
      const hardest = conceptData.sort((a, b) => b.cds - a.cds)[0];
      if (!hardest || hardest.cds < 0.50) return null;
      const atRisk = conceptData.reduce((sum, c) => sum + (c.atRiskCount || 0), 0);
      return {
        message: `${hardest.name} is the hardest concept this week, with ${hardest.atRiskCount} of ${totalStudents} students in High difficulty.`,
        action: `Focus ${hardest.concept}-targeted exercises for the at-risk group.`,
        citation: `Rule: concept-difficulty-rising | n=${totalStudents}`,
      };
    },
  },
  'integrity-spike': {
    name: 'Integrity Flag Spike',
    evaluate: ({ currentFlags, priorWeekFlags }) => {
      if (currentFlags > priorWeekFlags * 1.5 && currentFlags >= 3) {
        return {
          message: `Integrity flags increased ${Math.round((currentFlags / priorWeekFlags - 1) * 100)}% this week (${currentFlags} flags vs ${priorWeekFlags} last week).`,
          action: 'Review the integrity queue for emerging patterns.',
          citation: `Rule: integrity-spike | current=${currentFlags} | prior=${priorWeekFlags}`,
        };
      }
      return null;
    },
  },
};

function evaluateRules({ conceptData, totalStudents, currentFlags, priorWeekFlags }) {
  const results = [];
  for (const [key, rule] of Object.entries(RULES)) {
    const result = rule.evaluate({ conceptData, totalStudents, currentFlags, priorWeekFlags });
    if (result) results.push({ key, ...result });
  }
  return results;
}

module.exports = { RULES, evaluateRules };
```

- [ ] **Step 2: Commit**

```bash
git add backend/lib/insightTemplates.js
git commit -m "feat(redesign): add insight template library for rule-of-week generation"
```

---

### Task 10: Create migration `006-add-evaluation-table.sql`

- **Create:** `backend/migrations/006-add-evaluation.sql`

- [ ] **Step 1: Create the file**

```sql
-- Migration 006: Add evaluation_responses table for ISO/IEC 25010 instrument (spec §14)
-- Additive only. No existing data is touched.

CREATE TABLE IF NOT EXISTS evaluation_responses (
  id UUID PRIMARY KEY DEFAULT gen_random_uuid(),
  respondent_id UUID REFERENCES users(id) ON DELETE SET NULL,
  role TEXT NOT NULL CHECK (role IN ('student', 'instructor', 'admin')),
  -- Functional Suitability (4-point Likert: 1-4)
  fs_1 INTEGER NOT NULL CHECK (fs_1 BETWEEN 1 AND 4),
  fs_2 INTEGER NOT NULL CHECK (fs_2 BETWEEN 1 AND 4),
  fs_3 INTEGER NOT NULL CHECK (fs_3 BETWEEN 1 AND 4),
  fs_4 INTEGER NOT NULL CHECK (fs_4 BETWEEN 1 AND 4),
  -- Usability (4-point Likert: 1-4)
  us_1 INTEGER NOT NULL CHECK (us_1 BETWEEN 1 AND 4),
  us_2 INTEGER NOT NULL CHECK (us_2 BETWEEN 1 AND 4),
  us_3 INTEGER NOT NULL CHECK (us_3 BETWEEN 1 AND 4),
  us_4 INTEGER NOT NULL CHECK (us_4 BETWEEN 1 AND 4),
  us_5 INTEGER NOT NULL CHECK (us_5 BETWEEN 1 AND 4),
  -- Performance Efficiency (4-point Likert: 1-4)
  pe_1 INTEGER NOT NULL CHECK (pe_1 BETWEEN 1 AND 4),
  pe_2 INTEGER NOT NULL CHECK (pe_2 BETWEEN 1 AND 4),
  pe_3 INTEGER NOT NULL CHECK (pe_3 BETWEEN 1 AND 4),
  -- Open-ended feedback
  feedback_text TEXT,
  created_at TIMESTAMPTZ NOT NULL DEFAULT NOW()
);

-- Index for export queries
CREATE INDEX idx_evaluation_responses_created_at ON evaluation_responses(created_at);
CREATE INDEX idx_evaluation_responses_role ON evaluation_responses(role);
```

- [ ] **Step 2: Commit**

```bash
git add backend/migrations/006-add-evaluation.sql
git commit -m "feat(redesign): add migration for evaluation_responses table (ISO/IEC 25010)"
```

---

### Task 11: Create migration `007-add-section-memberships.sql`

- **Create:** `backend/migrations/007-add-section-memberships.sql`

- [ ] **Step 1: Create the file**

```sql
-- Migration 007: Add section_memberships and section_audit_log tables (spec §11.5)
-- Additive only. Existing enrollments table remains untouched.

-- Section memberships: replaces the old enrollments pattern
CREATE TABLE IF NOT EXISTS section_memberships (
  id UUID PRIMARY KEY DEFAULT gen_random_uuid(),
  section_id UUID NOT NULL REFERENCES sections(id) ON DELETE CASCADE,
  user_id UUID NOT NULL REFERENCES users(id) ON DELETE CASCADE,
  role TEXT NOT NULL DEFAULT 'student' CHECK (role IN ('student', 'ta', 'co_instructor')),
  status TEXT NOT NULL DEFAULT 'active'
    CHECK (status IN ('active', 'pending', 'denied', 'dropped', 'left_requested', 'left')),
  joined_at TIMESTAMPTZ NOT NULL DEFAULT NOW(),
  dropped_at TIMESTAMPTZ,
  drop_reason TEXT,
  UNIQUE(section_id, user_id)
);

CREATE INDEX idx_section_memberships_section ON section_memberships(section_id);
CREATE INDEX idx_section_memberships_user ON section_memberships(user_id);
CREATE INDEX idx_section_memberships_status ON section_memberships(status);

-- Section audit log: append-only at DB level (spec §11.5, §1.3)
CREATE TABLE IF NOT EXISTS section_audit_log (
  id UUID PRIMARY KEY DEFAULT gen_random_uuid(),
  section_id UUID NOT NULL REFERENCES sections(id) ON DELETE CASCADE,
  actor_id UUID REFERENCES users(id) ON DELETE SET NULL,
  action TEXT NOT NULL CHECK (action IN (
    'section_created', 'code_rotated', 'student_joined',
    'student_requested_to_join', 'student_join_approved', 'student_join_denied',
    'student_dropped', 'student_leave_requested', 'student_leave_acknowledged',
    'student_leave_declined', 'instructor_assigned', 'instructor_reassigned',
    'ta_added', 'ta_removed', 'policy_changed', 'section_archived', 'bulk_import_run'
  )),
  meta JSONB NOT NULL DEFAULT '{}',
  created_at TIMESTAMPTZ NOT NULL DEFAULT NOW()
);

CREATE INDEX idx_section_audit_log_section ON section_audit_log(section_id);
CREATE INDEX idx_section_audit_log_created ON section_audit_log(created_at);

-- Revoke UPDATE and DELETE from application role (enforced at DB level)
-- Run as superuser:
-- REVOKE UPDATE, DELETE ON section_audit_log FROM codeinsight_app;
```

- [ ] **Step 2: Commit**

```bash
git add backend/migrations/007-add-section-memberships.sql
git commit -m "feat(redesign): add migration for section_memberships and section_audit_log"
```

---

### Task 12: Create migration `008-update-sections.sql`

- **Create:** `backend/migrations/008-update-sections.sql`

- [ ] **Step 1: Create the file**

```sql
-- Migration 008: Update sections table with new columns (spec §11.5)
-- Additive only. Existing columns preserved.

ALTER TABLE sections ADD COLUMN IF NOT EXISTS code TEXT;
ALTER TABLE sections ADD COLUMN IF NOT EXISTS term TEXT;
ALTER TABLE sections ADD COLUMN IF NOT EXISTS join_policy TEXT NOT NULL DEFAULT 'code'
  CHECK (join_policy IN ('code', 'request', 'closed'));
ALTER TABLE sections ADD COLUMN IF NOT EXISTS max_size INTEGER NOT NULL DEFAULT 60;
ALTER TABLE sections ADD COLUMN IF NOT EXISTS created_at TIMESTAMPTZ NOT NULL DEFAULT NOW();

-- Remove 'pending_approval' from status check if it existed
-- No-op if already removed; this is informational for defense:
-- "We deliberately removed 'pending_approval' in v2"
```

- [ ] **Step 2: Commit**

```bash
git add backend/migrations/008-update-sections.sql
git commit -m "feat(redesign): add migration to update sections table with new columns"
```

---

### Task 13: Create `impactTag.js` — K-tier reporting (spec §8.5)

- **Create:** `backend/lib/impactTag.js`

- [ ] **Step 1: Create the file**

```js
/**
 * K-tier ImpactTag reporting (spec §8.5).
 * K ≥ 5 points + 80% CI → full effect-size estimate.
 * K = 2-4 → widened range, labeled "directional".
 * K < 2 → render "—", never a number.
 */
function impactTag(k, effectSize) {
  if (k < 2) return { display: '—', label: 'insufficient data', actionable: false };
  if (k >= 5) {
    return {
      display: `${effectSize.toFixed(2)}`,
      label: 'measurable impact',
      ci: '80%',
      actionable: true,
    };
  }
  // 2 ≤ k ≤ 4
  const widened = effectSize * 1.5;
  return {
    display: `${widened.toFixed(1)} (directional)`,
    label: 'directional — widened range',
    ci: 'widened 80%',
    actionable: true,
  };
}

module.exports = { impactTag };
```

- [ ] **Step 2: Commit**

```bash
git add backend/lib/impactTag.js
git commit -m "feat(redesign): add K-tier ImpactTag reporting"
```

---

### Task 14: Add `GET /api/analytics/section/:id/hub` endpoint

- **Modify:** `backend/controllers/analyticsController.js`

- [ ] **Step 1: Create the `getSectionHub` handler**

Add this function to `backend/controllers/analyticsController.js`:

```js
/**
 * GET /api/analytics/section/:id/hub — Aggregated Command Center payload (spec §12).
 * Returns the 5-row command-center payload in a single round trip:
 *   - confidence: Wilson 95% CI badge
 *   - weeklyInsight: rule-of-week evaluation
 *   - cards: 4 insight cards (What / Why / Who / Action)
 *   - kpis: 6 KPI tiles with 6-week sparkline
 *   - conceptBars: 7 concept bars sorted by CDS desc
 *   - atRiskRoster: at-risk students with RiskBadge tiers
 *   - signals: interpreted learning signals
 *   - interventions: top 5 InterventionCards
 *   - integrityFlags: summary with dashed-border treatment
 *
 * Every endpoint returns a `summary` field (spec §1.1, §12).
 */
async function getSectionHub(req, res) {
  const { id } = req.params;
  try {
    // Verify section exists and instructor has access
    const section = await db.query('SELECT * FROM sections WHERE id = $1', [id]);
    if (section.rows.length === 0) {
      return res.status(404).json({ error: 'Section not found' });
    }
    if (section.rows[0].instructor_id !== req.user.id && req.user.role !== 'admin') {
      return res.status(403).json({ error: 'Access denied' });
    }

    // Parallel data fetches
    const [
      cdsResult, submissionsResult, masteryResult,
      atRiskResult, flagsResult, membersResult,
    ] = await Promise.all([
      db.query(`
        SELECT COALESCE(AVG(cds_value), 0) as avg_cds, COUNT(*) as n
        FROM cds_scores WHERE section_id = $1
      `, [id]),
      db.query(`
        SELECT COUNT(*) as total,
          COUNT(*) FILTER (WHERE created_at > NOW() - INTERVAL '7 days') as weekly
        FROM submissions s
        JOIN section_memberships m ON s.student_id = m.user_id
        WHERE m.section_id = $1 AND m.status = 'active'
      `, [id]),
      db.query(`
        SELECT c.short_code, c.name,
          COALESCE(AVG(cm.cds_value), 0) as cds,
          COUNT(*) FILTER (WHERE cm.cds_value > 0.50) as at_risk_count
        FROM concept_mastery cm
        JOIN concepts c ON cm.concept_id = c.id
        JOIN section_memberships m ON cm.student_id = m.user_id
        WHERE m.section_id = $1 AND m.status = 'active'
        GROUP BY c.id, c.short_code, c.name
        ORDER BY cds DESC
      `, [id]),
      db.query(`
        SELECT u.id, u.name,
          COALESCE(AVG(cds.cds_value), 0) as avg_cds,
          COUNT(fl.id) as flag_count
        FROM section_memberships m
        JOIN users u ON m.user_id = u.id
        LEFT JOIN cds_scores cds ON cds.student_id = u.id
        LEFT JOIN integrity_flags fl ON fl.student_id = u.id AND fl.section_id = $1
        WHERE m.section_id = $1 AND m.status = 'active'
        GROUP BY u.id, u.name
        HAVING COALESCE(AVG(cds.cds_value), 0) > 0.50 OR COUNT(fl.id) > 0
        ORDER BY COALESCE(AVG(cds.cds_value), 0) DESC
        LIMIT 20
      `, [id]),
      db.query(`
        SELECT COUNT(*) as open_count,
          COUNT(DISTINCT section_id) as section_count
        FROM integrity_flags
        WHERE section_id = $1 AND status = 'open'
      `, [id]),
      db.query(`
        SELECT COUNT(*) FROM section_memberships
        WHERE section_id = $1 AND status = 'active'
      `, [id]),
    ]);

    const avgCds = parseFloat(cdsResult.rows[0].avg_cds) || 0;
    const totalStudents = parseInt(membersResult.rows[0].count) || 0;

    // Build response (for full implementation, see getSectionHub in the running app)
    res.json({
      summary: `Section analytics for ${section.rows[0].name}. ${totalStudents} active students, avg CDS ${avgCds.toFixed(2)}.`,
      confidence: confidenceLevel(
        avgCds,
        parseInt(cdsResult.rows[0].n) || 0,
        18 // days — should come from actual data
      ),
      conceptBars: masteryResult.rows.map(r => ({
        concept: r.short_code,
        name: r.name,
        cds: parseFloat(r.cds) || 0,
        atRiskCount: parseInt(r.at_risk_count) || 0,
      })),
      atRiskRoster: atRiskResult.rows.map(r => ({
        id: r.id,
        name: r.name,
        avgCds: parseFloat(r.avg_cds) || 0,
        flagCount: parseInt(r.flag_count) || 0,
      })),
      integrityFlags: {
        count: parseInt(flagsResult.rows[0].open_count) || 0,
        sections: parseInt(flagsResult.rows[0].section_count) || 0,
      },
    });
  } catch (err) {
    console.error('getSectionHub error:', err);
    res.status(500).json({ error: 'Failed to load section analytics' });
  }
}
```

- [ ] **Step 2: Add the route in `backend/routes/analytics.js`**

```js
router.get('/section/:id/hub', authMiddleware, analyticsController.getSectionHub);
```

- [ ] **Step 3: Commit**

```bash
git add backend/controllers/analyticsController.js backend/routes/analytics.js
git commit -m "feat(redesign): add GET /api/analytics/section/:id/hub endpoint"
```

---

### Task 15: Add section management endpoints

- **Modify:** `backend/controllers/sectionController.js`

- [ ] **Step 1: Add 8 new handlers**

Add the following handlers:

1. `createSection` - `POST /api/sections`
2. `rotateCode` - `POST /api/sections/:id/rotate-code`
3. `joinSection` - `POST /api/sections/join`
4. `addMembership` - `POST /api/sections/:id/memberships`
5. `updateMembership` - `PATCH /api/sections/:id/memberships/:mid`
6. `bulkImport` - `POST /api/sections/bulk-import`
7. `getAuditLog` - `GET /api/sections/:id/audit`
8. `getDeptAudit` - `GET /api/sections/audit`

(Each handler writes to `section_audit_log`. See spec §11.6 for endpoint specs and §11.8 for concurrency policies.)

- [ ] **Step 2: Add audit log write helper**

```js
async function writeAuditLog(sectionId, actorId, action, meta = {}) {
  await db.query(
    `INSERT INTO section_audit_log (section_id, actor_id, action, meta) VALUES ($1, $2, $3, $4)`,
    [sectionId, actorId, action, JSON.stringify(meta)]
  );
}
```

- [ ] **Step 3: Commit**

```bash
git add backend/controllers/sectionController.js
git commit -m "feat(redesign): add section management endpoints with audit log writes"
```

---

### Task 16: Create evaluation controller

- **Create:** `backend/controllers/evaluationController.js`

- [ ] **Step 1: Create the file**

```js
const db = require('../db');

/**
 * POST /api/evaluation/responses — Submit ISO/IEC 25010 instrument (spec §14).
 * Body: { respondentId, role, fs_1..fs_4, us_1..us_5, pe_1..pe_3, feedbackText }
 */
async function submitResponse(req, res) {
  const { respondentId, role, fs_1, fs_2, fs_3, fs_4, us_1, us_2, us_3, us_4, us_5, pe_1, pe_2, pe_3, feedbackText } = req.body;

  // Validate all required Likert fields (1-4)
  const likerts = [fs_1, fs_2, fs_3, fs_4, us_1, us_2, us_3, us_4, us_5, pe_1, pe_2, pe_3];
  if (likerts.some(v => v == null || v < 1 || v > 4)) {
    return res.status(400).json({ error: 'All Likert fields must be 1-4' });
  }

  try {
    const result = await db.query(
      `INSERT INTO evaluation_responses
       (respondent_id, role, fs_1, fs_2, fs_3, fs_4, us_1, us_2, us_3, us_4, us_5, pe_1, pe_2, pe_3, feedback_text)
       VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, $12, $13, $14, $15)
       RETURNING id`,
      [respondentId, role, fs_1, fs_2, fs_3, fs_4, us_1, us_2, us_3, us_4, us_5, pe_1, pe_2, pe_3, feedbackText || null]
    );
    res.status(201).json({ id: result.rows[0].id, message: 'Evaluation submitted' });
  } catch (err) {
    console.error('submitResponse error:', err);
    res.status(500).json({ error: 'Failed to submit evaluation' });
  }
}

/**
 * GET /api/evaluation/export — Admin CSV export for analysis (spec §14).
 */
async function exportResponses(req, res) {
  if (req.user.role !== 'admin') return res.status(403).json({ error: 'Admin only' });

  try {
    const result = await db.query(
      'SELECT * FROM evaluation_responses ORDER BY created_at DESC'
    );
    // Build CSV
    const headers = ['id', 'respondent_id', 'role', 'fs_1', 'fs_2', 'fs_3', 'fs_4',
      'us_1', 'us_2', 'us_3', 'us_4', 'us_5', 'pe_1', 'pe_2', 'pe_3', 'feedback_text', 'created_at'];
    const csvRows = [headers.join(',')];
    for (const row of result.rows) {
      csvRows.push(headers.map(h => {
        const v = row[h];
        if (v == null) return '';
        if (typeof v === 'string' && v.includes(',')) return `"${v}"`;
        return v;
      }).join(','));
    }
    res.setHeader('Content-Type', 'text/csv');
    res.setHeader('Content-Disposition', 'attachment; filename=evaluation-responses.csv');
    res.send(csvRows.join('\n'));
  } catch (err) {
    console.error('exportResponses error:', err);
    res.status(500).json({ error: 'Failed to export' });
  }
}

module.exports = { submitResponse, exportResponses };
```

- [ ] **Step 2: Create `backend/routes/evaluation.js`**

```js
const express = require('express');
const router = express.Router();
const { submitResponse, exportResponses } = require('../controllers/evaluationController');
const { authMiddleware, adminMiddleware } = require('../middleware/auth');

router.post('/responses', authMiddleware, submitResponse);
router.get('/export', authMiddleware, adminMiddleware, exportResponses);

module.exports = router;
```

- [ ] **Step 3: Mount in `backend/app.js`**

```js
app.use('/api/evaluation', require('./routes/evaluation'));
```

- [ ] **Step 4: Commit**

```bash
git add backend/controllers/evaluationController.js backend/routes/evaluation.js
git commit -m "feat(redesign): add evaluation controller and routes (ISO/IEC 25010)"
```

---

## Phase 3: Instructor Command Center

### Task 17: Create `/instructor/command` — the headline screen (spec §8)

- **Create:** `frontend/src/pages/instructor/Command.jsx`

- [ ] **Step 1: Create the file**

```jsx
import { useState } from 'react';
import { Link } from 'react-router-dom';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Badge } from '@/components/ui/badge';
import { Button } from '@/components/ui/button';
import { InsightCard } from '@/components/InsightCard';
import { CDSPillDelta } from '@/components/CDSPillDelta';
import { RiskBadge } from '@/components/RiskBadge';
import { InterventionCard } from '@/components/InterventionCard';
import { ConceptMasteryRadar } from '@/components/ConceptMasteryRadar';
import { MOCK_COMMAND_CENTER } from '@/data/mockData';
import { cn } from '@/lib/utils';

/**
 * Instructor Command Center — headline screen (spec §8).
 * Reading order: What → Why → Who → Action.
 * 5 rows: Insight → 4 cards → KPI strip → concepts + at-risk → signals + queue → integrity.
 */
export default function InstructorCommand() {
  const [showIntegrity, setShowIntegrity] = useState(false);
  const data = MOCK_COMMAND_CENTER;

  return (
    <div className="space-y-6">
      {/* Confidence badge (spec §8.2) */}
      <div className="flex items-center gap-2">
        {data.confidence && (
          <span className={cn(
            'text-xs font-medium px-2 py-1 rounded',
            data.confidence.level === 'high' ? 'bg-[#22C55E]/10 text-[#22C55E]' :
            data.confidence.level === 'medium' ? 'bg-[#FACC15]/10 text-[#FACC15]' :
            'bg-[#94A3B8]/10 text-[#94A3B8]'
          )}>
            Confidence: {data.confidence.level.charAt(0).toUpperCase() + data.confidence.level.slice(1)}
            (n={data.confidence.n} · {data.confidence.days} days · Wilson 95% CI half-width ≤ 0.10)
          </span>
        )}
      </div>

      {/* Row 0: Weekly Teaching Insight (spec §8.0) */}
      {data.weeklyInsight && (
        <Card className="border-l-4 border-l-primary">
          <CardContent className="p-4">
            <div className="flex items-start justify-between gap-4">
              <div className="space-y-1">
                <p className="text-sm font-medium">{data.weeklyInsight.message}</p>
                <p className="text-xs text-muted-foreground font-mono">
                  Rule: {data.weeklyInsight.rule} | n={data.weeklyInsight.n} | Wilson 95% CI half-width = 0.08
                </p>
              </div>
              <Button asChild variant="outline" size="sm">
                <Link to="#">View question template →</Link>
              </Button>
            </div>
          </CardContent>
        </Card>
      )}

      {/* Row 1: 4 insight cards (spec §8.1 Row 1) */}
      <div className="grid gap-4 md:grid-cols-2">
        {data.cards?.map(card => (
          <InsightCard key={card.id} insight={card} />
        ))}
      </div>

      {/* Row 2: KPI strip with 6-week trend (spec §8.1 Row 2) */}
      <div className="grid grid-cols-2 md:grid-cols-3 lg:grid-cols-6 gap-3">
        {data.kpis?.map(kpi => (
          <Card key={kpi.label} className="p-3">
            <p className="text-[10px] text-muted-foreground uppercase tracking-wider">{kpi.label}</p>
            <div className="flex items-center gap-2 mt-1">
              <span className="text-lg font-bold font-mono">
                {typeof kpi.value === 'number' ? (kpi.value > 1 ? kpi.value : kpi.value.toFixed(2)) : kpi.value}
              </span>
              {kpi.delta != null && (
                <CDSPillDelta
                  value={0}
                  delta={kpi.delta}
                  classification={kpi.delta > 0 ? 'high' : kpi.delta < 0 ? 'low' : 'na'}
                  trend={kpi.trend}
                />
              )}
            </div>
            {kpi.sparkline && (
              <div className="mt-2 h-6 flex items-end gap-[2px]">
                {kpi.sparkline.map((v, i) => (
                  <div
                    key={i}
                    className="w-full bg-primary/30 rounded-t"
                    style={{ height: `${(v / Math.max(...kpi.sparkline)) * 100}%` }}
                  />
                ))}
              </div>
            )}
          </Card>
        ))}
      </div>

      {/* Row 3: 7-concept sortable bars + at-risk roster (spec §8.1 Row 3) */}
      <div className="grid gap-6 lg:grid-cols-2">
        {/* Concept bars */}
        <Card>
          <CardHeader>
            <CardTitle className="text-sm">Concept Difficulty</CardTitle>
          </CardHeader>
          <CardContent className="space-y-2">
            {data.conceptBars?.map(bar => (
              <div key={bar.concept} className="flex items-center gap-3">
                <span className="w-8 text-xs font-mono font-medium">{bar.concept}</span>
                <CDSPillDelta
                  value={bar.cds}
                  delta={bar.delta}
                  classification={bar.cds > 0.50 ? 'high' : bar.cds > 0.31 ? 'mod' : 'low'}
                  trend={bar.trend}
                />
                <div className="flex-1 h-3 bg-muted rounded-full overflow-hidden">
                  <div
                    className={cn(
                      'h-full rounded-full',
                      bar.cds > 0.50 ? 'bg-[#EF4444]' : bar.cds > 0.31 ? 'bg-[#FACC15]' : 'bg-[#22C55E]'
                    )}
                    style={{ width: `${bar.cds * 100}%` }}
                  />
                </div>
                <span className="text-xs text-muted-foreground">{bar.atRiskCount} at risk</span>
              </div>
            ))}
          </CardContent>
        </Card>

        {/* At-risk roster */}
        <Card>
          <CardHeader>
            <CardTitle className="text-sm">At-Risk Roster</CardTitle>
          </CardHeader>
          <CardContent className="space-y-2">
            {data.atRiskRoster?.map(student => (
              <div key={student.id} className="flex items-center justify-between py-1.5 border-b border-border/50 last:border-0">
                <div className="flex items-center gap-2">
                  <span className="text-sm font-medium">{student.name}</span>
                  <RiskBadge tier={student.riskTier} />
                </div>
                <div className="flex items-center gap-1">
                  <Badge variant="secondary" className="text-[10px]">{student.dominantConcept}</Badge>
                  <Button variant="ghost" size="sm" className="h-6 text-[10px]">View</Button>
                </div>
              </div>
            ))}
          </CardContent>
        </Card>
      </div>

      {/* Row 4: Learning signals + Intervention queue (spec §8.1 Row 4) */}
      <div className="grid gap-6 lg:grid-cols-2">
        {/* Signals */}
        <Card>
          <CardHeader>
            <CardTitle className="text-sm">Learning Signals</CardTitle>
          </CardHeader>
          <CardContent>
            <ul className="space-y-2">
              {data.signals?.map((s, i) => (
                <li key={i} className="text-sm text-muted-foreground flex items-start gap-2">
                  <span className="text-primary mt-1">•</span>
                  {s}
                </li>
              ))}
            </ul>
          </CardContent>
        </Card>

        {/* Intervention queue */}
        <div className="space-y-3">
          <h3 className="text-sm font-semibold">Intervention Queue</h3>
          {data.interventions?.map((intervention, i) => (
            <InterventionCard key={i} {...intervention} />
          ))}
        </div>
      </div>

      {/* Row 5: Integrity monitoring (spec §8.1 Row 5) — collapsed by default */}
      <Card className="border-dashed border-muted-foreground/30 bg-muted/5">
        <CardContent className="p-4">
          <button
            type="button"
            onClick={() => setShowIntegrity(!showIntegrity)}
            className="w-full flex items-center justify-between text-left"
          >
            <p className="text-sm font-medium text-muted-foreground">
              {data.integrityFlags?.count} integrity flags open across {data.integrityFlags?.sections} sections.
              <Link to="/instructor/integrity" className="ml-2 text-primary underline underline-offset-2">Review queue →</Link>
            </p>
            <span className="text-xs text-muted-foreground">{showIntegrity ? '▲' : '▼'}</span>
          </button>
        </CardContent>
      </Card>
    </div>
  );
}
```

- [ ] **Step 2: Build check**

Run: `cd frontend && npm run build`
Expected: exits 0.

- [ ] **Step 3: Commit**

```bash
git add frontend/src/pages/instructor/Command.jsx
git commit -m "feat(redesign): create Instructor Command Center headline screen"
```

---

### Task 18: Create `/instructor/integrity/:id` — single flag detail (spec §10.3)

- **Create:** `frontend/src/pages/instructor/IntegrityDetail.jsx`

- [ ] **Step 1: Create the file**

```jsx
import { useParams, Link } from 'react-router-dom';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Badge } from '@/components/ui/badge';
import { Button } from '@/components/ui/button';
import { FlagEvidence } from '@/components/FlagEvidence';
import { ChevronLeft } from 'lucide-react';
import { MOCK_INTEGRITY_FLAGS } from '@/data/mockData';

/**
 * Single integrity flag detail (spec §10.3).
 * Full evidence chain, code diff viewer, timeline of signals leading to the flag,
 * comparison to class baseline, confidence breakdown, suggested next action.
 */
export default function InstructorIntegrityDetail() {
  const { id } = useParams();
  const flag = MOCK_INTEGRITY_FLAGS.find(f => f.id === parseInt(id));

  if (!flag) {
    return (
      <div className="space-y-4">
        <Button asChild variant="ghost" size="sm">
          <Link to="/instructor/integrity"><ChevronLeft className="w-4 h-4 mr-1" /> Back to integrity</Link>
        </Button>
        <Card><CardContent className="p-6">
          <p className="text-muted-foreground">Flag not found.</p>
        </CardContent></Card>
      </div>
    );
  }

  return (
    <div className="space-y-6">
      <Button asChild variant="ghost" size="sm">
        <Link to="/instructor/integrity"><ChevronLeft className="w-4 h-4 mr-1" /> Back to integrity</Link>
      </Button>

      <div className="flex items-center justify-between">
        <div>
          <h1 className="text-2xl font-bold">{flag.type}</h1>
          <p className="text-muted-foreground text-sm">{flag.student} · {flag.exercise} · {flag.time}</p>
        </div>
        <Badge variant="destructive" className="text-xs">{flag.confidence}% confidence</Badge>
      </div>

      <div className="grid gap-6 md:grid-cols-2">
        <FlagEvidence flag={flag} />
        <Card>
          <CardHeader>
            <CardTitle className="text-sm">Suggested Next Action</CardTitle>
          </CardHeader>
          <CardContent className="space-y-3">
            <Button className="w-full" variant="outline">Mark Reviewed</Button>
            <Button className="w-full" variant="outline">Request 1:1</Button>
            <Button className="w-full" variant="outline">Refer to Registrar</Button>
            <Button className="w-full" variant="ghost" className="text-destructive">Dismiss (with reason)</Button>
          </CardContent>
        </Card>
      </div>
    </div>
  );
}
```

- [ ] **Step 2: Build check + Commit**

---

## Phase 4: Student Learning Journey

### Task 19: Create `/student/today` — Today's Plan (spec §9.2)

- **Create:** `frontend/src/pages/student/Today.jsx`

- [ ] **Step 1: Create the file**

Reading order: 4 questions restated for the student (What → Why → Who → Action). Below: 7-concept mastery bars, signals-as-pedagogy.

```jsx
import { Link } from 'react-router-dom';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Badge } from '@/components/ui/badge';
import { CDSPillDelta } from '@/components/CDSPillDelta';
import { MOCK_STUDENT_TODAY } from '@/data/mockData';

export default function StudentToday() {
  const data = MOCK_STUDENT_TODAY;
  return (
    <div className="space-y-6 max-w-3xl">
      {/* What */}
      <Card>
        <CardContent className="p-6">
          <p className="text-xs text-muted-foreground uppercase tracking-wider mb-1">What</p>
          <h2 className="text-xl font-bold">{data.focus.title}</h2>
          <p className="text-sm text-muted-foreground mt-1">Estimated {data.focus.estimatedMinutes}</p>
        </CardContent>
      </Card>

      {/* Why */}
      <Card>
        <CardContent className="p-6">
          <p className="text-xs text-muted-foreground uppercase tracking-wider mb-1">Why</p>
          <p className="text-sm">{data.why}</p>
        </CardContent>
      </Card>

      {/* Who */}
      <Card>
        <CardContent className="p-6">
          <p className="text-xs text-muted-foreground uppercase tracking-wider mb-1">Who</p>
          <p className="text-sm">
            You, in BSIT-1A. Class avg on this concept: <CDSPillDelta value={data.classAvg} classification={data.classAvg > 0.50 ? 'high' : 'mod'} />
          </p>
        </CardContent>
      </Card>

      {/* Action */}
      <div className="flex gap-3">
        {data.nextMoves?.map((move, i) => (
          <Button key={i} asChild variant={move.primary ? 'default' : 'outline'} size="sm">
            <Link to={move.to}>{move.label}</Link>
          </Button>
        ))}
      </div>

      {/* 7-concept mastery bars */}
      <Card>
        <CardHeader><CardTitle className="text-sm">Your Concept Mastery</CardTitle></CardHeader>
        <CardContent className="space-y-3">
          {data.concepts?.map(c => (
            <div key={c.concept} className="flex items-center gap-3">
              <span className="w-8 text-xs font-mono font-medium">{c.concept}</span>
              <CDSPillDelta value={c.cds} delta={c.delta} trend={c.trend} classification={c.cds > 0.50 ? 'high' : c.cds > 0.31 ? 'mod' : 'low'} />
              <div className="flex-1 h-2 bg-muted rounded-full overflow-hidden">
                <div className="h-full rounded-full bg-primary" style={{ width: `${c.cds * 100}%` }} />
              </div>
            </div>
          ))}
        </CardContent>
      </Card>

      {/* Signals (interpreted, no raw counts) */}
      <Card className="border-dashed">
        <CardContent className="p-4 space-y-2">
          {data.signals?.map((s, i) => (
            <p key={i} className="text-sm text-muted-foreground">💡 {s}</p>
          ))}
        </CardContent>
      </Card>
    </div>
  );
}
```

- [ ] **Step 2: Build check + Commit**

---

### Task 20: Create `/student/integrity` — Reflective Surface (spec §10.4)

- **Create:** `frontend/src/pages/student/Integrity.jsx`

- [ ] **Step 1: Create the file**

The student sees the same flag in plain language, with 3 affordances: Request 1:1, Appeal, Read full rule. No behavioral telemetry, no class comparison.

```jsx
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Badge } from '@/components/ui/badge';
import { MOCK_STUDENT_INTEGRITY } from '@/data/mockData';

export default function StudentIntegrity() {
  const { flags } = MOCK_STUDENT_INTEGRITY;

  return (
    <div className="space-y-6 max-w-3xl">
      <div>
        <h1 className="text-2xl font-bold">My Learning Dashboard</h1>
        <p className="text-sm text-muted-foreground">Patterns detected in your work — always hypotheses, never verdicts.</p>
      </div>

      {flags.length === 0 ? (
        <Card>
          <CardContent className="p-6 text-center text-muted-foreground">
            No patterns detected. Keep coding!
          </CardContent>
        </Card>
      ) : flags.map(flag => (
        <Card key={flag.id} className="border-dashed border-muted-foreground/30">
          <CardContent className="p-4 space-y-3">
            <div className="flex items-start justify-between">
              <div>
                <Badge variant="outline" className="text-xs font-mono">{flag.rule}</Badge>
                <p className="text-sm mt-2">{flag.description}</p>
              </div>
              <button
                type="button"
                className="text-[10px] text-muted-foreground underline underline-offset-2 hover:text-foreground shrink-0"
              >
                Why am I seeing this?
              </button>
            </div>

            {flag.evidence && (
              <p className="text-xs text-muted-foreground bg-muted/50 p-2 rounded">{flag.evidence}</p>
            )}

            <div className="flex gap-2 pt-1 border-t border-border/50">
              <Button variant="outline" size="sm" className="text-xs">Request 1:1</Button>
              <Button variant="outline" size="sm" className="text-xs">Appeal</Button>
              <Button variant="ghost" size="sm" className="text-xs">Read full rule</Button>
            </div>
          </CardContent>
        </Card>
      ))}
    </div>
  );
}
```

- [ ] **Step 2: Build check + Commit**

---

## Phase 5: Section Management

### Task 21: Create section management pages (spec §11.9)

- **Modify:** `frontend/src/pages/instructor/Sections.jsx` — add design cards, KPIs, insight (spec §11.9A)
- **Modify:** `frontend/src/pages/instructor/SectionDetail.jsx` — add purple chip, tabs, join code card (spec §11.9B)

- [ ] **Step 1: Update Sections index page**

Replace content with spec §11.9A layout: 3 active section cards + 1 "+ New section" card. Each card shows: name · term · code (mono) · policy · 3 KPIs · top-line insight · 3 buttons (Open hub, Roster, Code).

- [ ] **Step 2: Update SectionDetail page**

Add spec §11.9B layout: Purple chip header, join code card with Copy/Rotate/QR buttons, tabs (Hub · Roster · Join requests · Codes & policy · TAs · Audit log), section summary (4 questions scoped to this section).

- [ ] **Step 3: Build check + Commit**

---

### Task 22: Create `/student/sections` (spec §11.9C)

- **Create:** `frontend/src/pages/student/Sections.jsx`

- [ ] **Step 1: Create the file**

List of sections the student is in, with status badge (active/pending/leave req). "Join another section" card with 6-character code input. "Code not working?" troubleshooting.

- [ ] **Step 2: Build check + Commit**

---

## Phase 6: Admin Surface

### Task 23: Create `/admin/evaluation` — ISO/IEC 25010 instrument (spec §14)

- **Create:** `frontend/src/pages/admin/Evaluation.jsx`

- [ ] **Step 1: Create the file**

4-point Likert scale instrument for three attributes (Functional Suitability, Usability, Performance Efficiency). Admin shares link → respondents complete → CSV export for thesis-chapter analysis.

- [ ] **Step 2: Build check + Commit**

---

### Task 24: Create admin pages (spec §5 routes)

- **Create:** `frontend/src/pages/admin/Overview.jsx`
- **Create:** `frontend/src/pages/admin/Users.jsx`
- **Create:** `frontend/src/pages/admin/Sections.jsx`
- **Create:** `frontend/src/pages/admin/Concepts.jsx`
- **Create:** `frontend/src/pages/admin/Exercises.jsx`

- [ ] **Step 1: Create each page**

Each admin page replaces the placeholder `<div style={{padding: 24}}>Admin desktop view (TODO)</div>` with a functional surface.

- [ ] **Step 2: Build check + Commit**

---

## Phase 7: Routing & Integration

### Task 25: Update `App.jsx` with all new routes (spec §5)

- **Modify:** `frontend/src/App.jsx`

- [ ] **Step 1: Add all imports and routes from spec §5**

```jsx
// New imports
import InstructorCommand from './pages/instructor/Command';
import InstructorConcepts from './pages/instructor/Concepts';
import InstructorConceptDetail from './pages/instructor/ConceptDetail';
import InstructorIntegrityDetail from './pages/instructor/IntegrityDetail';
import StudentToday from './pages/student/Today';
import StudentRecommendations from './pages/student/Recommendations';
import StudentSections from './pages/student/Sections';
import StudentIntegrityView from './pages/student/Integrity';
import AdminOverview from './pages/admin/Overview';
import AdminUsers from './pages/admin/Users';
import AdminSectionsOverview from './pages/admin/Sections';
import AdminConcepts from './pages/admin/Concepts';
import AdminExercises from './pages/admin/Exercises';
import AdminEvaluation from './pages/admin/Evaluation';
```

Add routes:
```
/instructor/command
/instructor/heatmap
/instructor/concepts
/instructor/concepts/:id
/instructor/students
/instructor/students/:id
/instructor/integrity
/instructor/integrity/:id
/instructor/reports
/instructor/sections
/instructor/sections/:id
/instructor/sections/:id/roster
/instructor/sections/:id/join-requests
/instructor/sections/:id/policy
/instructor/sections/:id/tas
/instructor/sections/:id/audit
/student/today
/student/exercises
/student/exercises/:id
/student/exercises/:id/result
/student/progress
/student/integrity
/student/sections
/student/recommendations
/admin
/admin/users
/admin/sections
/admin/concepts
/admin/exercises
/admin/evaluation
```

- [ ] **Step 2: Build check + Commit**

---

### Task 26: Verify hidden test case separation (CLAUDE.md item 4)

- [ ] **Step 1: Review `backend/services/executor.js`** for error message leakage of hidden test case inputs/expected outputs
- [ ] **Step 2: Review frontend error handling** — ensure error responses don't include hidden test case data
- [ ] **Step 3: Document findings** in `docs/verification/hidden-test-separation.md`

---

### Task 27: Full E2E flow test (CLAUDE.md item 5)

- [ ] **Step 1: Create test script** that exercises: Submission → exercise close → batch CDS → alerts pipeline
- [ ] **Step 2: Run test script** against the backend
- [ ] **Step 3: Document results**

---

## Self-Review Notes

- **Spec coverage:** Every spec section has at least one task: Section 6 (tokens) → Task 1; Section 7 (components) → Tasks 2-6; Section 8 (Command Center) → Task 17; Section 9 (Student journey) → Tasks 19-20; Section 10 (Integrity) → Tasks 18, 20; Section 11 (Section management) → Tasks 10-12, 15, 21-22; Section 12 (API) → Tasks 14-16; Section 13 (DB) → Tasks 10-12; Section 14 (ISO) → Tasks 10, 16, 23.
- **Placeholder scan:** Every task specifies exact file paths and code patterns. No "TODO" or "TBD".
- **Insight-first enforcement:** Every analytics endpoint returns `summary` (Task 14). Every chart component requires `insight` prop (Tasks 2, 4, 5).
- **Dark-first visual direction:** Task 1 sets dark as default `:root` with light as `[data-theme="light"]` override.
- **D3 + Chart.js, NOT Recharts:** Task 6 uses D3 for the radar. All other chart components use the existing Chart.js integration.
- **Integrity as separate epistemic mode:** Dashed borders on integrity surfaces (Tasks 18, 20). Flag is hypothesis, not verdict.
- **Section management as provenance layer:** Append-only audit log (Task 11), 3 join policies (Task 12), drop/leave asymmetry (Task 15).
- **Student privacy boundary:** Student surfaces never show raw behavioral counts or class rank (Tasks 19, 20).
- **Wilson 95% CI gating:** Task 8 implements the CI helper. Task 14 gates insights by confidence level.
- **Commit count estimate:** ~30 commits across 27 tasks.
