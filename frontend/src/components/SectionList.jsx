// frontend/src/components/SectionList.jsx
// Spec §9: canonical mobile widget. Used on instructor/Students, instructor/Sections,
// student/Sections, admin/Overview (when showing sections). Desktop reuse: same component,
// no separate desktop file.
//
// Wire format (per the layout configs that reference this widget):
//   data = { sections: Array<{ id, name, courseCode?, studentCount? }> }
//
// Props:
//   data   — server payload, see wire format above
//   role   — "instructor" | "student" | "admin" (informational; widget itself is role-agnostic)
//   mode   — "mobile" | "tablet" | "desktop" (default "mobile")
//            On non-mobile modes, the row uses a different class to opt out of the
//            mobile tap-target / safe-area styling. CSS for the desktop variant
//            can hook into `.section-list[data-mode="desktop"] li`.
//   onView — optional callback fired with the section id when the View button is tapped.
//
// All styling comes from frontend/src/styles/mobile.css (.mobile-list-row, .mobile-list-row__btn).

export function SectionList({ data, role, mode = 'mobile', onView }) {
  if (!data) return null;
  const sections = data.sections ?? [];
  if (!sections.length) return <p className="mobile-empty">No sections yet.</p>;

  const rowClassName = mode === 'mobile' ? 'mobile-list-row' : 'section-list__row';

  return (
    <ul className="section-list" data-mode={mode} data-role={role} role="list" aria-label="Sections">
      {sections.map((s) => (
        <li key={s.id} className={rowClassName} data-testid={`section-row-${s.id}`}>
          <div className="mobile-list-row__main">
            <div className="mobile-list-row__title">{s.name}</div>
            {s.courseCode && (
              <div className="mobile-list-row__meta">{s.courseCode}</div>
            )}
            {typeof s.studentCount === 'number' && (
              <div className="mobile-list-row__meta">{s.studentCount} students</div>
            )}
          </div>
          {onView && (
            <button
              type="button"
              className="mobile-list-row__btn"
              onClick={() => onView(s.id)}
              aria-label={`View ${s.name}`}
            >
              View
            </button>
          )}
        </li>
      ))}
    </ul>
  );
}
