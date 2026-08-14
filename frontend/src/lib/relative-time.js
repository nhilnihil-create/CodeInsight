// frontend/src/lib/relative-time.js
// Sign-agnostic compact durations and human-readable deadline phrasing (no date-fns).

export function formatDurationFromNow(minutes) {
  if (typeof minutes !== 'number' || Number.isNaN(minutes)) return null;
  if (Math.abs(minutes) < 1) return 'now';
  const abs = Math.abs(minutes);
  const days = Math.floor(abs / 1440);
  const hours = Math.floor((abs % 1440) / 60);
  if (days >= 1) return hours > 0 ? `${days}d ${hours}h` : `${days}d`;
  if (hours >= 1) return `${hours}h`;
  return `${Math.floor(abs)}m`;
}

export function formatDeadlineFromNow(deadline, now = Date.now()) {
  if (deadline == null) return 'No deadline';
  const time = new Date(deadline).getTime();
  if (Number.isNaN(time)) return 'No deadline';

  const diff = time - now;
  if (diff <= 0) {
    const absMinutes = Math.floor(Math.abs(diff) / 60000);
    if (absMinutes < 1) return 'Due now';
    const days = Math.floor(absMinutes / 1440);
    const hours = Math.floor((absMinutes % 1440) / 60);
    if (days >= 1) return `Overdue ${days}d`;
    if (hours >= 1) return `Overdue ${hours}h`;
    return `Overdue ${absMinutes}m`;
  }

  const minutes = Math.floor(diff / 60000);
  if (minutes < 1) return 'Due now';
  const days = Math.floor(minutes / 1440);
  const hours = Math.floor((minutes % 1440) / 60);
  if (days >= 1) return hours > 0 ? `Due in ${days}d ${hours}h` : `Due in ${days}d`;
  if (hours >= 1) return `Due in ${hours}h`;
  return `Due in ${minutes}m`;
}

export function formatMinutesUntilDue(minutes) {
  if (typeof minutes !== 'number' || Number.isNaN(minutes)) return 'No deadline';
  if (Math.abs(minutes) < 1) return 'Due now';
  if (minutes < 0) return `Overdue ${formatDurationFromNow(minutes)}`;
  return `Due in ${formatDurationFromNow(minutes)}`;
}
