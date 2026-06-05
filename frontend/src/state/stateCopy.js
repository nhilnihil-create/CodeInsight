// frontend/src/state/stateCopy.js
// Canonical copy and visuals for the three states. Spec §8.

export const STATE_COPY = {
  NoData: {
    instructor: {
      title: 'No exercise activity yet',
      body: 'Once students submit, you\'ll see risk signals here.',
      cta: { label: 'Open exercises', route: '/instructor/exercises' },
      badge: null,
    },
    student: {
      title: 'No exercises yet',
      body: 'Your instructor will assign work soon. Check back shortly.',
      cta: { label: 'View sections', route: '/student/sections' },
      badge: null,
    },
    admin: {
      title: 'No data yet',
      body: 'The system is new. Metrics will appear as activity arrives.',
      cta: null,
      badge: null,
    },
  },
  LowConfidence: {
    instructor: {
      title: 'Early signal',
      body: 'Insights sharpen as data arrives.',
      badge: 'Limited',
    },
    student: {
      title: 'Just getting started',
      body: 'Your first submissions unlock personalised guidance.',
      badge: 'Limited',
    },
    admin: {
      title: 'Limited data',
      body: 'Sample size is still building. Re-check after the next batch.',
      badge: 'Limited',
    },
  },
  Healthy: {
    instructor: { badge: null },
    student: { badge: null },
    admin: { badge: null },
  },
};

// State → CSS class map. Spec §8.
export const STATE_VISUAL = {
  NoData:    { card: 'mobile-card--nodata',     border: 'border-dashed' },
  LowConfidence: { card: 'mobile-card--lowconf',  border: 'border-solid' },
  Healthy:   { card: 'mobile-card--healthy',    border: 'border-solid' },
};
