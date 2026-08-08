# Export Overhaul Plan (saved — paused in favor of code-editor bug fixes)

Status: PAUSED. Research complete (reasoner, incl. PDF/PNG visual export verdict).
Resume point: Phase 1 (backend core). No implementation started yet.

## Goal

Replace the current minimal, inconsistent export endpoints with a comprehensive,
consistent export system covering all instructor-facing analytics data in the
platform: per-section exports (CSV / XLSX / JSON), per-student dossiers, and a
PDF/PNG visual "Section Visual Report" (charts, heatmap, radar) as a later tier.

## Current State (as-is)

- `backend/routes/export.js` — `GET /api/export/section/:sectionId?format=csv|xlsx`
  Single flat join: enrollments → users → submissions → exercises.
  Hand-rolled CSV is broken for multi-line code, has no UTF-8 BOM, uses
  locale-formatted dates.
- `backend/controllers/UploadsController.js` — `exportRoster`
  `GET /api/sections/:id/export` — XLSX only, 3 columns (name, email, enrolled_at).
- `frontend/src/pages/instructor/Dashboard.jsx` — `handleExportCSV` (Date, CDS) +
  `handleExportExcel` (calls the section export endpoint).
- `frontend/src/pages/instructor/StudentDetail.jsx` — `handleExportSubmissions`
  CSV (Exercise, Attempt, Passed, Submitted).
- Libraries available: `exceljs`, `csv-parse` (import only), `bullmq` + `ioredis`,
  `node-schedule`. No CSV writer yet (write one or add `csv-stringify`).

## Data Domains (11)

1. Section roster — students, emails, enrollment dates, course
2. Submissions — student, exercise, attempt #, status, result, code, feedback, timestamps
3. Integrity flags — student, type, severity, status, source, timestamps
4. CDS history — daily/weekly CDS per student
5. Concept mastery — per concept, per student
6. Heatmap data — submission events per day/student
7. Behavioral analytics — IDE-style events (clicks, keystrokes, pauses)
8. Course catalog — exercises, topics, lessons
9. Class settings / configuration
10. Alerts — past notifications/triggers
11. Longitudinal overview — term-long aggregates

## Formats & Conventions

- CSV: RFC 4180, UTF-8 BOM, proper escaping (quotes/newlines — critical for code fields).
- XLSX: exceljs (multi-sheet for multi-domain exports).
- JSON: raw dump option for full fidelity.
- Async job-based exports for >5000 rows: BullMQ queue + DB snapshot, job status
  polling endpoints, download URL when ready.
- Consistent filename conventions: `{section_name}_{domain}_{date}.{ext}`.

## Frontend

- Reusable `ExportDropdown` component + `useExport` hook.
- Wired into Dashboard, Heatmap, Integrity, StudentDetail.
- Consistent UX: format picker → loading → download link/stream; error states.

## Phases (52 steps total, ~3–4 sessions)

- Phase 1 — backend `exportService.js` core: CSV writer (RFC 4180 + BOM), XLSX via
  exceljs, exports for roster / submissions / integrity, unit tests.
- Phase 2 — remaining domains: CDS history, concept mastery, heatmap, behavioral,
  catalog, settings, alerts, longitudinal.
- Phase 3 — async job queue for large exports (BullMQ + ioredis, job status
  endpoints, download links).
- Phase 4 — frontend `ExportDropdown` + `useExport` integration across instructor pages.
- Phase 5 — JSON format + advanced options (filters, date ranges, column selection).
- Phase 6 — polish: filename conventions, docs, per-student dossiers.

## PDF / PNG Visual Export — Research Verdict

- YES to server-rendered PDF (first tier); per-chart PNG downloads (second tier).
- NO client-side PDF rasterization (added complexity, no benefit here).
- Recommended deliverable: "Section Visual Report" PDF:
  - Cover page (section, term, instructor, generated date)
  - Executive summary (class CDS stats, at-risk counts, integrity summary)
  - Class overview (CDS trend chart, heatmap, distribution)
  - Per-student pages (CDS trend, concept radar, heatmap snippet)
  - Integrity flags summary + appendix (raw tables)
- Chart rendering: server-side (e.g., node-canvas/chart.js or SVG→PDF) so the
  report is generated without browser involvement.

## Open Questions (when resuming)

- Which domains get the async path first (likely roster+submissions+integrity go
  sync until >5000 rows).
- PDF styling library choice (puppeteer vs node-canvas vs SVG-based) — research
  recommended picking SVG-based for zero-dependency server rendering.
