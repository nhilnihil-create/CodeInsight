"""
TurboVec Semantic Code Search MCP Server
========================================
A hardware-accelerated semantic codebase search tool using:
- TurboVec (SIMD-optimized vector quantization index)
- TF-IDF document embeddings (no heavy model downloads needed)
- FastMCP protocol

Usage:
  claude mcp add turbovec -- uv run --with turbovec --with fastmcp python turbovec_mcp.py
"""

import os
import re
import glob
import numpy as np
from collections import Counter

from mcp.server.fastmcp import FastMCP

# ---------------------------------------------------------------------------
# Configuration
# ---------------------------------------------------------------------------

ROOT_DIR = os.getcwd()

# File extensions to index
CODE_EXTENSIONS = {
    ".js", ".jsx", ".ts", ".tsx", ".py", ".sql", ".sh", ".css",
    ".html", ".json", ".yaml", ".yml", ".toml", ".md",
    ".mjs", ".cjs", ".env", ".gitignore",
}

# Directories to skip
SKIP_DIRS = {
    "node_modules", ".git", "dist", "build", "vendor",
    "__pycache__", ".venv", "venv", ".cache", ".turbo",
    ".next", "coverage", ".nyc_output",
}

# Max file size to index (1 MB)
MAX_FILE_SIZE = 1_000_000

# Chunks per file limit (prevent huge files from dominating)
MAX_CHUNKS_PER_FILE = 50

# TF-IDF dimension (will be rounded up to multiple of 8 for TurboVec)
# Uses actual TF-IDF vocabulary size; padded to multiple of 8 if needed.

# ---------------------------------------------------------------------------
# File Scanning & Chunking
# ---------------------------------------------------------------------------

def _should_index(path: str) -> bool:
    """Return True if the file should be indexed."""
    rel = os.path.relpath(path, ROOT_DIR)
    parts = rel.split(os.sep)
    if any(p in SKIP_DIRS for p in parts):
        return False
    _, ext = os.path.splitext(path)
    return ext.lower() in CODE_EXTENSIONS


def scan_files() -> list[str]:
    """Return sorted list of indexable file paths."""
    files: list[str] = []
    for root, dirs, filenames in os.walk(ROOT_DIR):
        # Prune skipped dirs in-place
        dirs[:] = [d for d in dirs if d not in SKIP_DIRS]
        for fn in filenames:
            fpath = os.path.join(root, fn)
            if os.path.isfile(fpath) and _should_index(fpath) and os.path.getsize(fpath) <= MAX_FILE_SIZE:
                files.append(fpath)
    return sorted(files)


def chunk_file(filepath: str) -> list[dict]:
    """Split a file into semantically meaningful chunks."""
    try:
        with open(filepath, "r", encoding="utf-8", errors="replace") as f:
            content = f.read()
    except Exception:
        return []

    if not content.strip():
        return []

    rel_path = os.path.relpath(filepath, ROOT_DIR)
    lines = content.split("\n")
    ext = os.path.splitext(filepath)[1].lower()

    chunks: list[dict] = []

    # Pattern for code boundaries: function/class/def declarations, headings
    boundary_patterns = []
    if ext in (".py",):
        boundary_patterns = [
            re.compile(r"^(class |def |async def )"),
            re.compile(r"^# [A-Z]"),
        ]
    elif ext in (".js", ".jsx", ".ts", ".tsx", ".mjs", ".cjs"):
        boundary_patterns = [
            re.compile(r"^(export |export default |const |function |async function |class |// [A-Z]|/\*\*?)"),
        ]
    elif ext == ".sql":
        boundary_patterns = [
            re.compile(r"^(CREATE |ALTER |DROP |INSERT |SELECT |WITH |BEGIN |--)"),
        ]
    elif ext == ".md":
        boundary_patterns = [
            re.compile(r"^#{1,3}\s"),
        ]
    else:
        # Generic: blank lines separate blocks
        boundary_patterns = [
            re.compile(r"^$"),
        ]

    # Split at boundaries
    chunk_starts = [0]
    for i, line in enumerate(lines):
        for pat in boundary_patterns:
            if pat.match(line):
                if i > chunk_starts[-1]:
                    chunk_starts.append(i)
                break

    # Also cap chunk size at 60 lines
    final_chunks: list[dict] = []
    for idx, start in enumerate(chunk_starts):
        end = chunk_starts[idx + 1] if idx + 1 < len(chunk_starts) else len(lines)
        # If chunk is too big, subdivide
        chunk_lines = lines[start:end]
        if len(chunk_lines) > 60:
            for sub_start in range(0, len(chunk_lines), 40):
                sub_end = min(sub_start + 40, len(chunk_lines))
                sub_lines = chunk_lines[sub_start:sub_end]
                text = "\n".join(sub_lines).strip()
                if text:
                    final_chunks.append({
                        "file": rel_path,
                        "start_line": start + sub_start + 1,
                        "end_line": start + sub_end,
                        "text": text,
                    })
        else:
            text = "\n".join(chunk_lines).strip()
            if text:
                final_chunks.append({
                    "file": rel_path,
                    "start_line": start + 1,
                    "end_line": end,
                    "text": text,
                })

    return final_chunks[:MAX_CHUNKS_PER_FILE]


