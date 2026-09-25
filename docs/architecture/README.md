# CodeInsight V2 — Architecture Diagram

This directory contains the **complete, verified system architecture** for CodeInsight V2 as a self-contained HTML diagram and a rendered PNG.

## Files

| File | Description |
|------|-------------|
| `codeinsight-v2-architecture.html` | Self-contained HTML diagram (inline CSS, no CDN). A3 landscape, dark neon theme. |
| `codeinsight-v2-architecture.png` | Rendered PNG (1587×1123 px, A3 landscape @ 96dpi). |
| `codeinsight-v2-architecture-light.html` | Light-theme print variant of the same diagram (A3 landscape, white background, 600-level accent colors). |
| `codeinsight-v2-architecture-light.png` | Rendered light-theme PNG (1587×1123 px, A3 landscape @ 96dpi). |

## What was fixed vs. the original SYSTEM_MAP.md diagram

The original user-provided image was ~80% correct but omitted 10 critical areas. This diagram adds all of them:

1. **Sandbox / Executor branching** — Docker `gcc:14-bookworm` vs native `g++` fallback, ASAN (`-fsanitize=address`), `cppcheck` static analysis, `isSafe` guard (blocked syscalls), hidden-test masking (`[Hidden]`).
2. **Database schema depth** — 30 tables grouped into 8 clusters (Auth/Security, Sections/Enrollment, Concepts/Exercises, Submissions, CDS/Scoring, Integrity/Alerts, Behavioral/Audit, Metrics/Evaluation), not just "PostgreSQL".
3. **Security tier** — helmet, CORS allowlist, rateLimit, JWT + `token_blacklist`, bcryptjs.
4. **Observability** — pino / pino-http, `/health` + `/ready` endpoints, graceful shutdown (uncaughtException/unhandledRejection → 10s force timeout).
5. **External integrations** — Google OAuth via `google-auth-library`, Brevo email **active** (`@getbrevo/brevo`), resend/nodemailer **installed but inactive**, Swagger `/api/docs`.
6. **Async resilience** — sync fallback when Redis down, worker concurrency 3, DB-backed `cds_job_queue` (FOR UPDATE SKIP LOCKED), `autoCloseService` via node-schedule (5-min).
7. **Frontend internals** — Monaco editor, role-based pages (admin/instructor/student), contexts (Auth/EditorPrefs/Sidebar/Student), hooks, axios.
8. **DevOps** — Docker multi-stage, docker-compose (postgres16/redis7/backend), render.yaml (Neon/Upstash), cyclic.json, PM2 cluster, GitHub Actions.
9. **lib missing modules** — `impactTag`, `insightTemplates`, `wilsonScore` now shown.
10. **Explicit data-flow arrows** — HTTP (solid cyan), async/queue (dashed amber), sandbox (dotted rose), outbound/external (dashed sky), data (solid emerald).

## Verified counts (2026-09-07)

| Component | Count | Source |
|-----------|-------|--------|
| Routes | 12 | `backend/routes/` |
| Controllers | 12 | `backend/controllers/` |
| Services | 31 | `backend/services/` (32 `.js` files, 1 is a test) |
| lib modules | 15 | `backend/lib/` |
| Tables | 30 | `backend/schema.sql` (CREATE TABLE) |
| Queue files | 2 | `backend/queues/` |
| Middleware | 3 | `backend/middleware/` |
| Frontend components | 87 | `frontend/src/components/` |

## Notes / deviations from plan

- **Controllers**: plan said 14, actual repo has **12** (`adminConfigController`, `adminController`, `analyticsController`, `authController`, `enrollmentsController`, `evaluationController`, `exerciseController`, `integrityController`, `sectionController`, `sectionsController`, `submissionController`, `UploadsController`). The diagram uses the verified count of 12.
- **Services**: plan said 32, actual repo has **31** non-test service files (`academicIntegrityEngine.test.js` is a test, not a service). The diagram uses 31.
- **Email**: SYSTEM_MAP.md says Nodemailer (Gmail SMTP), but the active provider is **Brevo** (`@getbrevo/brevo` in `backend/lib/email.js`). Resend and nodemailer are installed but unused. The diagram marks Brevo ACTIVE and resend/nodemailer INACTIVE.

## Regenerating the PNG

```bash
node docs/architecture/screenshot.js
```

Requires Playwright with Chromium installed (already present in this repo's `node_modules`).

## Light theme variant

`codeinsight-v2-architecture-light.html` is a print-friendly light theme of the same diagram. It keeps the exact same layout, lane structure, and SVG arrow geometry as the dark version — only colors change.

- **Palette**: page/canvas `#ffffff`, lane background `#f8f9fb`, borders `#e5e7eb`, primary text `#111827`, secondary text `#6b7280`. Accent colors are the 600-level Tailwind shades: cyan `#0891b2`, violet `#7c3aed`, emerald `#059669`, amber `#d97706`, rose `#e11d48`, sky `#0284c7`.
- **Contrast**: dark ink (`#111827`) on white meets WCAG AA for normal text; 600-level accents on white/`#f8f9fb` are used for borders, dots, and legend lines (decorative, not text-bearing).
- **Regeneration**:

```bash
node docs/architecture/screenshot.js codeinsight-v2-architecture-light.html codeinsight-v2-architecture-light.png
```

## Linkage to SYSTEM_MAP.md

`SYSTEM_MAP.md` (repo root) carries a SUPERSEDED notice pointing here for the complete, verified architecture. Its Section 1 ASCII diagram mirrors the 8 lanes of these HTML diagrams, and its Section 3 table (30 tables · 8 clusters) matches Lane 7. The verified counts (12 routes / 12 controllers / 31 services / 15 lib / 30 tables) are shared across `SYSTEM_MAP.md`, both HTML diagrams, and their PNGs.
