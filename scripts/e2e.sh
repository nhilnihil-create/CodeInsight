#!/usr/bin/env bash
# scripts/e2e.sh — CodeInsight end-to-end demo artifact.
#
# Exercises the full student journey against a live backend and live
# database, asserting that real rows are written to behavioral_events
# and cds_scores. Intended to be runnable during a defense demo with
# zero manual intervention.
#
# Stages:
#   0   preflight         (tools + server + DB)
#   1   seed instructor    POST /api/auth/register
#   2   seed student       POST /api/auth/register
#   3   create section     POST /api/sections
#   4   enroll student     POST /api/sections/:id/enroll
#   5   create exercise    POST /api/exercises
#   6   submit code #1     POST /api/student/exercises/:id/submit
#   7   submit code #2     POST /api/student/exercises/:id/submit
#   8   close exercise     POST /api/exercises/:id/close
#   9   poll my-scores     GET  /api/analytics/my-scores
#   10  psql: behavioral_events  >= 10
#   10b hidden test leakage boundary check (PUT + /run + sentinel grep)
#   11  psql: cds_scores        >= 1
#   12  psql: classification    in {Low,Moderate,High,Unscored}
#   cleanup           DELETE users WHERE email LIKE 'e2e-%'
#
# Note: admin seeding is intentionally omitted. The live users table
# has CHECK (role IN ('instructor','student')), so admin registration
# via /api/auth/register returns 400 CHECK_VIOLATION. The admin role is
# documented as a v1.1 admin-provisioning gap; the demo path does not
# require an admin user. See DEFENSE_EVIDENCE.md.
#
# Usage:
#   bash scripts/e2e.sh              # full pass + cleanup
#   bash scripts/e2e.sh --keep       # leave seeded data
#   BASE_URL=http://host:5000 bash scripts/e2e.sh

set -euo pipefail

# ────────────────────────────────────────────────────────────────────────────
# Config
# ────────────────────────────────────────────────────────────────────────────
BASE_URL="${BASE_URL:-http://localhost:5000}"
RUN_ID="$(date +%s)"
EMAIL_PREFIX="e2e-${RUN_ID}"
PASSWORD="E2eTest12345!"
KEEP=0
USE_COLOR=1
[[ -t 1 ]] || USE_COLOR=0
for arg in "$@"; do
  case "$arg" in
    --keep)     KEEP=1 ;;
    --no-color) USE_COLOR=0 ;;
    -h|--help)
      sed -n '2,30p' "$0"; exit 0 ;;
    *)          echo "Unknown flag: $arg" >&2; exit 2 ;;
  esac
done

# Colors (only if TTY)
if [[ "$USE_COLOR" -eq 1 ]]; then
  C_OK=$'\e[32m'; C_BAD=$'\e[31m'; C_DIM=$'\e[2m'; C_RST=$'\e[0m'
else
  C_OK=''; C_BAD=''; C_DIM=''; C_RST=''
fi

STAGE_TIMES=()
STAGE_NAMES=()
STAGE_STATUS=()
START_NS=$(date +%s%N)

# ────────────────────────────────────────────────────────────────────────────
# Helpers
# ────────────────────────────────────────────────────────────────────────────
ok()       { printf '%s✓ %s%s\n' "$C_OK"  "$*" "$C_RST"; }
stage()    { STAGE_NAMES+=("$1"); printf '\n%s▶ %s%s\n' "$C_DIM" "$1" "$C_RST"; }
stamp()    { local end_ns; end_ns=$(date +%s%N); echo $(( (end_ns - START_NS) / 1000000 )); }

record_pass() { STAGE_STATUS+=("ok");  STAGE_TIMES+=("$(stamp)"); }
record_fail() { STAGE_STATUS+=("fail"); STAGE_TIMES+=("$(stamp)"); }

