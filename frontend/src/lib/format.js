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

export function formatDuration(seconds) {
  if (seconds === null || seconds === undefined || typeof seconds !== "number" || isNaN(seconds)) {
    return "—";
  }
  const s = Math.max(0, Math.round(seconds));
  if (s < 60) return `${s}s`;
  if (s < 3600) {
    const m = Math.floor(s / 60);
    const rs = s % 60;
    return rs === 0 ? `${m}m` : `${m}m ${rs}s`;
  }
  const h = Math.floor(s / 3600);
  const m = Math.floor((s % 3600) / 60);
  return `${h}h ${String(m).padStart(2, "0")}m`;
}