# ---------------------------------------------------------------------------
# TF-IDF Implementation (pure numpy)
# ---------------------------------------------------------------------------

class SimpleTFIDF:
    """Lightweight TF-IDF vectorizer (pure numpy, no sklearn dependency)."""

    def __init__(self, max_features: int = 2000, min_df: int = 2):
        self.max_features = max_features
        self.min_df = min_df
        self.idf_: np.ndarray | None = None
        self.vocabulary_: dict[str, int] = {}

    def _tokenize(self, text: str) -> list[str]:
        # Simple tokenizer: split on non-alphanumeric, keep underscores
        tokens = re.findall(r"[a-zA-Z0-9_]{2,}", text.lower())
        return tokens

    def fit(self, documents: list[str]) -> "SimpleTFIDF":
        """Build vocabulary and IDF from documents."""
        # Count document frequency
        doc_freq: Counter = Counter()
        all_terms: Counter = Counter()

        for doc in documents:
            tokens = self._tokenize(doc)
            unique = set(tokens)
            for term in unique:
                doc_freq[term] += 1
            all_terms.update(tokens)

        # Filter by min_df and take top max_features
        valid_terms = {t for t, c in doc_freq.items() if c >= self.min_df}
        # Sort by global frequency, take top
        sorted_terms = sorted(valid_terms, key=lambda t: all_terms[t], reverse=True)
        sorted_terms = sorted_terms[:self.max_features]

        self.vocabulary_ = {t: i for i, t in enumerate(sorted_terms)}
        n_docs = len(documents)

        # Compute IDF
        idf = np.zeros(len(self.vocabulary_), dtype=np.float64)
        for term, idx in self.vocabulary_.items():
            df = doc_freq[term]
            idf[idx] = np.log((1 + n_docs) / (1 + df)) + 1  # smooth IDF

        self.idf_ = idf
        return self

    def transform(self, documents: list[str]) -> np.ndarray:
        """Transform documents to TF-IDF matrix."""
        if self.idf_ is None:
            raise ValueError("TF-IDF not fitted. Call fit() first.")

        n_docs = len(documents)
        dim = len(self.vocabulary_)
        matrix = np.zeros((n_docs, dim), dtype=np.float32)

        for i, doc in enumerate(documents):
            tokens = self._tokenize(doc)
            if not tokens:
                continue
            tf = Counter(tokens)
            max_tf = max(tf.values()) if tf else 1
            for term, count in tf.items():
                if term in self.vocabulary_:
                    idx = self.vocabulary_[term]
                    # Augmented TF: 0.5 + 0.5 * (count / max_tf)
                    matrix[i, idx] = (0.5 + 0.5 * count / max_tf) * self.idf_[idx]

        # L2 normalize
        norms = np.linalg.norm(matrix, axis=1, keepdims=True)
        norms = np.where(norms == 0, 1, norms)
        matrix = matrix / norms
        return matrix

    def fit_transform(self, documents: list[str]) -> np.ndarray:
        self.fit(documents)
        return self.transform(documents)


# ---------------------------------------------------------------------------
# Index
# ---------------------------------------------------------------------------