# Summary printer — defined before die() so it can be called from there.
summary() {
  local total_ms; total_ms=$(stamp)
  printf '\n%s┌─────────────────────────────────────────────────────────────┐%s\n' "$C_DIM" "$C_RST"
  printf  '%s│ E2E summary                                                 │%s\n' "$C_DIM" "$C_RST"
  printf  '%s├─────────────────────────────────────────────────────────────┤%s\n' "$C_DIM" "$C_RST"
  for i in "${!STAGE_NAMES[@]}"; do
    local status="${STAGE_STATUS[$i]:-?}"
    local ms="${STAGE_TIMES[$i]:-0}"
    local mark="?"
    [[ "$status" == "ok"   ]] && mark="${C_OK}✓${C_RST}"
    [[ "$status" == "fail" ]] && mark="${C_BAD}✗${C_RST}"
    printf '│ %s %-40s %5sms │\n' "$mark" "${STAGE_NAMES[$i]}" "$ms"
  done
  printf  '%s├─────────────────────────────────────────────────────────────┤%s\n' "$C_DIM" "$C_RST"
  printf  '│ %-50s %5sms │\n' "TOTAL" "$total_ms"
  printf  '%s└─────────────────────────────────────────────────────────────┘%s\n' "$C_DIM" "$C_RST"
}

die()      { printf '%s✗ %s%s\n' "$C_BAD" "$*" "$C_RST" >&2; summary; exit 1; }

# Check a command exists; die with install hint.
need() { command -v "$1" >/dev/null 2>&1 || die "Missing dependency: $1. Install with: apt-get install $2"; }

# curl wrapper: prints body to stdout, status to stderr-last-line; aborts on 5xx.
http() {
  local method="$1" path="$2" token="${3:-}" data="${4:-}"
  local args=(-sS -X "$method" -H 'Content-Type: application/json' -w '\n%{http_code}' "$BASE_URL$path")
  [[ -n "$token" ]] && args+=(-H "Authorization: Bearer $token")
  [[ -n "$data"  ]] && args+=(-d "$data")
  curl "${args[@]}"
}

# Issue a request, assert HTTP status, return body on stdout.
api_call() {
  local method="$1" path="$2" expected_status="$3" token="${4:-}" data="${5:-}"
  local raw body status
  raw=$(http "$method" "$path" "$token" "$data")
  status="${raw##*$'\n'}"
  body="${raw%$'\n'*}"
  if [[ "$status" != "$expected_status" ]]; then
    printf '%s\n' "$body" >&2
    die "$method $path: expected $expected_status, got $status"
  fi
  printf '%s' "$body"
}

# Pull a field from a flat JSON object via jq.
jq_get() { jq -r "$1" <<<"$2"; }

# ────────────────────────────────────────────────────────────────────────────
# Stage 0 — preflight
# ────────────────────────────────────────────────────────────────────────────
stage "Stage 0: preflight"
need bash     bash
need curl     curl
need jq       jq
need psql     postgresql-client

# Backend reachable?
status=$(curl -sS -o /dev/null -w '%{http_code}' "$BASE_URL/api/health" || true)
[[ "$status" == "200" ]] || die "Backend at $BASE_URL is not reachable (HTTP $status). Start it with: cd backend && npm run dev"
ok "Backend healthy at $BASE_URL"

# DB reachable? (read-only SELECT 1)
db_url_ok=$(PGPASSWORD="${DB_PASSWORD:-codepassword123}" \
  psql -h "${DB_HOST:-localhost}" -p "${DB_PORT:-5432}" \
       -U "${DB_USER:-codeuser}" -d "${DB_NAME:-codeinsight}" \
       -tAc "SELECT 1" 2>/dev/null || true)
[[ "$db_url_ok" == "1" ]] || die "PostgreSQL not reachable with default creds (DB_USER=codeuser DB_PASSWORD=codepassword123). Set DB_HOST/DB_PORT/DB_USER/DB_PASSWORD/DB_NAME env vars."
ok "PostgreSQL reachable"

