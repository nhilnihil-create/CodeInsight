import React from 'react';

const IntegrityFlagBadge = ({ flagType }) => {
  // Map flag types to labels and colors
  const flagConfig = {
    HARD_CODING: { label: 'Hardcoding', color: 'text-red-600 bg-red-100' },
    BLANK_TEMPLATE: { label: 'Blank/Template', color: 'text-orange-600 bg-orange-100' },
    BEHAVIORAL_ANOMALY: { label: 'Behavioral Anomaly', color: 'text-yellow-600 bg-yellow-100' },
    CODE_GROWTH_ANOMALY: { label: 'Code Growth', color: 'text-green-600 bg-green-100' },
    PASSIVE_BEHAVIOR_LOG: { label: 'Passive Behavior', color: 'text-blue-600 bg-blue-100' },
    // Default for unknown types
    default: { label: flagType || 'Unknown', color: 'text-gray-600 bg-gray-100' }
  };

  const config = flagConfig[flagType] || flagConfig.default;

  return (
    <span className={`px-2 py-1 text-xs rounded-full font-medium ${config.color}`}>
      {config.label}
    </span>
  );
};

export default IntegrityFlagBadge;