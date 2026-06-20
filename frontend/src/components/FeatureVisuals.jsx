import { useState, useEffect, useRef } from 'react';

function AnimatedNumber({ value, duration = 1200, decimals = 2 }) {
  const [display, setDisplay] = useState('0.00');
  const ref = useRef(null);

  useEffect(() => {
    const el = ref.current?.closest('[data-visible="true"]');
    if (!el) return;

    const start = performance.now();
    const num = parseFloat(value);
    const animate = (now) => {
      const progress = Math.min((now - start) / duration, 1);
      const eased = 1 - Math.pow(1 - progress, 3);
      setDisplay((num * eased).toFixed(decimals));
      if (progress < 1) requestAnimationFrame(animate);
    };
    requestAnimationFrame(animate);
  }, [value, duration, decimals]);

  return <span ref={ref}>{display}</span>;
}

function PulseDot({ color = 'bg-emerald-400', delay = 0 }) {
  return (
    <span className="relative flex h-2 w-2">
      <span
        className={`absolute inline-flex h-full w-full animate-ping rounded-full opacity-75 ${color}`}
        style={{ animationDelay: `${delay}ms` }}
      />
      <span className={`relative inline-flex h-2 w-2 rounded-full ${color}`} />
    </span>
  );
}

function BarSegment({ percent, color, label }) {
  return (
    <div className="flex items-center gap-2">
      <span className="text-[9px] text-muted-foreground w-16 text-right">{label}</span>
      <div className="flex-1 h-1.5 rounded-full bg-border/40 overflow-hidden">
        <div
          className={`h-full rounded-full transition-all duration-700 ${color}`}
          style={{ width: `${percent}%` }}
        />
      </div>
      <span className="text-[9px] font-mono text-muted-foreground w-8">{percent}%</span>
    </div>
  );
}

export function CDSVisual() {
  const [step, setStep] = useState(-1);

  const components = [
    { label: 'NER', sublabel: 'Error Rate', value: 0.68, weight: 40, color: 'bg-amber-500' },
    { label: 'NRS', sublabel: 'Attempts', value: 0.42, weight: 35, color: 'bg-emerald-500' },
    { label: 'NTS', sublabel: 'Time Spent', value: 0.81, weight: 25, color: 'bg-orange-500' },
  ];

  const cds = components.reduce((sum, c) => sum + c.value * (c.weight / 100), 0);
  const classification = cds <= 0.20 ? 'Very Low' : cds <= 0.40 ? 'Low' : cds <= 0.60 ? 'Moderate' : cds <= 0.80 ? 'Elevated' : 'High';
  const classColor = cds <= 0.40 ? 'text-emerald-400' : cds <= 0.60 ? 'text-amber-400' : 'text-orange-400';

  useEffect(() => {
    const timers = components.map((_, i) =>
      setTimeout(() => setStep(i), 400 + i * 300)
    );
    return () => timers.forEach(clearTimeout);
  }, []);

  return (
    <div className="space-y-3">
      <div className="rounded-lg border border-border/60 bg-background/60 p-3">
        <div className="text-[10px] text-primary font-semibold mb-1">Concept Difficulty Score</div>
        <div className="font-mono text-[8px] text-muted-foreground/60 mb-3">CDS = (0.40 × NER) + (0.35 × NRS) + (0.25 × NTS)</div>
        <div className="space-y-2.5">
          {components.map(({ label, sublabel, value, weight, color }, i) => (
            <div
              key={label}
              className={`transition-all duration-400 ${step >= i ? 'opacity-100 translate-x-0' : 'opacity-0 -translate-x-2'}`}
            >
              <div className="flex items-center justify-between mb-0.5">
                <div className="flex items-baseline gap-1.5">
                  <span className="text-[10px] font-semibold text-foreground">{label}</span>
                  <span className="text-[8px] text-muted-foreground/60">{sublabel}</span>
                </div>
                <span className="text-[8px] text-muted-foreground/60 font-mono">×{weight / 100}</span>
              </div>
              <BarSegment percent={Math.round(value * 100)} color={color} label="" />
            </div>
          ))}
        </div>
      </div>

      <div className="grid grid-cols-2 gap-2">
        <div className="rounded-lg border border-primary/30 bg-primary/5 p-3 text-center">
          <div className="text-[9px] text-muted-foreground mb-1">CDS Score</div>
          <div className="text-3xl font-bold text-primary font-mono">
            <AnimatedNumber value={cds} />
          </div>
          <div className={`text-[10px] font-semibold mt-0.5 ${classColor}`}>{classification}</div>
        </div>
        <div className="rounded-lg border border-border/40 bg-background/40 p-3 text-center space-y-1">
          <div className="text-[9px] text-muted-foreground">Class p95</div>
          <div className="text-lg font-bold font-mono text-foreground">0.54</div>
          <div className="text-[8px] text-muted-foreground/60">normalized to class</div>
        </div>
      </div>

      <div className="rounded-lg border border-border/40 bg-background/40 px-3 py-2 text-[9px] text-muted-foreground/70 text-center">
        Class-wide p95-capped normalization — scores are relative, not absolute
      </div>
    </div>
  );
}

