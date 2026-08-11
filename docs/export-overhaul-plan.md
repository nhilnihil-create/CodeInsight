# Export Overhaul Plan (CSV / XLSX / PDF) — Refreshed, Execution-Ready

Status: REFRESHED (2026-08-12) against current code state. No implementation started. Plan is execution-ready; review "Open Questions" before beginning Phase 1.

## Goal

Replace the current minimal, inconsistent export endpoints with a comprehensive, consistent export system covering all instructor-facing analytics data in the platform: per-section exports (CSV / XLSX / JSON), per-student dossiers, and a PDF "Section Visual Report" (charts, heatmap, radar) as a later tier.

## 1. Corrected current-state snapshot ("as-is")

### Backend endpoints (both live, both verifyToken + requireRole('instructor'), both mounted in backend/server.js)

| Endpoint | File | Behavior today |
|---|---|---|
| GET /api/export/section/:sectionId?format=csv\|xlsx | backend/routes/export.js (only route in file) | Single flat join enrollments→users→submissions→exercises. CSV hand-rolled, 7 cols (Name, Email, Exercise, Attempt, Passed, CDS, Submitted): escapes only `"`, no newline handling, no UTF-8 BOM, toLocaleDateString() dates (server-locale dependent), cds emitted as "12.3%" string, no code column at all — multiline-code breakage is currently latent (only exploitable if title/name/email contain newlines); the real risk lands the moment a code field is added. XLSX via exceljs, single sheet "Section Data", same 7 cols, same locale dates. Filenames section-{sectionId}-export.{ext}. |
| GET /api/sections/:id/export | backend/controllers/UploadsController.js → exportRoster (route at backend/routes/sections.js:51) | XLSX only, 3 cols (Name, Email, Enrolled At), toLocaleDateString(), filename section-{id}-roster.xlsx. |

- Security gap (pre-existing): neither endpoint verifies the section belongs to req.user — any instructor can export any section by ID. Also format is unvalidated (unknown values silently fall back to CSV), and sectionId is unvalidated (no validate.params).

