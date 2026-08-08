// frontend/src/lib/format.js
// Hand-rolled date/duration formatters (no date-fns).

function toEpochMs(value) {
  if (value === null || value === undefined || value === "") return null;
  if (typeof value === "number") {
    return value > 1e12 ? value : value * 1000;
  }
  if (/^\d+$/.test(String(value))) {
    const n = Number(value);
    return n > 1e12 ? n : n * 1000;
  }
  return new Date(value).getTime();
}

export function formatDateAgo(value, now = Date.now()) {
  const epochMs = toEpochMs(value);
  if (epochMs === null) return "—";
  const diffMs = now - epochMs;
  if (isNaN(diffMs)) return "—";
  if (diffMs < 0) return "just now";

  const mins = Math.floor(diffMs / 60000);
  if (mins < 1) return "just now";
  if (mins < 60) return mins === 1 ? "1 minute ago" : `${mins} minutes ago`;
  const hours = Math.floor(mins / 60);
  if (hours < 24) return hours === 1 ? "1 hour ago" : `${hours} hours ago`;
  const days = Math.floor(hours / 24);
  return days === 1 ? "1 day ago" : `${days} days ago`;
}

function trimTrailingZero(value) {
  return String(Math.round(value * 10) / 10).replace(/\.0$/, "");
}

export function formatDuration(seconds) {
  if (seconds === null || seconds === undefined || typeof seconds !== "number" || isNaN(seconds)) {
    return "—";
  }
  if (seconds < 0) return "0s";
  if (seconds < 60) return `${Math.round(seconds)}s`;
  if (seconds < 3600) return `${trimTrailingZero(seconds / 60)} min`;
  return `${trimTrailingZero(seconds / 3600)} hr`;
}