export function HeatmapVisual() {
  const [hovered, setHovered] = useState(null);
  const [search, setSearch] = useState('');

  const tiers = [
    { min: 0.01, max: 0.20, label: 'Very Low', cell: 'bg-emerald-500/20 text-emerald-400' },
    { min: 0.21, max: 0.40, label: 'Low', cell: 'bg-emerald-500/10 text-emerald-300/70' },
    { min: 0.41, max: 0.60, label: 'Moderate', cell: 'bg-amber-500/20 text-amber-400' },
    { min: 0.61, max: 0.80, label: 'Elevated', cell: 'bg-orange-500/25 text-orange-400' },
    { min: 0.81, max: 1.00, label: 'High', cell: 'bg-rose-600/35 text-rose-400 font-bold' },
  ];
  const noData = 'bg-slate-900/60 text-slate-500';

  function getTier(cds) {
    if (cds == null || cds === 0) return null;
    return tiers.find(t => cds >= t.min && cds <= t.max) || null;
  }

  const students = [
    { name: 'Maria R.', scores: { Loops: 0.71, Arrays: 0.22, Functions: 0.45, Conditionals: 0.15, OOP: 0.62, Datatypes: 0.33 } },
    { name: 'Jose S.', scores: { Loops: 0.88, Arrays: 0.12, Functions: 0.38, Conditionals: 0.28, OOP: 0.91, Datatypes: 0.18 } },
    { name: 'Ana L.', scores: { Loops: 0.31, Arrays: 0.45, Functions: 0.18, Conditionals: 0.09, OOP: 0.52, Datatypes: 0.25 } },
  ];

  const conceptOrder = ['Datatypes', 'Conditionals', 'Variables', 'Arrays', 'Functions', 'Loops', 'OOP'];
  const filtered = students.filter(s => !search || s.name.toLowerCase().includes(search.toLowerCase()));

  return (
    <div className="space-y-2">
      <div className="flex items-center gap-1.5 rounded-md border border-border/40 bg-background/40 px-2 py-1 text-[10px]">
        <svg className="h-3 w-3 text-muted-foreground" fill="none" viewBox="0 0 24 24" stroke="currentColor"><path strokeLinecap="round" strokeLinejoin="round" strokeWidth={2} d="M21 21l-6-6m2-5a7 7 0 11-14 0 7 7 0 0114 0z" /></svg>
        <input
          value={search}
          onChange={e => setSearch(e.target.value)}
          placeholder="Search student..."
          className="w-full bg-transparent outline-none text-muted-foreground placeholder:text-muted-foreground/40"
        />
      </div>

      <div className="overflow-x-auto">
        <table className="border-collapse text-[9px] font-mono">
          <thead>
            <tr>
              <th className="text-[8px] text-muted-foreground/50 font-normal pr-1.5 text-left sticky left-0 bg-background"></th>
              {conceptOrder.map(c => (
                <th key={c} className="text-[8px] text-muted-foreground/50 font-normal pb-1 px-0.5 text-center">
                  <div className="rotate-45 origin-bottom-left translate-x-1/2 whitespace-nowrap">{c}</div>
                </th>
              ))}
            </tr>
          </thead>
          <tbody>
            {filtered.map((s) => (
              <tr key={s.name} className="group">
                <td className="text-[8px] text-muted-foreground/60 pr-1.5 text-left sticky left-0 bg-background">{s.name}</td>
                {conceptOrder.map(c => {
                  const cds = s.scores[c];
                  const t = getTier(cds);
                  const key = `${s.name}-${c}`;
                  return (
                    <td
                      key={key}
                      onMouseEnter={() => setHovered(key)}
                      onMouseLeave={() => setHovered(null)}
                      className={`w-7 h-7 text-center rounded-[2px] transition-all duration-100 cursor-default ${
                        t ? t.cell : noData
                      } ${hovered === key ? 'scale-110 z-10 relative ring-1 ring-white/20' : ''}`}
                    >
                      {cds > 0 ? cds.toFixed(2) : ''}
                    </td>
                  );
                })}
              </tr>
            ))}
          </tbody>
        </table>
      </div>

      {hovered && (() => {
        const [sn, cn] = hovered.split('-');
        const s = students.find(st => st.name === sn);
        const cds = s?.scores[cn];
        if (!cds || !tiers.some(t => cds >= t.min && cds <= t.max)) return null;
        return (
          <div className="rounded-lg border border-white/10 bg-white/[0.06] backdrop-blur-xl p-2.5 text-[10px] transition-all duration-200 animate-in fade-in">
            <div className="font-semibold text-foreground mb-1">{cn} — {s.name}</div>
            <div className="text-muted-foreground">Difficulty: {cds.toFixed(2)}</div>
          </div>
        );
      })()}

      <div className="flex items-center gap-1.5 flex-wrap text-[8px] text-muted-foreground justify-center">
        {tiers.map(t => (
          <span key={t.label} className="flex items-center gap-1">
            <span className={`w-2 h-1.5 rounded-[1px] ${t.cell}`} />
            {t.label}
          </span>
        ))}
      </div>
    </div>
  );
}

