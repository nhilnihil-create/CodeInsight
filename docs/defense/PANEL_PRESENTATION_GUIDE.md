# CodeInsight-V2 — Panel Presentation Guide
**Team:** 7 members | **Slot:** 30–60 min | **Recommended:** 40-min talk + 15–20 min Q&A (ends early = bonus points)
**Repo/tag:** `CodeInsight-V2` @ `cd42c64` + `defense-v1.0` tag (freeze before defense) | **Fallback diagram:** `docs/architecture/codeinsight-v2-architecture-light.png`

## Golden rules (panels fail teams on these)
1. Never show `.env`, passwords, or real student data. Synthetic demo only.
2. Never claim a number you can't click to. Every metric = live screen or labeled screenshot.
3. One laptop drives; everyone else narrates. No "let me login real quick" — pre-login all accounts.
4. If live demo dies, say the recovery line (below) and switch in <15s. Panels reward recovery, punish panic.

## Roles for 7 (assign names before final rehearsal)
| # | Role | Job | Backup |
|---|---|---|---|
| 1 | Leader / Narrator | Opens, closes, transitions, owns time | 7 |
| 2 | Demo Op — Student | Drives Monaco Run/Submit + Progress live | 3 |
| 3 | Demo Op — Instructor | Drives Sections → Close → Heatmap → Alerts → Reports | 2 |
| 4 | Architecture Explainer | 8-lane diagram, 30 tables, sandbox, queues | 5 |
| 5 | CDS + Integrity Technical | Formula, normalization, flags, behavioral, hidden tests | 4 |
| 6 | Q&A Lead | First answer on hard questions, owns "we don't know yet" | 1 |
| 7 | Timekeeper / Closer | Holds time cards, handles fallback video, delivers contributions + future work | 1 |

Rehearse handoffs with exact words: *"And now [Name] will show how a student experiences this."* No silent laptop passing.

## Time plan (40-min talk — trim/extend marked)
| Min | Block | % | Speaker | What panel sees |
|---|---|---|---|---|
| 0–3 | Problem + users | 8% | 1 | 1 slide: programming instructors can't see *struggle* until finals; students get pass/fail with no guidance. Users: students, instructors, admins (PSU CCS). |
| 3–7 | Objectives + scope | 10% | 1 | 1 slide: 4 objectives (submit+auto-grade C++, CDS struggle score, integrity flags, instructor analytics). Scope IN/OUT: C++ only, no auto-grading of style; email via Brevo only. |
| 7–13 | Architecture | 14% | 4 | Light PNG diagram: React+Monaco → Express (helmet/CORS/rate-limit/JWT) → 12 routes → 31 services → Postgres 30 tables (8 clusters) + Redis/BullMQ → g++ sandbox (Docker or native fallback). Point to lanes as you speak. |
| 13–26 | LIVE DEMO (core — only 3 actions) | 33% | 2 + 3 | See demo script below. Nothing else live. |
| 26–32 | Validation / results | 15% | 5 + 6 | Tests (905 backend + 99 frontend, lint 0 errors, build 13.7s), heatmap screenshot, confusion-free CDS explanation. Label anything pre-recorded. |
| 32–37 | Limitations + future | 12% | 7 | Honest: C++ only, 5-submitter minimum, email single-provider, `process` guard fix, pino migration. Future: more languages, PgBouncer, plagiarism cluster UI. |
| 37–40 | Contributions + close | 8% | 1 + 7 | 1 slide: who built what (all 7 named), repo + tag, "ready for pilot in one CCS section." Stop at 40. Invite Q&A. |

If given only 30 min: cut validation to 3 min and limitations to 2 min; never cut demo or architecture.

## Slide deck (12 slides max — panels hate walls of text)
1. Title (system name, team of 7, tag, date) 2. Problem + users 3. Objectives + scope IN/OUT 4. Architecture (light PNG, full-bleed) 5. Demo map (3 actions + accounts) 6. Student result (CDS pill + radar screenshot) 7. Instructor result (heatmap + alert screenshot) 8. CDS formula (see below) 9. Integrity + hidden tests 10. Validation (lint/build/tests table) 11. Limitations + future 12. Contributions + thank you / Q&A. Font ≥24pt, zoom screenshots to 125%.

## Demo script (rehearse 3× cold-start, ≤12 min)
**Pre-login (before panel enters):** instructor + maria tabs open, notifications off, zoom 125%.
**Action 1 — Student submits (Member 2, 4 min):** Login `maria@student.psu.edu / password123` → Today → "Sum Two Numbers" → paste correct C++ (sum `a+b`) → **Run** → show visible `2 3 → 5` pass, hidden stays `[Hidden]` → **Submit** → show all-pass + submission saved. Say: *"Run is practice on visible cases; Submit is official and graded on visible plus hidden."*
**Action 2 — Instructor closes + CDS (Member 3, 4 min):** Login `instructor@psu.edu / password123` → Sections → Close exercise → Progress/Heatmap → point to Maria's CDS pill + class heatmap. Say: *"Closing computes CDS for everyone; under 5 submitters it shows Unscored by design."*
**Action 3 — Integrity + report (Member 3, 3 min):** Alerts → show RETRY_STORM/CDS_HIGH or pasted-code flag → open one evidence drawer → Reports → Export CSV. Say: *"Every flag carries evidence; instructor reviews before any action."*
**Recovery line (Member 7, calm):** *"Live services sometimes sleep — switching to our recorded run of this exact build while I restart the API."* → play 3-min video → continue on screenshots. Never debug live.

