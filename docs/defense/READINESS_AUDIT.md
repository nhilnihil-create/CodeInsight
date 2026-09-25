# CodeInsight-V2 — Defense Readiness Audit
**Date:** 2026-09-25 | **Auditor:** Muse Spark 1.3 (direct, no executor subagent per team request)
**Target:** `C:\Users\Rokhai\CodeInsight-V2` | **Branch:** `CodeInsight-V2` | **Commit:** `cd42c640b641b745643ddfb4c662492213c53ca7`
**Working tree at audit:** `M SYSTEM_MAP.md`, `?? docs/architecture/` (5 files: 2×HTML + 2×PNG + README)
**Defense scope:** CodeInsight-V2, 7 members, 30–60 min slot

## Verdict: CONDITIONAL GO (fix 6 small items, then GO)
The system builds, lints clean, and has complete demo-critical paths. It is **presentable today**, but do the 6 fixes below (about 2–3 hours total, mostly rehearsal + hygiene) to walk in as a solid GO.

Do NOT claim full GO until: working tree is committed/tagged, full test suite is re-run on the frozen commit, and you have 3 successful cold-start demo rehearsals + fallback video.

## Evidence (re-run today, this machine)
| Check | Result | Notes |
|---|---|---|
| Backend lint `npm run lint --prefix backend` | ✅ PASS — 0 errors, 131 warnings | Warnings only (unused vars, `==` vs `===`). No blockers. |
| Frontend lint `npm run lint --prefix frontend` | ✅ PASS — 0 errors, 141 warnings | 1 item needs attention: `ResizableWorkbench.jsx:162 'process' is not defined` — see F-1 |
| Frontend build `npm run build --prefix frontend` | ✅ PASS — 13.7s, 3386 modules | Good chunk split: vendor-ui 442KB, pages-instructor 568KB (gzip 124KB/167KB). No build errors. |
| Node / npm | v24.14.1 / 11.17.0 | Repo targets Node 22+; Node 24 built fine. Use the same laptop for defense. |
| DB tables `CREATE TABLE` in `backend/schema.sql` | ✅ 30 tables | Matches new architecture docs (not the old "12 tables" claim). |
| Routes / Services | ✅ 12 route files / ~30 service files | Matches `docs/architecture/README.md` verified counts (12 controllers, 31 services incl. 1 test file, 15 lib, 87 frontend components). |
| Backend tests | ⚠️ NOT re-run today (historical: 905/905 per AUDIT_REPORT 2026-06-24) | Must re-run `npm run test --prefix backend` on frozen commit night before defense. |
| Frontend tests | ⚠️ NOT re-run today (historical: 99/99) | Re-run `npm run test --prefix frontend`. |
| E2E Playwright (4 specs) | ⚠️ NOT re-run today | Requires Postgres + Redis + backend + frontend running. Re-run at least `classroomWorkflow.spec.js` once. |
| Typecheck | ➖ Not configured (no `tsc --noEmit` script) | Don't claim type-safe; lint+build is your evidence. |

## What is actually ready
- **Auth:** JWT + bcrypt + Google GIS + OTP + blacklist logout. Seeded demo accounts in README work (`instructor@psu.edu` / `maria|jose|ana@student.psu.edu` / `password123`).
- **Student flow:** Monaco editor → Run (visible only) → Submit (all cases) → history → Progress (CDS + radar). Hidden-test masking verified in code (`routes/student.js` no longer leaks hidden pass/fail on `/run`).
- **Instructor flow:** Sections + join codes → Exercise create/bulk → Close triggers CDS → Heatmap → Alerts → Integrity flags → Reports/exports (CSV/Excel/PDF).
- **CDS engine:** `CDS = 0.40×NER + 0.35×NRS + 0.25×NTS`, p95-capped min-max, zero-variance guard, post-solution cutoff, integrity exclusions, confidence tiers (<5 Unscored, 5–9 Prelim, 10+ Confident). This is your #1 panel question — know it cold.
- **Integrity:** plagiarism/hardcoding/blank-template + behavioral (tab/paste/idle/retry-storm) + graduated flagging via shared `submissionPipeline.js` (sync+async unified).
- **Ops:** `/api/health` + `/api/ready`, helmet, rate limits (10/min submit, 60/min behavioral), pino logging, docker-compose (postgres16/redis7/backend), Dockerfile (node:22-alpine + g++), CI with 5 jobs.
- **Docs/diagrams:** `docs/architecture/` (dark + light HTML/PNG, A3 landscape) is defense-ready and far better than the old SYSTEM_MAP diagram. Use the **light PNG** for projection/printing.

