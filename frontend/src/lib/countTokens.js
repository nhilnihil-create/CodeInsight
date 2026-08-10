// frontend/src/lib/countTokens.js
// Client-side mirror of the backend tokenizer used for growth-velocity
// monitoring (backend/controllers/submissionController.js). Must stay
// verbatim-in-sync with the server version so client samples match
// server counts.

/**
 * Count C++ identifiers, keywords, operators, literals.
 * Mirrors the backend implementation exactly.
 */
export function countTokens(code) {
  if (!code) return 0;
  const cleaned = code
    .replace(/\/\/.*$/gm, '')
    .replace(/\/\*[\s\S]*?\*\//g, '')
    .replace(/"[^"]*"/g, '""')
    .replace(/'[^']*'/g, "''");
  const tokens = cleaned.match(/[a-zA-Z_]\w*|\d+|[+\-*/=<>!&|^~%]+/g) || [];
  return tokens.length;
}
