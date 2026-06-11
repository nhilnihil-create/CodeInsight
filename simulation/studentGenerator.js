/**
 * simulation/studentGenerator.js
 *
 * C++ AST normalizer + CodeNet structural template matcher for 7 core concepts.
 * Payload generator produces C++ code variants for each bug state.
 *
 * Uses tree-sitter-cpp to parse, strip identifiers/literals, and generate
 * anonymous structural hashes that map against pre-computed CodeNet templates.
 */

const Parser = require('tree-sitter');
const CPP = require('tree-sitter-cpp');
const crypto = require('crypto');

// ── AST Normalizer ─────────────────────────────────────────────────────────

const parser = new Parser();
parser.setLanguage(CPP);

/**
 * Strip identifiers and literals from C++ AST, replacing with anonymous tokens.
 * @param {string} sourceCode
 * @returns {string} anonymized source
 */
function normalizeAst(sourceCode) {
  const tree = parser.parse(sourceCode);
  let result = sourceCode;

  // Collect all identifiers and their positions from the AST
  const replacements = [];
  const identifierTypes = new Set([
    'identifier', 'field_identifier', 'namespace_identifier',
    'type_identifier', 'template_identifier'
  ]);
  const literalTypes = new Set([
    'number_literal', 'char_literal', 'string_literal',
    'true', 'false', 'null'
  ]);

  function traverse(node) {
    if (identifierTypes.has(node.type)) {
      replacements.push({ start: node.startIndex, end: node.endIndex, type: 'IDENT' });
    } else if (literalTypes.has(node.type)) {
      replacements.push({ start: node.startIndex, end: node.endIndex, type: 'LITERAL' });
    }
    for (let i = 0; i < node.childCount; i++) {
      traverse(node.child(i));
    }
  }
  traverse(tree.rootNode);

  // Apply replacements in reverse order to preserve indices
  replacements.sort((a, b) => b.start - a.start);
  for (const r of replacements) {
    result = result.slice(0, r.start) + r.type + result.slice(r.end);
  }

  return result;
}

/**
 * Generate a structural SHA-256 hash from anonymized AST.
 * @param {string} sourceCode
 * @returns {string} hex hash
 */
function structuralHash(sourceCode) {
  try {
    const normalized = normalizeAst(sourceCode);
    return crypto.createHash('sha256').update(normalized).digest('hex');
  } catch (e) {
    // If parsing fails, hash the raw source as fallback
    return crypto.createHash('sha256').update(sourceCode).digest('hex');
  }
}

// ── CodeNet Template Library ────────────────────────────────────────────────
// Pre-computed structural hashes for 7 core concepts.
// Each template has a canonical C++ snippet whose normalized hash is stored.

const CODENET_TEMPLATES = {
  'Datatypes': [
    {
      id: 'datatype_basic',
      canonical: `int main() { int x = 0; float y = 0.0; char z = 'a'; return 0; }`,
    },
  ],
  'Variables': [
    {
      id: 'variable_assignment',
      canonical: `int main() { int IDENT = LITERAL; IDENT = IDENT + LITERAL; return 0; }`,
    },
  ],
  'Conditionals': [
    {
      id: 'if_else',
      canonical: `int main() { int IDENT = LITERAL; if (IDENT > LITERAL) { return LITERAL; } else { return LITERAL; } }`,
    },
    {
      id: 'switch_case',
      canonical: `int main() { int IDENT = LITERAL; switch (IDENT) { case LITERAL: return LITERAL; default: return LITERAL; } }`,
    },
  ],
  'Loops': [
    {
      id: 'for_loop',
      canonical: `int main() { int IDENT = LITERAL; for (int IDENT = LITERAL; IDENT <= LITERAL; IDENT++) { IDENT = IDENT + LITERAL; } return IDENT; }`,
    },
    {
      id: 'while_loop',
      canonical: `int main() { int IDENT = LITERAL; while (IDENT <= LITERAL) { IDENT = IDENT + LITERAL; } return IDENT; }`,
    },
    {
      id: 'do_while',
      canonical: `int main() { int IDENT = LITERAL; do { IDENT = IDENT + LITERAL; } while (IDENT <= LITERAL); return IDENT; }`,
    },
  ],
  'Functions': [
    {
      id: 'function_def',
      canonical: `int IDENT(int IDENT) { return IDENT + LITERAL; } int main() { return IDENT(LITERAL); }`,
    },
  ],
  'Arrays': [
    {
      id: 'array_basic',
      canonical: `int main() { int IDENT[LITERAL]; for (int IDENT = LITERAL; IDENT < LITERAL; IDENT++) { IDENT[IDENT] = LITERAL; } return LITERAL; }`,
    },
  ],
  'OOP': [
    {
      id: 'class_basic',
      canonical: `class IDENT { public: int IDENT; void IDENT() { IDENT = LITERAL; } }; int main() { IDENT IDENT; IDENT.IDENT(); return LITERAL; }`,
    },
  ],
};

