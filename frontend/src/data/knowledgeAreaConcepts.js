export const KNOWLEDGE_AREA_GROUPS = [
  {
    key: 'SDF-FPC',
    label: 'Procedural Fundamentals',
    shortLabel: 'Fundamentals',
  },
  {
    key: 'SDF-PMD',
    label: 'Program Design & Logic',
    shortLabel: 'Design & Logic',
  },
  {
    key: 'SDF-OOP',
    label: 'Object Oriented Paradigms',
    shortLabel: 'OOP',
  },
  {
    key: 'SDF-FDS',
    label: 'Advanced Structures',
    shortLabel: 'Advanced',
  },
];

export const CONCEPT_KNOWLEDGE_AREA = {
  'Datatypes': 'SDF-FPC',
  'Variables': 'SDF-FPC',
  'Strings': 'SDF-FPC',
  'Input/Output': 'SDF-FPC',
  'Enums': 'SDF-FPC',
  'Type Casting': 'SDF-FPC',
  'File I/O': 'SDF-FPC',
  'Conditionals': 'SDF-PMD',
  'Loops': 'SDF-PMD',
  'Functions': 'SDF-PMD',
  'Switch/Case': 'SDF-PMD',
  'Nested Loops': 'SDF-PMD',
  'Recursion': 'SDF-PMD',
  'Error Handling': 'SDF-PMD',
  'Scope': 'SDF-PMD',
  'OOP': 'SDF-OOP',
  'Preprocessor': 'SDF-OOP',
  'Namespaces': 'SDF-OOP',
  'Inheritance': 'SDF-OOP',
  'Polymorphism': 'SDF-OOP',
  'Arrays': 'SDF-FDS',
  'Pointers': 'SDF-FDS',
  'Structs': 'SDF-FDS',
  'Dynamic Memory': 'SDF-FDS',
  'Linked Lists': 'SDF-FDS',
};

export function getConceptsForArea(areaKey) {
  return Object.entries(CONCEPT_KNOWLEDGE_AREA)
    .filter(([, area]) => area === areaKey)
    .map(([name]) => name);
}

export function getAreaKeyForConcept(conceptName) {
  return CONCEPT_KNOWLEDGE_AREA[conceptName] || null;
}

export function buildRadarDataForGroup(scores, areaKey) {
  const areaConcepts = getConceptsForArea(areaKey);
  const bucket = {};
  for (const s of scores || []) {
    const name = s.concept_name;
    if (!name || !areaConcepts.includes(name)) continue;
    if (!bucket[name]) {
      bucket[name] = { cdsTotal: 0, nerTotal: 0, nrsTotal: 0, ntsTotal: 0, count: 0, attempts: 0 };
    }
    const b = bucket[name];
    b.cdsTotal += Number(s.cds) || 0;
    b.nerTotal += Number(s.ner) || 0;
    b.nrsTotal += Number(s.nrs) || 0;
    b.ntsTotal += Number(s.nts) || 0;
    b.count += 1;
    b.attempts += 1;
  }
  return areaConcepts.map((name) => {
    const b = bucket[name];
    if (!b) {
      return { subject: name, mastery: 0, cds: 0, ner: 0, nrs: 0, nts: 0, attempts: 0 };
    }
    const avgCds = b.cdsTotal / b.count;
    return {
      subject: name,
      mastery: Math.round((1 - avgCds) * 10000) / 100,
      cds: Math.round(avgCds * 100) / 100,
      ner: Math.round((b.nerTotal / b.count) * 100) / 100,
      nrs: Math.round((b.nrsTotal / b.count) * 100) / 100,
      nts: Math.round((b.ntsTotal / b.count) * 100) / 100,
      attempts: b.attempts,
    };
  });
}
