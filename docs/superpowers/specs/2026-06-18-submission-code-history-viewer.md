# Submission Code History Viewer

**Date**: 2026-06-18
**Status**: Approved

## Overview

Replace the integrity-flag-only Submissions tab in the instructor section detail page with a full submission browser that shows all student submissions and allows instructors to click through to view the code history (run attempts + final submission) with compiler logs.

## Backend API

### `GET /api/analytics/sections/:sectionId/submissions`

Returns all submissions for a section with `code` and `compiler_log`.

**Query params**: `search` (student name), `exerciseId`, `status` (pass/fail/all)

**Response**:
```json
{
  "submissions": [
    {
      "id": 1,
      "student_id": 1,
      "student_name": "Maria Student",
      "student_email": "maria@...",
      "exercise_id": 1,
      "exercise_title": "Sum 1 to N",
      "concept_name": "Loops",
      "attempt_number": 1,
      "is_correct": false,
      "code": "#include <iostream>...",
      "compiler_log": "[Line 5:5] ERROR: ...",
      "submitted_at": "2026-06-18T12:00:00Z",
      "time_spent_seconds": 120,
      "flag_count": 0
    }
  ]
}
```

### `GET /api/analytics/submissions/:submissionId/runs`

Returns all run attempts for the same student+exercise, plus the final submission.

**Response**:
```json
{
  "runs": [
    {
      "id": 1,
      "code": "#include <iostream>...",
      "compiler_log": "[Line 5:5] ERROR: ...",
      "error_count": 1,
      "time_limit_hit": false,
      "run_at": "2026-06-18T11:55:00Z",
      "is_submission": false
    },
    {
      "id": 2,
      "code": "#include <iostream>...",
      "compiler_log": null,
      "error_count": 0,
      "time_limit_hit": false,
      "run_at": "2026-06-18T11:58:00Z",
      "is_submission": false
    },
    {
      "id": 45,
      "code": "#include <iostream>...",
      "compiler_log": null,
      "error_count": 0,
      "time_limit_hit": false,
      "run_at": "2026-06-18T12:00:00Z",
      "is_submission": true
    }
  ]
}
```

## Frontend Components

### SubmissionsTab (rewrite)

All-submissions table with:
- Columns: Student, Exercise, Attempt, Status, Submitted, Flags
- Search input (client-side filter by student name)
- Exercise filter dropdown (populated from section exercises)
- Status tabs: All / Pass / Fail
- Rows clickable → opens SubmissionDetailDrawer
- Preserved "Flagged" filter toggle from current tab

### SubmissionDetailDrawer (new)

shadcn `Sheet` (right slide-over) containing:
- Header: student name, email, exercise title, pass/fail badge
- Run history timeline (vertical, each attempt clickable)
- Read-only Monaco editor (code at selected attempt)
- Compiler log panel (visible when selected attempt has compiler_log)

## Files to Create/Modify

| File | Action |
|---|---|
| `backend/routes/analytics.js` | Add 2 new routes |
| `backend/controllers/analyticsController.js` | Add `getSectionSubmissions` + `getSubmissionRuns` |
| `frontend/src/pages/instructor/tabs/SubmissionsTab.jsx` | Rewrite |
| `frontend/src/components/analytics/SubmissionDetailDrawer.jsx` | Create |

## Out of Scope

- Rubric/grading by instructors
- CDS scores in the drawer
- Editing/regrading submissions
- Export functionality for the submission list
