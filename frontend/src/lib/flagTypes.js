export const FLAG_TYPE_LABELS = {
  HARDCODING: 'Hardcoding',
  BLANK_TEMPLATE: 'Blank Template',
  BEHAVIORAL_ANOMALY: 'Behavioral Anomaly',
  CODE_GROWTH_ANOMALY: 'Code Growth',
  PASSIVE_BEHAVIOR_LOG: 'Contextual Activity',
};

export function flagTypeLabel(type) {
  return FLAG_TYPE_LABELS[type] || (type || 'Flag').replace(/_/g, ' ');
}
