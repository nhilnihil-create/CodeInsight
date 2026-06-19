#!/bin/bash
set -e

echo "========================================"
echo "  WORKFLOW SIMULATION TEST RUNNER"
echo "  15 Students x 3 Exercises x 70 Steps"
echo "========================================"
echo ""

# Check if backend and frontend are running
echo "Checking services..."
if ! curl -s http://localhost:5000/api/health > /dev/null 2>&1; then
  echo "Backend not running! Start with: cd backend && npm run dev"
  exit 1
fi
echo "  Backend: OK (port 5000)"

if ! curl -s http://localhost:5173 > /dev/null 2>&1; then
  echo "Frontend not running! Start with: cd frontend && npm run dev"
  exit 1
fi
echo "  Frontend: OK (port 5173)"
echo ""

# Step 1: Seed data
echo "=== STEP 1: Seeding test data ==="
node seed-data.js
echo ""

# Step 2: Run student workflow tests (headed)
echo "=== STEP 2: Student Workflow Tests (15 personas) ==="
npx playwright test student-flow.spec.js --headed --reporter=line
echo ""

# Step 3: Run instructor workflow tests (headed)
echo "=== STEP 3: Instructor Workflow Tests (70 steps) ==="
npx playwright test instructor-flow.spec.js --headed --reporter=line
echo ""

# Step 4: Database verification
echo "=== STEP 4: Database Verification ==="
node -e "
  const { runFullVerification, close } = require('./helpers/db-verifier');
  const fs = require('fs');
  const state = JSON.parse(fs.readFileSync('./seed-state.json'));
  runFullVerification(state.sectionId, 15).then(r => {
    close();
    process.exit(r.allPassed ? 0 : 1);
  });
"
echo ""

# Step 5: Print spec checker summary
echo "=== STEP 5: Spec Checker Summary ==="
node -e "
  const { printSummary } = require('./spec-checker');
  printSummary();
"
echo ""
echo "========================================"
echo "  SIMULATION COMPLETE"
echo "  Screenshots saved to: screenshots/"
echo "========================================"