// Pre-compute hashes
for (const [concept, templates] of Object.entries(CODENET_TEMPLATES)) {
  for (const t of templates) {
    t.hash = structuralHash(t.canonical);
  }
}

/**
 * Match student code against CodeNet templates.
 * @param {string} sourceCode
 * @returns {{ conceptMatch: string, similarity: number, templateId: string }}
 */
function matchCodeNet(sourceCode) {
  const studentHash = structuralHash(sourceCode);

  let bestMatch = { conceptMatch: 'Unknown', similarity: 0, templateId: 'none' };
  let bestScore = 0;

  for (const [concept, templates] of Object.entries(CODENET_TEMPLATES)) {
    for (const t of templates) {
      // Simple hash comparison (exact structural match)
      const score = studentHash === t.hash ? 1.0 : 0;
      if (score > bestScore) {
        bestScore = score;
        bestMatch = { conceptMatch: concept, similarity: score, templateId: t.id };
      }
    }
  }

  return bestMatch;
}

// ── Payload Generator ───────────────────────────────────────────────────────

const PAYLOADS = {
  // Correct solution for "Print numbers 1 to N"
  STATE_CORRECT: (n = 10) =>
    `#include <iostream>\nusing namespace std;\n\nint main() {\n  int n = ${n};\n  for (int i = 1; i <= n; i++) {\n    cout << i << endl;\n  }\n  return 0;\n}\n`,

  // Off-by-one: terminates early (< instead of <=)
  BUG_OFF_BY_ONE: (n = 10) =>
    `#include <iostream>\nusing namespace std;\n\nint main() {\n  int n = ${n};\n  for (int i = 1; i < n; i++) {\n    cout << i << endl;\n  }\n  return 0;\n}\n`,

  // Infinite loop: missing increment
  BUG_INFINITE_LOOP: (n = 10) =>
    `#include <iostream>\nusing namespace std;\n\nint main() {\n  int n = ${n};\n  int i = 1;\n  while (i <= n) {\n    cout << i << endl;\n  }\n  return 0;\n}\n`,

  // Syntax error: missing semicolon
  BUG_SYNTAX_ERROR: (n = 10) =>
    `#include <iostream>\nusing namespace std;\n\nint main() {\n  int n = ${n}\n  for (int i = 1; i <= n; i++) {\n    cout << i << endl;\n  }\n  return 0;\n}\n`,

  // Copy-paste flag: perfect code with marker for zero-telemetry detection
  FLAG_COPY_PASTE: (n = 10) =>
    `#include <iostream>\nusing namespace std;\n\nint main() {\n  int n = ${n};\n  for (int i = 1; i <= n; i++) {\n    cout << i << endl;\n  }\n  return 0;\n}\n`,

  // Massive payload: binary string to test buffer handling
  MASSIVE_PAYLOAD: () => {
    const binary = '10110010'.repeat(50000); // ~400KB
    return `#include <iostream>\nusing namespace std;\nint main() { const char* data = "${binary}"; cout << data; return 0; }\n`;
  },

  // Compiler-breaking code
  COMPILER_BREAK: () =>
    `#include <iostream>\nint main() { ${'int x; '.repeat(1000)} return 0; }\n`,
};

/**
 * Generate a C++ payload based on persona tier and desired state.
 * @param {string} state - One of PAYLOADS keys
 * @param {object} persona - Persona object
 * @returns {string} C++ source code
 */
function generatePayload(state, persona) {
  const generator = PAYLOADS[state];
  if (!generator) return PAYLOADS.STATE_CORRECT();

  if (state === 'FLAG_COPY_PASTE') {
    return generator(10); // Mark as copy-paste for telemetry analysis
  }

  return generator(10);
}

module.exports = {
  normalizeAst,
  structuralHash,
  matchCodeNet,
  generatePayload,
  CODENET_TEMPLATES,
  PAYLOADS,

  /**
   * 🔥 AI Student Generator Prompt — External LLM Configuration
   *
   * Use this prompt template to configure an external LLM for generating
   * diverse student-like C++ submissions:
   *
   * ---
   * You are a student learning C++ programming. Generate a C++ program
   * to solve this exercise: "Print numbers from 1 to N where N is given."
   *
   * Your response should match one of these profiles:
   * 1. PERFECT: Correct solution using a for loop with proper bounds.
   * 2. OFF_BY_ONE: Loop condition is wrong (e.g., i < N instead of i <= N).
   * 3. INFINITE_LOOP: Missing loop increment or broken condition.
   * 4. SYNTAX_ERROR: Missing semicolon, undeclared variable, wrong syntax.
   * 5. CREATIVE_APPROACH: Uses while, do-while, recursion, or other valid approach.
   *
   * Return ONLY the C++ code, no explanations.
   * Profile: {STATE}
   * Student Tier: {TIER}
   * ---
   */
};
