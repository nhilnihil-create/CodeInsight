/**
 * simulation/personas.js
 *
 * 50 student personas across 4 performance tiers + 1 instructor.
 * All emails use sim.*@test.codeinsight for cleanup-at-start prefix scoping.
 */

const INSTRUCTOR = {
  name: 'Sim Instructor',
  email: 'sim.instructor@test.codeinsight',
  password: 'SimPass123!',
  role: 'instructor',
};

const TIER_CONFIGS = {
  high_performer: {
    count: 10,
    accuracyRange: [0.90, 1.0],
    avgTimeSecRange: [60, 180],
    errorProfiles: ['none'],
    retryBehavior: 'none',
    tierLabel: 'Tier 1',
  },
  medium_learner: {
    count: 20,
    accuracyRange: [0.50, 0.80],
    avgTimeSecRange: [180, 600],
    errorProfiles: ['BUG_SYNTAX_ERROR', 'BUG_OFF_BY_ONE'],
    retryBehavior: 'moderate',
    tierLabel: 'Tier 2',
  },
  struggling_learner: {
    count: 15,
    accuracyRange: [0.10, 0.50],
    avgTimeSecRange: [600, 1800],
    errorProfiles: ['BUG_INFINITE_LOOP', 'BUG_OFF_BY_ONE', 'BUG_SYNTAX_ERROR'],
    retryBehavior: 'heavy',
    tierLabel: 'Tier 3',
  },
  adversarial: {
    count: 5,
    accuracyRange: [0, 0],
    avgTimeSecRange: [0, 10],
    errorProfiles: ['FLAG_COPY_PASTE', 'spam', 'massive_payload'],
    retryBehavior: 'spam',
    tierLabel: 'Tier 4',
  },
};

// Deterministic seeded random for reproducibility
function seededRandom(seed) {
  let s = seed;
  return function () {
    s = (s * 16807 + 0) % 2147483647;
    return (s - 1) / 2147483646;
  };
}

function randRange(rng, min, max) {
  return min + rng() * (max - min);
}

function pickOne(rng, arr) {
  return arr[Math.floor(rng() * arr.length)];
}

const FIRST_NAMES = [
  'Alice', 'Bob', 'Carol', 'Dan', 'Eve', 'Frank', 'Grace', 'Hank',
  'Iris', 'Jack', 'Kate', 'Leo', 'Mia', 'Noah', 'Olivia', 'Pete',
  'Quinn', 'Rosa', 'Sam', 'Tina', 'Uma', 'Vince', 'Wendy', 'Xander',
  'Yara', 'Zane', 'Amy', 'Ben', 'Chloe', 'Derek', 'Ella', 'Felix',
  'Gina', 'Hugo', 'Ivy', 'Jake', 'Kira', 'Liam', 'Maya', 'Nate',
  'Opal', 'Paul', 'Rita', 'Sean', 'Tara', 'Uri', 'Vera', 'Will',
  'Xena', 'Yuri'
];

const LAST_NAMES = [
  'Chen', 'Smith', 'Johnson', 'Williams', 'Brown', 'Jones', 'Garcia',
  'Miller', 'Davis', 'Rodriguez', 'Martinez', 'Hernandez', 'Lopez',
  'Gonzalez', 'Wilson', 'Anderson', 'Thomas', 'Taylor', 'Moore',
  'Jackson', 'Martin', 'Lee', 'Perez', 'Thompson', 'White', 'Harris',
  'Sanchez', 'Clark', 'Ramirez', 'Lewis', 'Robinson', 'Walker',
  'Young', 'Allen', 'King', 'Wright', 'Scott', 'Torres', 'Nguyen',
  'Hill', 'Flores', 'Green', 'Adams', 'Nelson', 'Baker', 'Hall',
  'Rivera', 'Campbell', 'Mitchell', 'Carter'
];

function generatePersonas() {
  const personas = [];
  const rng = seededRandom(42); // deterministic
  let nameIdx = 0;
  let globalIdx = 1;

  for (const [tierKey, config] of Object.entries(TIER_CONFIGS)) {
    for (let i = 0; i < config.count; i++) {
      const firstName = FIRST_NAMES[nameIdx % FIRST_NAMES.length];
      const lastName = LAST_NAMES[nameIdx % LAST_NAMES.length];
      nameIdx++;

      const email = `sim.${firstName.toLowerCase()}.${lastName.toLowerCase()}${globalIdx}@test.codeinsight`;

      personas.push({
        id: `sim_${tierKey}_${String(globalIdx).padStart(2, '0')}`,
        name: `${firstName} ${lastName}`,
        email,
        password: 'SimPass123!',
        tier: tierKey,
        tierLabel: config.tierLabel,
        accuracy: Math.round(randRange(rng, ...config.accuracyRange) * 100) / 100,
        avgTimeSec: Math.round(randRange(rng, ...config.avgTimeSecRange)),
        errorProfile: config.errorProfiles.length > 0
          ? pickOne(rng, config.errorProfiles)
          : 'none',
        retryBehavior: config.retryBehavior,
      });

      globalIdx++;
    }
  }

  return personas;
}

const PERSONAS = generatePersonas();

module.exports = { PERSONAS, INSTRUCTOR, TIER_CONFIGS };