class CodeIndex:
    """TurboVec-accelerated code search index."""

    def __init__(self):
        self.vectorizer: SimpleTFIDF | None = None
        self.turbo_index = None
        self.file_paths: list[str] = []
        self.chunks: list[dict] = []
        self.built = False
        self._build_error: str | None = None

    def build(self) -> dict:
        """Build the index from the codebase. Returns stats dict."""
        import turbovec

        print("Scanning files...", flush=True)
        self.file_paths = scan_files()
        if not self.file_paths:
            self._build_error = "No indexable files found."
            return {"error": self._build_error, "files": 0}

        print(f"Chunking {len(self.file_paths)} files...", flush=True)
        all_chunks: list[dict] = []
        for fpath in self.file_paths:
            all_chunks.extend(chunk_file(fpath))
        self.chunks = all_chunks
        if not self.chunks:
            self._build_error = "No chunks extracted from files."
            return {"error": self._build_error, "files": len(self.file_paths)}

        print(f"Building TF-IDF on {len(self.chunks)} chunks...", flush=True)
        texts = [c["text"] for c in self.chunks]
        self.vectorizer = SimpleTFIDF(max_features=2000, min_df=2)
        vectors = self.vectorizer.fit_transform(texts)

        # TurboQuantIndex requires dimension to be multiple of 8
        dim = vectors.shape[1]
        padded_dim = ((dim + 7) // 8) * 8
        if padded_dim > dim:
            vectors = np.pad(vectors, ((0, 0), (0, padded_dim - dim)), mode="constant")
            print(f"Padded vectors from {dim} to {padded_dim} dims", flush=True)

        print(f"Building TurboVec index ({padded_dim}d, {len(vectors)} vectors)...", flush=True)
        self.turbo_index = turbovec.TurboQuantIndex(dim=padded_dim)
        self.turbo_index.add(vectors)
        self.turbo_index.prepare()
        self.built = True
        self._build_error = None

        stats = {
            "files": len(self.file_paths),
            "chunks": len(self.chunks),
            "vocab_size": len(self.vectorizer.vocabulary_),
            "vector_dim": padded_dim,
        }
        print(f"Index built: {stats}", flush=True)
        return stats

    def search(self, query: str, limit: int = 5) -> list[dict]:
        """Search the index. Returns list of {file, start_line, end_line, text, score}."""
        if not self.built or self.vectorizer is None:
            if not self.built:
                self.build()
            if not self.built:
                return [{"error": self._build_error or "Index not built"}]

        # Transform query to TF-IDF vector
        query_vec = self.vectorizer.transform([query])

        # Pad to match index dimension
        dim = self.turbo_index.dim
        if query_vec.shape[1] < dim:
            query_vec = np.pad(query_vec, ((0, 0), (0, dim - query_vec.shape[1])), mode="constant")

        # Ensure float32
        query_vec = query_vec.astype(np.float32)

        # Search
        n_results = min(limit, len(self.chunks))
        distances, indices = self.turbo_index.search(query_vec, n_results)

        results = []
        for dist, idx in zip(distances[0], indices[0]):
            if idx < len(self.chunks):
                chunk = self.chunks[idx]
                # Convert distance to similarity score (lower distance = higher similarity for IP)
                results.append({
                    "file": chunk["file"],
                    "start_line": chunk["start_line"],
                    "end_line": chunk["end_line"],
                    "text": chunk["text"][:500],  # Truncate for display
                    "score": round(float(dist), 4),
                })

        return results


# ---------------------------------------------------------------------------
# MCP Server
# ---------------------------------------------------------------------------

mcp = FastMCP(
    name="TurboVec Code Search",
    instructions="Semantic code search powered by TurboVec SIMD acceleration and TF-IDF embeddings.",
)

_index: CodeIndex | None = None


def get_index() -> CodeIndex:
    global _index
    if _index is None:
        _index = CodeIndex()
    return _index


@mcp.tool()
def semantic_code_search(query: str, limit: int = 5) -> str:
    """
    Search the codebase semantically using SIMD-accelerated vector search.

    Args:
        query: Natural language search query (e.g., "authentication middleware",
               "database connection pool", "error handling")
        limit: Maximum number of results to return (default 5)

    Returns:
        Formatted search results with file paths, line numbers, scores, and code snippets.
    """
    idx = get_index()

    if not idx.built:
        stats = idx.build()
        if "error" in stats:
            return f"Index build failed: {stats['error']}"

    results = idx.search(query, limit)

    if not results:
        return f"No results found for query: '{query}'"

    lines = [f"Search results for: \"{query}\"", "=" * 60, ""]
    for i, r in enumerate(results, 1):
        if "error" in r:
            lines.append(f"  Error: {r['error']}")
            continue
        lines.append(f"  [{i}] {r['file']}:{r['start_line']}-{r['end_line']}  (score: {r['score']})")
        lines.append(f"  {'─' * 56}")
        for code_line in r["text"].split("\n")[:10]:  # Show first 10 lines of snippet
            lines.append(f"    {code_line}")
        if r["text"].count("\n") > 10:
            lines.append(f"    ... (truncated)")
        lines.append("")

    return "\n".join(lines)


@mcp.tool()
def index_stats() -> str:
    """Return statistics about the current search index."""
    idx = get_index()
    if not idx.built:
        return "Index not yet built. Run semantic_code_search() to trigger index build."
    return (
        f"Codebase Index Statistics:\n"
        f"  Files indexed: {len(idx.file_paths)}\n"
        f"  Code chunks:   {len(idx.chunks)}\n"
        f"  Vocabulary:    {len(idx.vectorizer.vocabulary_)} terms\n"
        f"  Vector dim:    {idx.turbo_index.dim}d\n"
        f"  Status:        Built ✅"
    )


if __name__ == "__main__":
    mcp.run()