# Required columns present? (catches drifted DB schemas.)
required_cols=("sections.code" "sections.join_policy")
for col in "${required_cols[@]}"; do
  tbl="${col%.*}"; name="${col#*.}"
  has=$(PGPASSWORD="${DB_PASSWORD:-codepassword123}" \
    psql -h "${DB_HOST:-localhost}" -p "${DB_PORT:-5432}" \
         -U "${DB_USER:-codeuser}" -d "${DB_NAME:-codeinsight}" \
         -tAc "SELECT 1 FROM information_schema.columns WHERE table_name='${tbl}' AND column_name='${name}'" 2>/dev/null || true)
  [[ "$has" == "1" ]] || die "Schema drift: ${tbl}.${name} is missing. As a superuser, run: psql -U postgres -d ${DB_NAME:-codeinsight} -c 'ALTER TABLE ${tbl} ADD COLUMN IF NOT EXISTS ${name} TEXT;' (see backend/migrations/008-update-sections.sql)"
done
# Required tables present? (catches drifted DB schemas.)
required_tables=("section_memberships" "section_audit_log" "behavioral_events" "cds_scores")
for tbl in "${required_tables[@]}"; do
  has=$(PGPASSWORD="${DB_PASSWORD:-codepassword123}" \
    psql -h "${DB_HOST:-localhost}" -p "${DB_PORT:-5432}" \
         -U "${DB_USER:-codeuser}" -d "${DB_NAME:-codeinsight}" \
         -tAc "SELECT 1 FROM information_schema.tables WHERE table_name='${tbl}'" 2>/dev/null || true)
  [[ "$has" == "1" ]] || die "Schema drift: ${tbl} table is missing. Restart the backend so migrations.js can create it."
done
ok "schema columns present"

record_pass

# ────────────────────────────────────────────────────────────────────────────
# Stage 1-3 — seed users
# ────────────────────────────────────────────────────────────────────────────
INSTR_EMAIL="${EMAIL_PREFIX}-inst@codeinsight.test"
STUD_EMAIL="${EMAIL_PREFIX}-stud@codeinsight.test"

register_or_login() {
  local email="$1" name="$2" role="$3"
  local body resp token user
  body=$(jq -nc --arg n "$name" --arg e "$email" --arg p "$PASSWORD" --arg r "$role" \
    '{name:$n, email:$e, password:$p, role:$r}')
  resp=$(http POST /api/auth/register '' "$body")
  local status="${resp##*$'\n'}"
  if [[ "$status" == "201" ]]; then
    token=$(jq -r '.token' <<<"${resp%$'\n'*}")
  elif [[ "$status" == "409" ]]; then
    resp=$(http POST /api/auth/login '' "$(jq -nc --arg e "$email" --arg p "$PASSWORD" '{email:$e, password:$p}')")
    token=$(jq -r '.token' <<<"${resp%$'\n'*}")
  else
    printf '%s\n' "${resp%$'\n'*}" >&2
    die "Register $email: expected 201/409, got $status"
  fi
  printf '%s' "$token"
}

stage "Stage 1: seed instructor"
INSTR_TOKEN=$(register_or_login "$INSTR_EMAIL" "E2E Instructor" "instructor")
[[ -n "$INSTR_TOKEN" && "$INSTR_TOKEN" != "null" ]] || die "Instructor token empty"
ok "instructor token acquired"

record_pass

stage "Stage 2: seed student"
STUD_TOKEN=$(register_or_login "$STUD_EMAIL" "E2E Student" "student")
STUD_USER_ID=$(api_call GET /api/auth/me 200 "$STUD_TOKEN" | jq -r '.id')
[[ -n "$STUD_USER_ID" && "$STUD_USER_ID" != "null" ]] || die "Student id empty"
ok "student token acquired (id=$STUD_USER_ID)"

record_pass

