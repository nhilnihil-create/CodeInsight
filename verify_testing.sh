#!/bin/bash
# Verification script after closing the "Sum 1 to N" exercise

EXERCISE_ID=6
echo "=========================================="
echo "CodeInsight Testing Verification"
echo "=========================================="
echo ""

PGPASSWORD=codepassword123 psql -h localhost -U codeuser -d codeinsight << 'EOF'
-- Submission Statistics
echo "1️⃣  SUBMISSION STATISTICS"
echo "================================"
SELECT
  u.name as student,
  u.email,
  COUNT(*) as total_attempts,
  SUM(CASE WHEN s.passed THEN 1 ELSE 0 END) as tests_passed,
  ROUND(100.0 * SUM(CASE WHEN s.passed THEN 1 ELSE 0 END) / COUNT(*), 1) as pass_rate,
  COUNT(DISTINCT CASE WHEN s.is_verified = false THEN 1 END) as failed_verification_count
FROM submissions s
JOIN users u ON s.student_id = u.id
WHERE s.exercise_id = 6
GROUP BY u.id, u.name, u.email
ORDER BY u.id;

echo ""
echo "2️⃣  CDS SCORES (After Exercise Close)"
echo "================================"
SELECT
  u.name as student,
  u.email,
  ROUND(cs.ner::numeric, 4) as NER,
  ROUND(cs.nrs::numeric, 4) as NRS,
  ROUND(cs.nts::numeric, 4) as NTS,
  ROUND(cs.cds::numeric, 4) as CDS,
  cs.classification
FROM cds_scores cs
JOIN users u ON cs.student_id = u.id
WHERE cs.exercise_id = 6
ORDER BY cs.cds DESC;

echo ""
echo "3️⃣  ALERTS GENERATED"
echo "================================"
SELECT
  u.name as student,
  u.email,
  ROUND(a.cds_score::numeric, 4) as cds_score,
  a.classification,
  c.name as concept,
  a.is_reviewed,
  a.created_at
FROM alerts a
JOIN users u ON a.student_id = u.id
JOIN concepts c ON a.exercise_id = (SELECT id FROM exercises WHERE id = 6)
WHERE a.exercise_id = 6
ORDER BY a.cds_score DESC;

echo ""
echo "4️⃣  AST VERIFICATION FAILURES"
echo "================================"
SELECT
  u.name as student,
  u.email,
  COUNT(*) as verification_failures,
  STRING_AGG(DISTINCT vl.reason, '; ') as reasons
FROM verification_logs vl
JOIN users u ON vl.student_id = u.id
WHERE vl.exercise_id = 6
GROUP BY u.id, u.name, u.email
ORDER BY u.id;

echo ""
echo "5️⃣  SUBMISSION DETAILS (For Debugging)"
echo "================================"
SELECT
  u.name,
  u.email,
  s.attempt_number,
  s.passed,
  s.is_verified,
  LEFT(s.verification_note, 100) as verification_note,
  s.time_spent_seconds,
  LENGTH(s.code) as code_length,
  s.created_at
FROM submissions s
JOIN users u ON s.student_id = u.id
WHERE s.exercise_id = 6
ORDER BY u.id, s.attempt_number;

EOF

echo ""
echo "=========================================="
echo "✅ Verification Complete!"
echo "=========================================="