export function IntegrityVisual() {
  const [revealed, setRevealed] = useState([]);
  const flags = [
    {
      type: 'HARDCODING',
      title: 'Hardcoding Detected',
      detail: 'Output contains literal values instead of computed results',
      evidence: 'cout << 42 — expected answer is 42, no variables used',
      whatNext: 'Your instructor will review this flag.',
    },
    {
      type: 'BLANK_TEMPLATE',
      title: 'Blank/Template Submission',
      detail: 'Submission is identical to the starter code',
      evidence: 'No changes made to the provided template',
      whatNext: 'Try modifying the code to solve the problem.',
    },
    {
      type: 'BEHAVIORAL_ANOMALY',
      title: 'Behavioral Pattern Detected',
      detail: 'Unusual timing pattern detected during submission',
      evidence: '4 failed attempts followed by sudden correct answer',
      whatNext: 'This is a hypothesis for review, not a verdict.',
    },
    {
      type: 'CODE_GROWTH_ANOMALY',
      title: 'Code Growth Spike',
      detail: 'More than 30% code added in a single submission',
      evidence: 'Code grew from 19 to 27 lines between attempts',
      whatNext: 'Your instructor will review this flag.',
    },
    {
      type: 'PASSIVE_BEHAVIOR_LOG',
      title: 'Passive Behavior Logged',
      detail: 'Tab switching, pasting, or extended idle time detected',
      evidence: 'Tab switches: 2 · Paste events: 0 · Idle: 14s',
      whatNext: 'This information is logged for context only.',
    },
  ];

  useEffect(() => {
    const timers = flags.map((_, i) =>
      setTimeout(() => setRevealed(prev => [...prev, i]), 300 + i * 200)
    );
    return () => timers.forEach(clearTimeout);
  }, []);

  return (
    <div className="space-y-2">
      <div className="rounded-lg border border-primary/20 bg-primary/5 p-2 text-[9px] text-muted-foreground text-center">
        Integrity flags are hypotheses for review, not verdicts.
      </div>
      {flags.map(({ type, title, detail, evidence, whatNext }, i) => (
        <div
          key={type}
          className={`rounded-lg border px-3 py-2 text-xs transition-all duration-300 ${
            revealed.includes(i) ? 'opacity-100 translate-x-0' : 'opacity-0 -translate-x-4'
          } border-border/40 bg-background/40`}
        >
          <div className="flex items-center justify-between mb-1">
            <span className="font-mono text-[9px] font-semibold text-primary">{type}</span>
            <PulseDot color="bg-amber-400" delay={i * 200} />
          </div>
          <div className="font-medium text-foreground text-left mb-0.5">{title}</div>
          <div className="text-[10px] text-muted-foreground text-left">{detail}</div>
          <div className="mt-1.5 pt-1.5 border-t border-border/40 text-[9px] text-muted-foreground/70 space-y-0.5">
            <div className="font-mono">{evidence}</div>
            <div className="text-muted-foreground/50 italic">{whatNext}</div>
          </div>
        </div>
      ))}
    </div>
  );
}

