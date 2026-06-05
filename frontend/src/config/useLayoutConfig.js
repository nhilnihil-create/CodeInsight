// frontend/src/config/useLayoutConfig.js
// Spec §10. The shell renders exactly what the config says.

import instructorMobile from './mobile/instructor.json';
import studentMobile from './mobile/student.json';
import adminMobile from './mobile/admin.json';

const TABLES = {
  instructor: { mobile: instructorMobile, tablet: instructorMobile, desktop: instructorMobile },
  student:    { mobile: studentMobile,    tablet: studentMobile,    desktop: studentMobile },
  admin:      { mobile: adminMobile,      tablet: adminMobile,      desktop: adminMobile },
};

export function getConfig(role, mode) {
  const cfg = TABLES[role]?.[mode];
  if (!cfg) throw new Error(`No config for role=${role} mode=${mode}`);
  return cfg;
}

/** Evaluate a showIf expression against response data. Spec §10. */
export function shouldShow(widget, data) {
  if (!widget.showIf) return true;
  // simple expression format: "data.length > 0" or "data.count >= 1"
  const expr = widget.showIf;
  if (expr === 'data.length > 0')  return Array.isArray(data) && data.length > 0;
  if (expr === 'data.length > 2')  return Array.isArray(data) && data.length > 2;
  if (expr === 'data && data.length > 0') return Array.isArray(data) && data.length > 0;
  if (expr.startsWith('data.')) {
    // data.<path> <op> <value>
    const m = expr.match(/^data\.(\w+)\s*(>=|<=|==|!=|>|<)\s*(.+)$/);
    if (m) {
      const [, path, op, raw] = m;
      const actual = data?.[path];
      const expected = JSON.parse(raw);
      switch (op) {
        case '>=': return actual >= expected;
        case '<=': return actual <= expected;
        case '==': return actual === expected;
        case '!=': return actual !== expected;
        case '>':  return actual > expected;
        case '<':  return actual < expected;
      }
    }
  }
  return true;
}
