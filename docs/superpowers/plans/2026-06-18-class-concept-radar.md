# Class-Wide Concept Radar Analytics

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Replace the horizontal bar concept mastery card in the instructor section Analytics tab with a radar chart showing class-wide concept mastery (NER/NRS/NTS breakdown per concept), grouped by knowledge area — matching the student profile radar but scoped to the entire class.

**Architecture:** Add a new backend endpoint `GET /api/analytics/sections/:sectionId/class-concept-radar` that returns per-concept aggregated CDS component data (avg NER, NRS, NTS across all students). Frontend replaces `ConceptMasteryBarSet` with the existing `ConceptRadarChart` component, fed by this new endpoint. The knowledge area grouping and segmented picker are reused from `ConceptRadarPanel`.

**Tech Stack:** Express.js backend, PostgreSQL, React + Recharts frontend, TanStack Query

---

## File Structure

| File | Action | Purpose |
|------|--------|---------|
| `backend/controllers/analyticsController.js` | Modify | Add `getClassConceptRadar()` handler |
| `backend/routes/analytics.js` | Modify | Add route for new endpoint |
| `frontend/src/pages/instructor/tabs/AnalyticsTab.jsx` | Modify | Fetch radar data, replace bar chart with radar |

---

### Task 1: Backend — New class concept radar endpoint

**Files:**
- Modify: `backend/controllers/analyticsController.js` (add `getClassConceptRadar` function)
- Modify: `backend/routes/analytics.js` (add route)

**Interfaces:**
- Consumes: `sectionId` from route params
- Produces: `GET /api/analytics/sections/:sectionId/class-concept-radar` → `{ concepts: [{ concept_name, cds, ner, nrs, nts, student_count, attempt_count }] }`

- [ ] **Step 1: Add the controller function**

In `backend/controllers/analyticsController.js`, add at the end of the file (before module.exports if applicable, or alongside other exports):

```js
exports.getClassConceptRadar = async (req, res, next) => {
  try {
    const { sectionId } = req.params;
    const result = await db.query(`
      SELECT
        c.name AS concept_name,
        ROUND(AVG(cs.cds)::numeric, 4) AS cds,
        ROUND(AVG(cs.ner)::numeric, 4) AS ner,
        ROUND(AVG(cs.nrs)::numeric, 4) AS nrs,
        ROUND(AVG(cs.nts)::numeric, 4) AS nts,
        COUNT(DISTINCT cs.student_id) AS student_count,
        COUNT(*) AS attempt_count
      FROM cds_scores cs
      JOIN exercises ex ON cs.exercise_id = ex.id
      LEFT JOIN exercise_concept_tags ect ON ect.exercise_id = ex.id AND ect.is_primary = true
      LEFT JOIN concepts c ON c.id = ect.concept_id
      WHERE cs.section_id = $1
      GROUP BY c.name
      ORDER BY c.name
    `, [sectionId]);
    res.json({ concepts: result.rows });
  } catch (err) { next(err); }
};
```

- [ ] **Step 2: Add the route**

In `backend/routes/analytics.js`, add after the existing section routes (near line 60):

```js
router.get('/sections/:sectionId/class-concept-radar', analyticsController.getClassConceptRadar);
```

- [ ] **Step 3: Verify the endpoint works**

```bash
curl -s -b /tmp/cookies.txt http://localhost:5000/api/analytics/sections/100/class-concept-radar | python3 -m json.tool
```

Expected output:
```json
{
  "concepts": [
    { "concept_name": "Arrays", "cds": "0.3000", "ner": "0.2500", "nrs": "0.1250", "nts": "0.6250", "student_count": "15", "attempt_count": "15" },
    { "concept_name": "Conditionals", "cds": "0.3250", ... },
    { "concept_name": "Loops", "cds": "0.2120", ... }
  ]
}
```

---

### Task 2: Frontend — Replace bar chart with radar in AnalyticsTab

**Files:**
- Modify: `frontend/src/pages/instructor/tabs/AnalyticsTab.jsx`

**Interfaces:**
- Consumes: New API endpoint from Task 1
- Produces: Renders `ConceptRadarChart` with class-wide data, knowledge area picker

- [ ] **Step 1: Add radar imports and data fetch**

Replace the imports and add new query. Change the top of `AnalyticsTab.jsx`:

