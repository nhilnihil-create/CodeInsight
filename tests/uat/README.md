# User Acceptance Testing (UAT)

## Purpose
UAT validates that the system meets **business requirements** and is **usable in real-world scenarios**. Unlike E2E tests (which ask "does it work?"), UAT asks "is this the right system for the user?"

## Personas

| Persona | Role | Primary Goals |
|---------|------|---------------|
| Dr. Chen | Instructor | Monitor student progress, identify at-risk students, provide targeted feedback |
| Maria | Student (struggling) | Complete exercises, understand mistakes, improve coding skills |
| Alex | Student (advanced) | Move quickly through material, challenge self |
| Admin Lee | Administrator | System oversight, audit integrity, manage users |

## UAT Checklist

### Instructor Workflows
- [ ] Create a section with a unique join code
- [ ] View real-time student progress dashboard
- [ ] Identify high-CDS (struggling) students at a glance
- [ ] Review integrity flags with context
- [ ] Dismiss false-positive flags with a note
- [ ] Export class performance report
- [ ] Close an exercise and trigger automated CDS computation
- [ ] Receive notification when CDS computation completes

### Student Workflows
- [ ] Join a section using a 7-character join code
- [ ] See enrolled sections on the dashboard
- [ ] Open an exercise with starter code
- [ ] Write and submit C++ code
- [ ] See test results (pass/fail) for visible test cases
- [ ] See only masked output for hidden test cases
- [ ] View CDS score and classification after exercise closes
- [ ] Practice mode: submit unlimited attempts without affecting CDS

### Administrator Workflows
- [ ] View system-wide evaluation queue
- [ ] Audit integrity flags across all sections
- [ ] Monitor system health metrics
- [ ] Manage user accounts (create, suspend, delete)

## Running UAT

```bash
# Run the full UAT suite
node tests/uat/runner.js

# Run a specific persona workflow
node tests/uat/runner.js --persona instructor
```