### Frontend ad-hoc handlers (no shared component/hook)
- Dashboard.jsx — handleExportCSV (client-side Blob CSV: Date, CDS from dashboard trend) + handleExportExcel (GET /api/sections/${sectionId}/export, blob). Radix DropdownMenu UI.
- Reports.jsx — handleExportCSV (client-side, per tab: mastery/concepts×weeks, completion, integrity-timeline), handleExportExcel (same section endpoint), downloadEndpointExport (calls /api/export/section/${activeSectionId}?format=csv).
- SectionDetail.jsx — handleExportCSV (client-side from GET /api/sections/:id/students), handleExportExcel.
- StudentDetail.jsx — handleExportSubmissions (client-side from in-memory submissions state: Exercise, Attempt, Passed, Submitted).
- Heatmap.jsx, Integrity.jsx, Alerts.jsx, ClassMicroConceptReport.jsx exist but have NO export UI (old plan's "wired into Heatmap/Integrity" was aspirational).

### Dependencies & data
- Backend has exceljs@4.4.0, csv-parse@5.6 (sync parse, import only), bullmq@5.78 + ioredis@5.11, node-schedule. No CSV writer, no PDF lib, no puppeteer. Redis ships in docker-compose.yml (redis:7-alpine); backend/queues/submissionQueue.js establishes the house pattern: BullMQ with graceful synchronous fallback when Redis is down (initQueue() timeout 5s, redisAvailable flag).
- All 11 data domains are available in schema.sql: submissions (code TEXT, cds/ner/nrs/nts, attempt_number, is_correct, is_verified, time_spent_seconds, tab_switch_count, paste_count, idle_time_seconds, cppcheck_warnings, submitted_at), cds_scores, cds_snapshots, student_concept_metrics (cmi, velocity), section_concept_metrics (crs, crs_score, at_risk_count), alerts + analytics_alerts, integrity_flags (flag_type, severity, evidence JSONB, context_behaviors text[], status), behavioral_events, run_attempts, audit_log, code_snapshots, exercises, sections (name, course_code, instructor_id, term), enrollments (enrolled_at). Existing query sources to reuse: integrityFlagEngine.getFlagsForSection, analyticsController.getConceptMasteryReport / getCompletionReport / getIntegrityTrends / getSectionLongitudinal / getStudentSubmissions / heatmap.
- Test runners (verified): backend = jest (backend/jest.config.js: roots test/ + services/, *.test.js, node env, 30s timeout, dotenv). Frontend = vitest (frontend/vitest.config.js: jsdom, globals, setup src/test/setup.js with Radix pointer-capture polyfill, @ alias), co-located .test.jsx files. Backend route tests use ad-hoc express app + http server + jwt.sign helper (pattern in backend/test/runCheckpointIntegrity.test.js; no supertest dep).
- Naming conventions: backend flat services/ (camelCase files); frontend UI components src/components/ui/<kebab-case>.jsx, hooks src/hooks/<useCamel>.js, services src/services/*.js + src/api/analyticsService.js; toasts via sonner; axios client @/services/api (withCredentials, 401→/login).

## 2. Re-scoped execution-ready phases

Dependency chain: P1 → P2 (parallel per-domain) → P3 (frontend, parallel page rewires) → P4 (PDF, reuses P2 fetchers). P5 deferred.

### Phase 1 — Backend export core (sequential; ~0.5–1 day)
1. CSV writer module — pure RFC 4180 writer. New backend/services/csvWriter.js: csvEscape(value) (quote-escape ", wrap only when field contains , " \r \n or leading/trailing whitespace; null/undefined → empty), toCsv(rows, columns) → Buffer starting with UTF-8 BOM (\uFEFF), \r\n line endings, last line newline-terminated. columns = { key, header, format?(value, row) }[]. Edge cases: multiline code, embedded CR/LF, quotes, numbers, booleans, null, pre-formatted date values. Verify: backend/test/csvWriter.test.js; npm test -- csvWriter in backend/.
2. Export service — domain registry + format dispatch + filename/headers + ownership helper. New backend/services/exportService.js: sanitizeFilename(name) (strip [\\/:*?"<>|], collapse spaces, cap 60 chars), buildExportFilename({ sectionName, domain, ext, date }) → {sanitized}_{domain}_{YYYY-MM-DD}.{ext}, setDownloadHeaders(res, filename, mimeType) (RFC 5987 filename*=UTF-8''…), getSectionMeta(sectionId) (name, course_code, instructor_id), assertInstructorOwnsSection(sectionId, instructorId) (SELECT 1 FROM sections WHERE id=$1 AND instructor_id=$2, throw AppError(403)), fetchRows(domain, sectionId, opts), formatExport(domain, sectionId, format, opts). DOMAINS registry: roster, submissions (includes code column — the multiline stress case), integrity. Edge cases: section not found (404), not owned (403), empty result sets (header-only file, still valid), format whitelist (csv|xlsx|json → else 400). Verify: backend/test/exportService.test.js.
3. Rewire export router — backend/routes/export.js (rewrite), no server.js change (already mounted at /api/export). Canonical GET /api/export/:domain/:sectionId?format=&startDate=&endDate=&studentId= (domain whitelist + validate.params + ownership); legacy GET /api/export/section/:sectionId kept as alias → domain submissions so Reports.jsx's downloadEndpointExport keeps working. Edge cases: invalid domain/format → 400; missing/foreign section → 404/403; no data → valid header-only file. Verify: backend/test/exportRoutes.test.js; manual curl with cookie.
4. Delegate roster endpoint — backend/controllers/UploadsController.js exportRoster: replace inline exceljs with exportService for domain roster, keeping URL GET /api/sections/:id/export and default format xlsx (drop-in for the 3 consuming pages). Keep 3-col default shape identical (Name, Email, Enrolled At); dates now ISO-8601 (deliberate fix). Verify: route test + manual.

### Phase 2 — Remaining domains (parallelizable per domain; each ~2–4h; total ~1–1.5 days)
Pattern per domain: add { fetch, columns } entry in exportService.js + test block. Reuse existing services/controller SQL.

| Domain | Data source (reuse) | Notes |
|---|---|---|
| cds (CDS history) | cds_scores + cds_snapshots joins; align with getSectionLongitudinal | daily/weekly per student |
| mastery | student_concept_metrics/section_concept_metrics; align with getConceptMasteryReport | concept × student CMI/velocity |
| completion | align with getCompletionReport query | exercise on-time/late/missing |
| heatmap | align with analyticsController.heatmap where-clause | day×student event cells |
| behavioral | behavioral_events, audit_log, run_attempts | event_type + payload JSON stringified in CSV, native in JSON |
| catalog | exercises + concepts for section | title, description, starter_code, time limit |
| settings | sections row + policy | one-row export |
| alerts | alerts + analytics_alerts | status/severity/evidence |
| longitudinal | getSectionLongitudinal | term aggregates |

- JSON format ships here (cheap: JSON.stringify(fetchRows()) with application/json, raw DB fidelity — cds 0–1 decimal, booleans, ISO timestamps). Edge cases: JSONB evidence/payload deep-object handling; very large behavioral exports (row-count guard). Verify: per-domain test asserting column headers + row counts + a multiline-code cell round-trip through csv-parse/sync (already a dep).

### Phase 3 — Frontend shared layer + page rewires (sequential build, parallel rewires; ~1–1.5 days)
1. API service — new frontend/src/services/exportApi.js: buildExportUrl(domain, sectionId, { format, studentId }), fetchExportBlob(domain, sectionId, { format, studentId, onProgress }) (axios responseType blob, parse Content-Disposition filename when present), triggerDownload(blob, filename) (object-URL create/revoke; stub URL.createObjectURL in tests). Verify: frontend/src/services/exportApi.test.js (vitest, mocked @/services/api).
2. useExport hook — new frontend/src/hooks/useExport.js + useExport.test.js: returns { startExport(opts), status: 'idle'|'loading'|'done'|'error', error, fileName }; startExport({ domain, sectionId, format, studentId, fileName }) guards sectionId == null, sets loading, calls fetchExportBlob, triggerDownload, toasts via sonner. Edge cases: double-click re-entrancy guard, 401 interceptor already redirects, empty blob, non-2xx blob errors (parse error JSON out of blob). Verify: vitest with vi.mock('@/services/exportApi').
3. ExportDropdown component — new frontend/src/components/ui/export-dropdown.jsx + export-dropdown.test.jsx: props { sectionId, domain, formats = ['csv','xlsx','json'], fileName?, label='Export', align, disabled }, wraps existing Radix dropdown-menu.jsx (already exported), renders one item per format, wires useExport, shows spinner in item while loading, disables when disabled || !sectionId. Edge cases: no section → disabled state; unmount during fetch. Verify: vitest (Radix polyfill already in src/test/setup.js).
4. Page rewires (parallel, one commit each): Dashboard.jsx (trend CSV → domain cds), Reports.jsx (per-tab CSV → domains mastery/completion/integrity-trends; keep tab state passing to pick domain), SectionDetail.jsx (roster CSV → domain roster), StudentDetail.jsx (submissions CSV → domain submissions + studentId). Replace each page's ad-hoc DropdownMenu+handlers with <ExportDropdown …>, then delete the old handlers (order matters — see §5). Verify: npm run lint + npm test (frontend) + manual per-page smoke test.
5. (Optional, small) Add ExportDropdown to Heatmap.jsx / Integrity.jsx / Alerts.jsx / ClassMicroConceptReport.jsx (domains heatmap/integrity/alerts/mastery). No handlers to remove.

### Phase 4 — PDF "Section Visual Report" v1 (sequential; ~1–1.5 days)
1. Chart primitives — new backend/services/pdfCharts.js: pure functions over pdfkit's vector API: renderLineChart(doc, {x,y,w,h,series,labels,color}), renderBarChart(...), renderRadarChart(doc, {axes, values, center, radius, color}), renderHeatmapGrid(doc, {rows, cols, cellW, cellH, colorFn, labels}), shared CDS_STOPS color ramp mirroring Heatmap.jsx's stops (0→#1a5f50 … 1→#be123c) so PDF visuals match the app. Edge cases: empty series, single data point, long labels (clamp/truncate), null cds → "No Data" cell. Verify: backend/test/pdfCharts.test.js — test the math (scales, grid layout, color interpolation) as pure functions; don't assert pixels.
2. Report builder — new backend/services/pdfReport.js: buildSectionVisualReport(sectionId, { studentId? }): Promise<Buffer> using pdfkit (single dep, pure JS). Pages: cover (section, term, course, instructor, generated date) → exec summary (class avg CDS, at-risk counts, integrity summary counts) → class overview (CDS trend line, heatmap, distribution bar) → per-student pages (CDS trend, concept radar, heatmap snippet) → integrity flags table + appendix raw tables (reuse P2 fetchers for cds, mastery, heatmap, integrity). studentId present → dossier: cover + that student's pages only. Edge cases: 0 students (single page "no data"), >60 students → throw 413 "section too large for visual report" (guard), page-count cap (≈2 pages/student), long names. Verify: backend/test/pdfReport.test.js asserts buffer starts with %PDF-, byte length > threshold, page count parsed from /Type /Page count; manual open in viewer.
3. Route — backend/routes/export.js: GET /api/export/visual-report/:sectionId?studentId= and/or domain=visual-report in the canonical router (recommend canonical domain=visual-report for one URL scheme; filename {section}_visual-report_{date}.pdf). Same-process synchronous handler. Verify: route test (200 + application/pdf + filename header; 413 guard test).

### Phase 5 — Deferred (documented, NOT in this execution pass)
BullMQ async tier (>25k rows → job + GET /api/export/jobs/:id status + download URL, reusing submissionQueue pattern incl. sync fallback); per-chart PNG downloads (candidate: @resvg/resvg-js, prebuilt binaries — revisit when scoped); advanced options UI (date range, column selection); admin all-sections export.

## 3. Locked decisions (recommendation + rationale)

1. CSV writer: hand-rolled RFC 4180. ~25 lines, zero new dep, full control of BOM + \r\n + column formatting, trivially unit-testable — matches repo minimalism (no existing writer deps; csv-parse is parse-only). Fallback: add csv-stringify if a later reviewer prefers a library; interface (toCsv(rows, columns) → Buffer) is unchanged either way.
2. ExcelJS multi-sheet strategy: one workbook per request; single sheet per domain; multi-sheet only when a future combined domain (section-all) exists. Dates = ISO-8601 strings; CDS = numeric percent 0–100 with header "CDS (%)"; passed = "Yes"/"No"; header row frozen, column widths from ColumnDef.width. Rationale: keep v1 scope small; exceljs already proven in-repo.
3. Async: deferred from v1. Sync path up to 25,000 rows/request; above that → 413 with explicit message. Rationale: realistic section scale (≤200 students × ≤100 submissions ≈ 20k rows) streams fine in exceljs; Redis isn't guaranteed in dev/test (submissionQueue's fallback proves the team treats Redis as optional); sync routes are trivially testable. BullMQ phase reuses the existing queues/submissionQueue.js pattern when it lands.
4. PDF stack: pdfkit (pure JS vector drawing), chosen over puppeteer and node-canvas. Rationale: puppeteer = Chromium download + headless-launch pain on WSL/Windows/CI and heavy dep; node-canvas = native node-gyp builds, the classic WSL/Windows breakage risk; pdfkit is dependency-light, embeds its own base-font metrics (no system fontconfig), deterministic and testable, and all four chart types (line/bar/heatmap/radar) are straightforward vector drawing. Fallback: if pixel-perfect parity with the web UI becomes a requirement, switch to puppeteer + an HTML/CSS template (would be a new phase, not a patch). Same-process, synchronous generation with a 60-student guard — no separate worker process in v1 (PM2 already runs 2 cluster instances; a bounded ~3–5s generation during an explicit user action is acceptable; a separate worker is only warranted when async tier lands).
5. pdfkit license/policy: MIT — confirm the team is fine adding one new runtime dependency (the only new dep in the whole plan).

## 4. Testing strategy

- Backend (jest, backend/test/*.test.js, npm test in backend/):
  - csvWriter.test.js (pure): multiline code cell stays intact; embedded " doubled; CR/LF preserved; BOM = bytes EF BB BF at buffer start; empty/null fields; CRLF line endings; trailing newline.
  - exportService.test.js: sanitizeFilename / buildExportFilename (spaces, slashes, non-ASCII, date format); formatExport for csv/xlsx/json; XLSX read-back via exceljs (sheet count, header row, row counts, a multiline cell); CSV round-trip through csv-parse/sync; DB-backed fetchers using ./setup seeds (seedFullScenario + seedSubmission with \n-laden code) asserting row counts per domain; empty-section → header-only file.
  - exportRoutes.test.js (ad-hoc express app + http server + signToken, pattern from runCheckpointIntegrity.test.js): 401 no token; 403 student role; 403 instructor exporting another instructor's section (ownership guard); 400 bad domain/format; 200 csv/xlsx/json with correct Content-Disposition filename; 404 unknown section.
  - pdfCharts.test.js (pure math) + pdfReport.test.js (%PDF- magic, page count via /Type /Page tokens, 413 >60 students, dossier with studentId).
- Frontend (vitest, npm test in frontend/): exportApi.test.js (mocked @/services/api; blob + filename-from-header fallback), useExport.test.js (mocked exportApi: loading state, double-click re-entrancy, error toast, URL.createObjectURL stubbed), export-dropdown.test.jsx (renders format items, disabled without sectionId, item shows loading, click calls startExport with correct domain/format).
- Runner statement: backend jest, frontend vitest — both configs verified present.

## 5. Migration / rollout

1. Backend-first, additive only: P1–P2 add new endpoints and keep both legacy URLs byte-compatible in behavior (/api/sections/:id/export stays 3-col roster XLSX; /api/export/section/:sectionId stays submissions). No existing route is removed or changed in shape during P1–P2, so the deployed bundle keeps working untouched.
2. Ship shared frontend components (P3.1–3.3) without touching any page.
3. Drop-in per page, then dedupe: for each page, swap the ad-hoc DropdownMenu+handler block for <ExportDropdown> in the same UI slot, confirm the exported file's column set matches what the old handler produced (Dashboard Date,CDS; Reports mastery/completion/integrity headers; SectionDetail Name,Email,Enrolled At; StudentDetail Exercise,Attempt,Passed,Submitted) — server-side output is strictly better (BOM, escaping, ISO dates) but must not surprise instructors with changed columns — then delete the old handler and its now-unused imports in the same commit (lint will flag dead imports). One commit per page.
4. Deploy: single backend release after P1–P2; frontend bundle can ship the shared components earlier or with P3 — independent. No feature flags needed since behavior is additive; the only intentional output changes (ISO dates, BOM, ownership 403s) are documented in the deploy note.

## 6. Open questions (review before Phase 1)

1. Ownership guard: adding instructor_id verification to export endpoints changes 403 behavior for any cross-section export that exists today — confirm no admin/tooling consumer (e.g., scripts/codenet-scanner.js, backend/ci-inspect.js) relies on exporting other instructors' sections.
2. CDS representation: locked recommendation is numeric 0–100 with "CDS (%)" header in CSV/XLSX (JSON keeps raw 0–1). Confirm instructors prefer % over raw decimal — Reports.jsx already displays %.
3. Visual report v1 scope: full class report (≈2 pages/student) vs summary-only first — page count vs the 60-student guard is the trade-off; is 60 the right cap?
4. Column parity: should Dashboard/Reports CSV columns stay exactly as today (muscle memory) or may the server-side versions add sensible columns (e.g., code, timestamps) — locked plan says parity; flag if parity isn't desired.
5. pdfkit dependency: MIT license — confirm the team is fine adding one new runtime dependency (the only new dep in the whole plan).