export function ASTVisual() {
  const [step, setStep] = useState(-1);

  const checks = [
    { label: 'Syntax check: code parses without errors', ok: true },
    { label: 'Required constructs: for loop found', ok: true },
    { label: 'Non-empty body: loop has meaningful logic', ok: true },
    { label: 'Variable usage: loop uses variable, not literal', ok: true },
    { label: 'Output dependency: loop affects program output', ok: true },
    { label: 'Bad pattern: assignment in condition (= vs ==)', ok: false },
  ];

  useEffect(() => {
    const timers = checks.map((_, i) =>
      setTimeout(() => setStep(i), 400 + i * 300)
    );
    return () => timers.forEach(clearTimeout);
  }, []);

  return (
    <div className="space-y-3">
      <div className="rounded-lg border border-border/60 bg-background/60 p-3">
        <div className="text-[10px] text-primary font-semibold mb-2">Verification Steps</div>
        <div className="space-y-1.5">
          {checks.map(({ label, ok }, i) => (
            <div
              key={i}
              className={`flex items-center gap-2 transition-all duration-300 text-[11px] ${
                step >= i ? 'opacity-100 translate-x-0' : 'opacity-0 -translate-x-2'
              }`}
            >
              <span className={ok ? 'text-emerald-400' : 'text-red-400'}>
                {step >= i ? (ok ? '✓' : '✗') : '·'}
              </span>
              <span className={ok ? 'text-muted-foreground' : 'text-red-400'}>
                {label}
              </span>
            </div>
          ))}
        </div>
      </div>

      {step >= checks.length - 1 && (
        <div className="rounded-lg border border-amber-500/30 bg-amber-500/5 p-2 text-[10px] text-amber-400 text-center transition-all duration-300 animate-in fade-in">
          1 issue found — review recommended
        </div>
      )}
    </div>
  );
}

export function MicroConceptVisual() {
  const [expanded, setExpanded] = useState(null);

  const concepts = [
    {
      name: 'Loops',
      issues: [
        { name: 'Off-by-one error', students: 8, severity: 'high', suggestion: 'Check loop boundary — use < instead of <= when iterating to array length' },
        { name: 'Missing increment', students: 3, severity: 'high', suggestion: 'Ensure i++ or equivalent is inside the loop body' },
        { name: 'Infinite loop', students: 2, severity: 'high', suggestion: 'Verify loop has a condition that eventually becomes false' },
      ],
    },
    {
      name: 'Functions',
      issues: [
        { name: 'Missing return statement', students: 5, severity: 'medium', suggestion: 'Non-void functions must return a value' },
        { name: 'Wrong return type', students: 3, severity: 'medium', suggestion: 'Check that return value matches declared type' },
      ],
    },
    {
      name: 'Conditionals',
      issues: [
        { name: 'Assignment in condition', students: 4, severity: 'medium', suggestion: 'Use == for comparison, not =' },
        { name: 'Missing else branch', students: 2, severity: 'low', suggestion: 'Handle both true and false cases' },
      ],
    },
  ];

  return (
    <div className="space-y-2">
      <div className="rounded-lg border border-border/60 bg-background/60 p-2.5">
        <div className="text-[10px] text-primary font-semibold mb-1.5">Class-Wide Report</div>
        <div className="text-[9px] text-muted-foreground">33 rules across 7 C++ concepts — instructor view</div>
      </div>

      {concepts.map((group, gi) => (
        <button
          key={group.name}
          onClick={() => setExpanded(expanded === gi ? null : gi)}
          className="w-full rounded-lg border border-border/60 bg-background/60 p-2.5 text-left transition-all duration-200 hover:border-primary/30 hover:bg-background/80 cursor-pointer"
        >
          <div className="flex items-center justify-between">
            <span className="text-xs font-medium text-foreground">{group.name}</span>
            <span className="text-[9px] font-mono text-muted-foreground">{group.issues.length} issues</span>
          </div>
          {expanded === gi && (
            <div className="mt-2 pt-2 border-t border-border/40 space-y-2 animate-in fade-in slide-in-from-top-1 duration-200">
              {group.issues.map(issue => (
                <div key={issue.name} className="space-y-0.5">
                  <div className="flex items-center justify-between">
                    <span className="text-[10px] font-medium text-foreground/80">{issue.name}</span>
                    <span className={`text-[8px] px-1.5 py-0.5 rounded-full font-medium ${
                      issue.severity === 'high' ? 'bg-red-500/10 text-red-400' :
                      issue.severity === 'medium' ? 'bg-amber-500/10 text-amber-400' :
                      'bg-emerald-500/10 text-emerald-400'
                    }`}>
                      {issue.students} students
                    </span>
                  </div>
                  <div className="text-[9px] text-muted-foreground/70 italic">{issue.suggestion}</div>
                </div>
              ))}
            </div>
          )}
        </button>
      ))}
    </div>
  );
}