# ────────────────────────────────────────────────────────────────────────────
# Stage 4 — create section
# ────────────────────────────────────────────────────────────────────────────
stage "Stage 3: create section"
section_body=$(jq -nc --arg n "E2E-${RUN_ID}" '{name:$n, course_code:"E2E-101"}')
section_resp=$(api_call POST /api/sections 201 "$INSTR_TOKEN" "$section_body")
SECTION_ID=$(jq -r '.id' <<<"$section_resp")
[[ -n "$SECTION_ID" && "$SECTION_ID" != "null" ]] || die "Section id empty"
ok "section created (id=$SECTION_ID, code=$(jq -r '.code' <<<"$section_resp"))"

record_pass

# ────────────────────────────────────────────────────────────────────────────
# Stage 5 — enroll student (via email — controller expects emails[] or
# student_ids[], but the validator strips unknown keys, so we use emails)
# ────────────────────────────────────────────────────────────────────────────
stage "Stage 4: enroll student"
enroll_body=$(jq -nc --arg e "$STUD_EMAIL" '{emails:[$e]}')
enroll_resp=$(api_call POST "/api/sections/${SECTION_ID}/enroll" 200 "$INSTR_TOKEN" "$enroll_body")
ok "$(jq -r '.message' <<<"$enroll_resp")"

record_pass

# ────────────────────────────────────────────────────────────────────────────
# Stage 6 — create exercise (1 visible + 1 hidden test, min 2 required)
# ────────────────────────────────────────────────────────────────────────────
stage "Stage 5: create exercise"
ex_body=$(jq -nc --arg sid "$SECTION_ID" '{
  title: "E2E Sum of Two",
  description: "Return a + b",
  concept_name: "Variables",
  section_id: ($sid|tonumber),
  time_limit_minutes: 5,
  track_ner: true,
  track_nrs: true,
  track_nts: true,
  auto_alert: true,
  is_draft: false,
  test_cases: [
    {input:"1 2", expected:"3", description:"basic", hidden:false},
    {input:"10 20", expected:"30", description:"edge", hidden:true}
  ]
}')
ex_resp=$(api_call POST /api/exercises 201 "$INSTR_TOKEN" "$ex_body")
EXERCISE_ID=$(jq -r '.id' <<<"$ex_resp")
[[ -n "$EXERCISE_ID" && "$EXERCISE_ID" != "null" ]] || die "Exercise id empty"
ok "exercise created (id=$EXERCISE_ID)"

record_pass