## CDS — say it exactly (panel favorite)
`CDS = 0.40×NER + 0.35×NRS + 0.25×NTS`, each normalized p95-capped min-max: `(min(value,p95) − min)/(p95 − min)`, clamped [0,1], zero-variance → 0. NER = wrong submissions; NRS = total attempts; NTS = time vs limit. Post-solution cutoff (only work before first correct), flagged students excluded from class stats. Tiers: ≤0.20 Very Low … >0.80 High; <5 Unscored, 5–9 Prelim, 10+ Confident. Note: *low CDS = low struggle = mastering* (README wording is awkward — explain it before they ask).

## 22 anticipated questions (concise answer + evidence + owner)
1. **Why does this matter?** Instructors see failure too late. Evidence: heatmap screenshot. Owner: 1. Follow-up: pilot in one section.
2. **Who are the users?** Students/instructors/admins, role-gated routes. Evidence: `backend/routes/` (12) + protected routes. Owner: 1.
3. **CDS formula?** See CDS box above. Evidence: `services/cdsEngine.js` + live pill. Owner: 5.
4. **Why p95 cap?** Outliers (100 tries) would crush everyone else. Evidence: normalization code + zero-variance guard. Owner: 5.
5. **Why <5 = Unscored?** Statistically unstable. Evidence: close with 3 students → Unscored live. Owner: 5.
6. **Integrity accuracy / false positives?** Graduated Warning→Low→Full + evidence drawer + instructor review; never auto-penalize. Evidence: `lib/submissionPipeline.js`, `integrityFlags.js`. Owner: 5.
7. **Privacy/fairness?** Synthetic demo data, minimal collection, role checks, flagged students excluded from class stats. Owner: 6.
8. **Hidden tests leaked?** No — `/run` uses visible only, `/submit` grades all, UI shows `[Hidden]`. Evidence: `routes/student.js` + demo. Owner: 5.
9. **Run vs Submit?** Run = practice, not saved as official; Submit = persisted + triggers pipeline. Evidence: demo + `submissions` table. Owner: 2.
10. **Auth?** JWT (7-day, httpOnly+Secure+SameSite) + blacklist logout + bcrypt(10) + Google GIS + OTP. Evidence: `middleware/auth.js`, `docs/google-signin.md`. Owner: 6.
11. **Authorization?** `requireRole/requireAnyRole` on every route; student can't hit instructor APIs. Evidence: route files. Owner: 6.
12. **Sandbox safety?** Blocked syscalls (`system/fork/exec`), timeout, native g++ fallback when Docker absent (Cyclic), ASAN+cppcheck. Evidence: `services/executor.js`. Owner: 4.
13. **Why 30 tables?** 8 clusters (auth, sections, concepts, submissions, CDS, integrity, behavioral, eval). Evidence: `schema.sql` count + Lane 7 diagram. Owner: 4.
14. **Why Redis/BullMQ?** Async grading so Submit returns fast; sync fallback if Redis down; worker concurrency 3; DB-backed `cds_job_queue` with SKIP LOCKED. Owner: 4.
15. **What if queue/DB down?** `/api/ready` 503, graceful message, retry; autoClose via node-schedule every 5 min. Owner: 4.
16. **Performance?** Build 13.7s/3386 modules, deferred post-processing + exercise cache + compile limiter; benchmark via `tests/load/benchmark.js`. Don't invent ms numbers — show live. Owner: 4.
17. **Deployment?** Cyclic (backend) + Neon (Postgres) + Redis; Docker Compose locally; `render.yaml`/`cyclic.json` present. Owner: 4.
18. **Why Express+React+Postgres?** Team skill + relational integrity for grades + Monaco for C++. Trade-off: vendor-ui 442KB — code-split by role. Owner: 6.
19. **Email provider?** Brevo ACTIVE; nodemailer/resend installed but inactive (legacy). Say one story. Evidence: `lib/email.js`, architecture README. Owner: 6.
20. **Validation?** 905 backend + 99 frontend historical, lint 0 errors both sides, build green, 4 Playwright specs, ISO evaluation page. Re-run on frozen tag night before. Owner: 6.
21. **Lessons?** Unified sync/async pipeline killed duplicate flag bugs; hidden-test leak fix; outlier caps. Owner: 1.
22. **Contributions?** Name all 7 with one line each (e.g., CDS engine, executor sandbox, heatmap UI, auth, reports, QA/E2E, docs/video). No "all did all." Owner: 7.

## Night-before + day-of checklist
Night before: freeze tag, `npm ci`, build, run backend+frontend tests once, record counts, rotate demo keys, render fallback video, charge laptop + bring charger/HDMI/USB with PNG+PDF+video. Day of: arrive 30 min early, test projector at both resolutions, pre-login, disable sleep/updates/notifications, one driver laptop + one fallback laptop, water for speakers, printed 1-page role/account cheat sheet (never with real secrets).