## Findings — fix before presenting
### P1 — Critical (do these first, <1 hr)
| ID | Issue | Evidence | Fix (owner) | Accept test |
|---|---|---|---|---|
| F-1 | Frontend references `process` in browser code | `frontend/src/pages/student/editor/ResizableWorkbench.jsx:162` lint `no-undef` | Replace with `import.meta.env` guard or `typeof process !== 'undefined'` check (1 dev, 15 min) | `npm run lint --prefix frontend` shows 0 `no-undef`; `npm run build` still passes; open Code Editor page, no console error |
| F-2 | Uncommitted defense assets | `M SYSTEM_MAP.md`, `?? docs/architecture/` | Commit + tag e.g. `defense-v1.0` on a clean clone; burn PNG/HTML + `dist/` backup to USB (leader, 15 min) | `git status --short` clean on defense laptop; fallback PNG opens in <15s offline |
| F-3 | Live secret in local `backend/.env` (value NOT copied here) | Prior `AUDIT_REPORT.md` §Phase 2 + local `backend/.env` exists (git-ignored, good) | Rotate the Gmail App Password / Brevo key; never open `.env` on projector; use demo-only credentials (owner of email account, 5 min + provider delay) | New key works for OTP demo OR email is disabled with graceful message; old key revoked |
| F-4 | No frozen release candidate | Commit `cd42c64` + dirty files = unreproducible | Freeze: commit, `npm ci`, migrate + seed demo DB, record SHA in this report (leader, 20 min) | Any member can check out tag and reach `/api/health` + login |

### P2 — High (do before defense day)
| ID | Issue | Fix |
|---|---|---|
| F-5 | Full tests not re-run on this commit | Run `npm run test --prefix backend`, `npm run test --prefix frontend`, and 1 Playwright spec (`classroomWorkflow`) on the frozen tag. Record counts. If anything fails, triage — don't hide it. |
| F-6 | Email provider confusion (Brevo ACTIVE, nodemailer/resend installed but inactive) | Decide ONE story: "Brevo is active; others are legacy/inactive" (see `docs/architecture/README.md:45-46`). Remove or clearly label inactive providers in slides. Panel WILL ask. |
| F-7 | `PLAYWRIGHT=1` bypasses auth rate limits (`routes/auth.js`) | Never set this env in demo; mention it only if asked ("test-only bypass, never in prod"). Ideally guard with `NODE_ENV==='test'`. |

### P3 — Polish (nice-to-have)
- 272 lint warnings (`==` vs `===`, unused imports) — do NOT mass-fix now (risk). Just know the answer: "warnings, zero errors; enforced in CI as non-blocking."
- `console.*` still present in ~21 backend files (only 3 use pino) — answer: "structured logging on hot paths; full migration is future work."
- `backup.sh` default password + systemd `ExecStop pm2 stop` — dev-only, out of demo scope.
- CDS classification labels are counterintuitive in README (`Very Low CDS <= 0.20 (struggling significantly)`) — rehearse the explanation: low CDS = low struggle = mastering. Panel will probe this.

## Demo reliability checklist (must do)
- [ ] Freeze tag + `npm ci` + `npm run build --prefix frontend` green on the **defense laptop**
- [ ] Local Postgres + Redis running; `GET /api/health` and `/api/ready` return 200
- [ ] Seeded demo: 1 section, 3 students (maria/jose/ana), 1 exercise "Sum Two Numbers" (1 visible `2 3 → 5`, 1 hidden `10 20 → 30`)
- [ ] 3× cold-start rehearsals timed (target: full demo ≤ 12 min inside your 40-min talk)
- [ ] Fallback ready: (1) second local instance or hotspot, (2) 3-min screen recording, (3) light-architecture PNG + heatmap screenshot PDF — each opens offline in <15s
- [ ] Browser: clean profile, notifications off, zoom 125%, font large enough for back row, projector tested at 1366×768 AND 1920×1080
- [ ] No real student data, no `.env` on screen, no live registration, no real email dependency (pre-verify OTP or disable gracefully)
- [ ] Roles assigned for all 7 (see PANEL_PRESENTATION_GUIDE.md), Q&A mock done once

## Traceability (capstone artifacts)
| Artifact | Status | Location |
|---|---|---|
| Objectives / scope / users | ✅ in README + CLAUDE.md | `README.md`, `CLAUDE.md` |
| Architecture + deployment diagrams | ✅ new verified set (use these) | `docs/architecture/*.html|*.png`, `SYSTEM_MAP.md` (has SUPERSEDED notice — explain it) |
| ERD / 30-table schema | ✅ | `backend/schema.sql`, `docs/architecture/` Lane 7 |
| Sequence/activity (Run vs Submit, CDS on close) | ✅ in code + specs | `routes/student.js`, `services/cdsEngine.js`, `lib/submissionPipeline.js`, `e2e/classroomWorkflow.spec.js` |
| User manual | ⚠️ README Quick Start + Testing Workflow is enough for demo, but print a 1-page role cheat sheet | `README.md:63-150` |
| Validation (tests, UAT, eval) | ⚠️ historical 905+99 passing; ISO evaluation endpoint exists | `backend/test/`, `tests/uat/`, `pages/admin/Evaluation.jsx` — re-run before defense |
| Slides / video fallback | ❌ not in repo — create from guide | `docs/defense/PANEL_PRESENTATION_GUIDE.md` |

*Secret hygiene: this report intentionally omits all credential values. Old `AUDIT_REPORT.md` contains a revoked-value reference — rotate it and never paste it into slides, video, or chat.*
