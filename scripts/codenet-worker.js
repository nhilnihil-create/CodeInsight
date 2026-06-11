#!/usr/bin/env node
/**
 * CodeNet Scanner Worker — runs a single batch in isolated process.
 * Usage: node scripts/codenet-worker.js <batch_file.json>
 * Output: JSON to stdout with { problem_id: [tags...] }
 */

const fs = require('fs');
const path = require('path');

const DATA_DIR = path.resolve(__dirname, '..', 'data', 'Project_CodeNet_C++1000');
const SAMPLE_PER_PROBLEM = 50;
const DEFAULT_THRESHOLD = 0.80;
const OOP_THRESHOLD = 0.10;

const CONCEPT_NODES = {
  'Datatypes': ['primitive_type', 'sized_type_specifier'],
  'Variables': ['declaration', 'init_declarator'],
  'Conditionals': ['if_statement', 'switch_statement', 'ternary_expression'],
  'Loops': ['for_statement', 'while_statement', 'do_statement'],
  'Functions': ['function_definition', 'call_expression'],
  'Arrays': ['array_declarator', 'subscript_expression', 'initializer_list'],
  'OOP': ['class_specifier', 'field_declaration', 'constructor_specifier'],
};

// Lazy parser
let parser = null;
function getParser() {
  if (!parser) {
    const Parser = require('tree-sitter');
    const CPP = require('tree-sitter-cpp');
    parser = new Parser();
    parser.setLanguage(CPP);
  }
  return parser;
}

function scanProblem(problemDir) {
  let cppFiles;
  try {
    cppFiles = fs.readdirSync(problemDir).filter(f => f.endsWith('.cpp'));
  } catch { return null; }

  const sample = cppFiles.sort(() => Math.random() - 0.5).slice(0, SAMPLE_PER_PROBLEM);
  const conceptCounts = {};
  for (const c of Object.keys(CONCEPT_NODES)) conceptCounts[c] = 0;
  let parsedFiles = 0;
  const p = getParser();

  for (const file of sample) {
    let sourceCode;
    try { sourceCode = fs.readFileSync(path.join(problemDir, file), 'utf8'); } catch { continue; }
    if (sourceCode.trim().length < 20) continue;

    let tree;
    try { tree = p.parse(sourceCode); } catch { continue; }
    if (tree.rootNode.hasError) continue;
    parsedFiles++;

    // Collect node types iteratively
    const nodeTypes = new Set();
    const stack = [tree.rootNode];
    while (stack.length > 0) {
      const node = stack.pop();
      nodeTypes.add(node.type);
      for (let i = node.childCount - 1; i >= 0; i--) {
        stack.push(node.child(i));
      }
    }

    for (const [concept, nodeNames] of Object.entries(CONCEPT_NODES)) {
      for (const n of nodeNames) {
        if (nodeTypes.has(n)) { conceptCounts[concept]++; break; }
      }
    }

    sourceCode = null;
  }

  return { parsedFiles: Math.max(parsedFiles, 1), conceptCounts };
}

// ── Main ─────────────────────────────────────────────────────────────────────

const batchFile = process.argv[2];
if (!batchFile) { process.stderr.write('Usage: node codenet-worker.js <batch_file>\n'); process.exit(1); }

const problemIds = JSON.parse(fs.readFileSync(batchFile, 'utf8'));
const results = {};

for (const pid of problemIds) {
  const result = scanProblem(path.join(DATA_DIR, pid));
  if (!result) { results[pid] = []; continue; }

  const tags = [];
  for (const [concept, count] of Object.entries(result.conceptCounts)) {
    const ratio = count / result.parsedFiles;
    const threshold = concept === 'OOP' ? OOP_THRESHOLD : DEFAULT_THRESHOLD;
    if (ratio >= threshold) tags.push(concept.toLowerCase());
  }
  results[pid] = tags;
}

process.stdout.write(JSON.stringify(results));