# ────────────────────────────────────────────────────────────────────────────
# Stages 7-8 — submit code (twice, with 5 behavioral events each)
# ────────────────────────────────────────────────────────────────────────────
submit_once() {
  local attempt="$1"
  local ts_before ts_after ts_idle ts_paste ts_burst ts_focus ts_blur
  ts_before=$(date -u -d "5 seconds ago"  +%Y-%m-%dT%H:%M:%S.000Z)
  ts_after=$(date -u                    +%Y-%m-%dT%H:%M:%S.000Z)
  ts_focus=$(date -u -d "8 seconds ago"  +%Y-%m-%dT%H:%M:%S.000Z)
  ts_burst=$(date -u -d "6 seconds ago"  +%Y-%m-%dT%H:%M:%S.000Z)
  ts_paste=$(date -u -d "4 seconds ago"  +%Y-%m-%dT%H:%M:%S.000Z)
  ts_idle=$(date -u  -d "2 seconds ago"  +%Y-%m-%dT%H:%M:%S.000Z)
  ts_blur=$(date -u                     +%Y-%m-%dT%H:%M:%S.000Z)

  local body
  body=$(jq -nc --arg ts1 "$ts_focus" --arg ts2 "$ts_burst" --arg ts3 "$ts_paste" \
                   --arg ts4 "$ts_idle" --arg ts5 "$ts_blur" --argjson sp 60 '
  {
    code: "def add(a,b):\n  return a + b\nprint(add(1, 2))\n",
    timeSpentSeconds: 60,
    behavioralEvents: [
      {type:"tab_focus",      timestamp:$ts1, payload:{}},
      {type:"keystroke_burst",timestamp:$ts2, payload:{count:15, windowMs:1500}},
      {type:"paste",          timestamp:$ts3, payload:{length:$sp}},
      {type:"idle_start",     timestamp:$ts4, payload:{}},
      {type:"tab_blur",       timestamp:$ts5, payload:{}}
    ]
  }')
  api_call POST "/api/student/exercises/${EXERCISE_ID}/submit" 201 "$STUD_TOKEN" "$body"
}

stage "Stage 6: submit code (attempt 1)"
sub1=$(submit_once 1)
attempt1=$(jq -r '.attempt_number' <<<"$sub1")
live_cds=$(jq -r '.liveCDS.cds // .liveCDS' <<<"$sub1")
ok "attempt_number=$attempt1, liveCDS=$live_cds, hiddenTestCount=$(jq -r '.hiddenTestCount' <<<"$sub1")"

stage "Stage 7: submit code (attempt 2)"
sub2=$(submit_once 2)
attempt2=$(jq -r '.attempt_number' <<<"$sub2")
[[ "$attempt2" == "2" ]] || die "expected attempt_number=2, got $attempt2"
ok "attempt_number=$attempt2"

record_pass

# ────────────────────────────────────────────────────────────────────────────
# Stage 9 — close exercise (triggers batch CDS via cdsJobQueue)
# ────────────────────────────────────────────────────────────────────────────
stage "Stage 8: close exercise"
close_resp=$(api_call POST "/api/exercises/${EXERCISE_ID}/close" 200 "$INSTR_TOKEN" '')
ok "$(jq -r '.message' <<<"$close_resp")"

record_pass

# ────────────────────────────────────────────────────────────────────────────
# Stage 10 — poll my-scores until non-empty (or 10s)
# ────────────────────────────────────────────────────────────────────────────
stage "Stage 9: poll /api/analytics/my-scores"
scores=""
for i in 1 2 3 4 5 6 7 8 9 10; do
  resp=$(api_call GET /api/analytics/my-scores 200 "$STUD_TOKEN")
  if [[ "$(jq 'length' <<<"$resp")" -gt 0 ]]; then
    scores="$resp"
    ok "scores appeared after ${i}s ($(jq 'length' <<<"$resp") rows)"
    break
  fi
  sleep 1
done
[[ -n "$scores" ]] || die "no scores appeared within 10s after close"

record_pass

# ────────────────────────────────────────────────────────────────────────────
# Stages 11-13 — psql assertions
# ────────────────────────────────────────────────────────────────────────────
psql_q() {
  PGPASSWORD="${DB_PASSWORD:-codepassword123}" \
    psql -h "${DB_HOST:-localhost}" -p "${DB_PORT:-5432}" \
         -U "${DB_USER:-codeuser}" -d "${DB_NAME:-codeinsight}" \
         -tAc "$1" 2>/dev/null
}

stage "Stage 10: psql — behavioral_events count"
ev_count=$(psql_q "SELECT COUNT(*) FROM behavioral_events WHERE student_id = $STUD_USER_ID")
[[ "$ev_count" -ge 10 ]] || die "expected >=10 behavioral_events for student $STUD_USER_ID, got $ev_count"
ok "$ev_count behavioral_events rows for student $STUD_USER_ID"

record_pass

# Lightweight hidden-test leakage boundary check.
# Hits the actual student-facing run endpoint with a sentinel hidden
# input/expected pair and asserts the response body does NOT contain
# the sentinel. Per task constraint: lightweight, no infra changes.
stage "Stage 10b: hidden test leakage — student /run endpoint"
SENTINEL_INPUT="__LEAK_SENTINEL_INPUT_$(date +%s)__"
SENTINEL_EXPECTED="__LEAK_SENTINEL_OUTPUT_$(date +%s)__"
# Add a hidden test case to the just-created exercise (idempotent for
# this e2e session: append one more, hidden=true).
hidden_body=$(jq -nc --arg si "$SENTINEL_INPUT" --arg se "$SENTINEL_EXPECTED" --argjson sid "$EXERCISE_ID" '{
  test_cases: [
    {input:"1 2", expected:"3", description:"visible basic", hidden:false},
    {input:"10 20", expected:"30", description:"visible edge", hidden:false},
    {input: $si, expected: $se, description:"hidden sentinel", hidden: true}
  ]
}')
# Reuse the put endpoint to add hidden test (need to be instructor).
put_resp=$(http PUT "/api/exercises/${EXERCISE_ID}" "$INSTR_TOKEN" "$hidden_body")
put_status="${put_resp##*$'\n'}"
[[ "$put_status" == "200" ]] || die "PUT /api/exercises/${EXERCISE_ID} (add hidden): expected 200, got $put_status"

# Student calls /run — only visible tests should appear in response.
run_body=$(api_call POST "/api/student/exercises/${EXERCISE_ID}/run" 200 "$STUD_TOKEN" '{"code":"#include <iostream>\nusing namespace std;\nint main(){int a,b;cin>>a>>b;cout<<(a+b);return 0;}"}')
# Assert neither sentinel appears anywhere in the body.
if printf '%s' "$run_body" | grep -q "$SENTINEL_INPUT"; then
  die "LEAK: hidden test input sentinel '$SENTINEL_INPUT' appeared in /run response body"
fi
if printf '%s' "$run_body" | grep -q "$SENTINEL_EXPECTED"; then
  die "LEAK: hidden test expected sentinel '$SENTINEL_EXPECTED' appeared in /run response body"
fi
ok "no leak: neither sentinel in /run response (hidden filter verified at HTTP boundary)"

record_pass

stage "Stage 11: psql — cds_scores count"
cs_count=$(psql_q "SELECT COUNT(*) FROM cds_scores WHERE student_id = $STUD_USER_ID")
[[ "$cs_count" -ge 1 ]] || die "expected >=1 cds_scores for student $STUD_USER_ID, got $cs_count"
ok "$cs_count cds_scores rows for student $STUD_USER_ID"

record_pass

stage "Stage 12: psql — classification enum"
classification=$(psql_q "SELECT classification FROM cds_scores WHERE student_id = $STUD_USER_ID ORDER BY computed_at DESC LIMIT 1")
case "$classification" in
  Low|Moderate|High|Unscored) ok "classification=$classification" ;;
  *) die "unexpected classification: $classification" ;;
esac

record_pass

record_pass

# ────────────────────────────────────────────────────────────────────────────
# Cleanup
# ────────────────────────────────────────────────────────────────────────────
cleanup() {
  if [[ "$KEEP" -eq 1 ]]; then
    printf '\n%s--keep: leaving data. To inspect:%s\n' "$C_DIM" "$C_RST"
    printf '  PGPASSWORD=%s psql -h %s -U %s -d %s -c "SELECT id,email,role FROM users WHERE email LIKE '\''%s%%'\''"\n' \
      "${DB_PASSWORD:-codepassword123}" "${DB_HOST:-localhost}" "${DB_USER:-codeuser}" "${DB_NAME:-codeinsight}" "$EMAIL_PREFIX"
    return
  fi
  printf '\n%scleanup: removing seeded users…%s\n' "$C_DIM" "$C_RST"
  psql_q "DELETE FROM users WHERE email LIKE '${EMAIL_PREFIX}%'" >/dev/null || true
  ok "cleanup complete"
}
trap cleanup EXIT

summary
printf '\n%s✓ ALL STAGES PASSED%s\n' "$C_OK" "$C_RST"
exit 0