```jsx
import { useState, useMemo } from "react";
import { useQuery } from "@tanstack/react-query";
import {
  ResponsiveContainer,
  LineChart,
  Line,
  XAxis,
  YAxis,
  CartesianGrid,
  Tooltip,
  Legend,
} from "recharts";
import { AlertTriangle } from "lucide-react";
import InsightHeader from "@/components/ui/insight-header";
import ConceptRadarChart from "@/components/concept-radar/ConceptRadarChart";
import SegmentedPicker from "@/components/ui/segmented-picker";
import { KNOWLEDGE_AREA_GROUPS, buildRadarDataForGroup } from "@/data/knowledgeAreaConcepts";
import api from "@/services/api";
```

- [ ] **Step 2: Add state and radar data fetch inside the component**

After the existing `longitudinal` query, add:

```jsx
const [selectedArea, setSelectedArea] = useState('SDF-FPC');

const { data: radarPayload, isLoading: radarLoading } = useQuery({
  queryKey: ["analytics-class-radar", sectionId],
  queryFn: async () => {
    const { data } = await api.get(`/api/analytics/sections/${sectionId}/class-concept-radar`);
    return data;
  },
  enabled: !!sectionId,
});
```

- [ ] **Step 3: Build radar data from API response**

After the `trendData` useMemo, add:

```jsx
const radarScores = useMemo(() => {
  if (!radarPayload?.concepts) return [];
  return radarPayload.concepts.map((c) => ({
    concept_name: c.concept_name,
    cds: Number(c.cds) || 0,
    ner: Number(c.ner) || 0,
    nrs: Number(c.nrs) || 0,
    nts: Number(c.nts) || 0,
  }));
}, [radarPayload]);

const radarData = useMemo(
  () => buildRadarDataForGroup(radarScores, selectedArea),
  [radarScores, selectedArea]
);

const pickerOptions = KNOWLEDGE_AREA_GROUPS.map((g) => ({
  key: g.key,
  label: g.shortLabel,
}));

const currentGroup = KNOWLEDGE_AREA_GROUPS.find((g) => g.key === selectedArea);
const totalConcepts = radarData.length;
const attemptedConcepts = radarData.filter((d) => d.attempts > 0).length;
```

- [ ] **Step 4: Replace ConceptMasteryBarSet JSX with radar**

Replace the concept mastery card (lines 133-150 in the original file):

```jsx
<div className="rounded-lg border border-border bg-card shadow-sm">
  <div className="px-5 py-3 border-b border-border">
    <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
      Class-Wide
    </p>
    <h3 className="text-sm font-semibold mt-0.5">Concept mastery radar</h3>
  </div>
  <div className="p-5">
    {radarLoading ? (
      <p className="text-sm text-muted-foreground text-center py-8">Loading radar…</p>
    ) : radarData.length > 0 ? (
      <div>
        <div className="flex items-center justify-between mb-3">
          <SegmentedPicker
            value={selectedArea}
            onChange={setSelectedArea}
            options={pickerOptions}
            size="sm"
          />
          <span className="text-[10px] font-mono uppercase tracking-wider text-muted-foreground/50">
            {attemptedConcepts}/{totalConcepts} concepts
          </span>
        </div>
        <p className="text-[10px] text-muted-foreground/50 mb-2 ml-0.5 font-mono tracking-wide">
          {currentGroup?.label}
        </p>
        <div className="h-72 w-full">
          <ConceptRadarChart data={radarData} />
        </div>
      </div>
    ) : (
      <p className="text-sm text-muted-foreground text-center py-8">
        No exercise data available yet
      </p>
    )}
  </div>
</div>
```

- [ ] **Step 5: Remove unused imports**

Remove `ConceptMasteryBarSet` import (line 16) since it's no longer used. Also remove `RefreshCw` from lucide-react imports if present.

- [ ] **Step 6: Verify in browser**

Navigate to `http://localhost:5173/instructor/sections/100` → Analytics tab. Verify:
- Radar chart renders with concept axes (Loops, Conditionals, Arrays)
- Knowledge area segmented picker works (Fundamentals, Design & Logic, OOP, Advanced)
- Tooltip shows mastery%, NER, NRS, NTS on hover
- Longitudinal progress line chart still renders beside it

---

### Task 3: Verify end-to-end

- [ ] **Step 1: Restart backend** (if not auto-restarted)
- [ ] **Step 2: Open browser** → instructor sections → section detail → Analytics tab
- [ ] **Step 3: Confirm radar renders** with 3 concepts (Loops, Conditionals, Arrays) under "Design & Logic" knowledge area
- [ ] **Step 4: Toggle knowledge area picker** — other areas show "No submissions yet" overlay (expected since we only have 3 exercises)
- [ ] **Step 5: Hover radar points** — tooltip shows mastery%, NER, NRS, NTS values
- [ ] **Step 6: Longitudinal chart** still works beside the radar
