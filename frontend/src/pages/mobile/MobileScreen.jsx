// frontend/src/pages/mobile/MobileScreen.jsx
// Renders one screen from the layout config. Zero role branching.

import { useEffect, useState } from 'react';
import { getConfig, shouldShow } from '../../config/useLayoutConfig.js';
import { StateAwareShell } from '../../state/StateAwareShell.jsx';
import { useStateDerivation } from '../../state/useStateDerivation.js';

import { InstructorPriorityInsight } from '../../components/mobile/InstructorPriorityInsight.jsx';
import { StudentTodayFocus }         from '../../components/mobile/StudentTodayFocus.jsx';
import { SnapshotMetrics }           from '../../components/mobile/SnapshotMetrics.jsx';
import { EvaluationProgress }        from '../../components/mobile/EvaluationProgress.jsx';
import { AtRiskQueue }               from '../../components/mobile/AtRiskQueue.jsx';
import { AtRiskRoster }              from '../../components/mobile/AtRiskRoster.jsx';
import { InterventionQueue }         from '../../components/mobile/InterventionQueue.jsx';
import { ActionStack }               from '../../components/mobile/ActionStack.jsx';
import { TopStrugglingConcepts }     from '../../components/mobile/TopStrugglingConcepts.jsx';
import { WeakestConceptBar }         from '../../components/mobile/WeakestConceptBar.jsx';
import { ConceptMasteryBarSet }      from '../../components/mobile/ConceptMasteryBarSet.jsx';
import { WeeklyProgress }            from '../../components/mobile/WeeklyProgress.jsx';
import { WeeklyTeachingInsight }     from '../../components/mobile/WeeklyTeachingInsight.jsx';
import { ClassProfileRadar }         from '../../components/mobile/ClassProfileRadar.jsx';
import { IntegrityFlagCount }        from '../../components/mobile/IntegrityFlagCount.jsx';
import { IntegrityFlagList }         from '../../components/mobile/IntegrityFlagList.jsx';
import { IntegrityFlagHistory }      from '../../components/mobile/IntegrityFlagHistory.jsx';
import { IntegrityDrillNotice }      from '../../components/mobile/IntegrityDrillNotice.jsx';
import { DesktopOnlyNotice }         from '../../components/mobile/DesktopOnlyNotice.jsx';
import { AuditLog }                  from '../../components/mobile/AuditLog.jsx';
import { ExerciseCardList }          from '../../components/mobile/ExerciseCardList.jsx';
import { TestResultList }            from '../../components/mobile/TestResultList.jsx';
import { OpenFullEditorHint }        from '../../components/mobile/OpenFullEditorHint.jsx';
import { CodePreviewSurface }        from '../../components/mobile/CodePreviewSurface.jsx';
import { Iso25010Instrument }        from '../../components/mobile/Iso25010Instrument.jsx';
import { SectionList }               from '../../components/SectionList.jsx';

const WIDGET_MAP = {
  InstructorPriorityInsight, AtRiskQueue, AtRiskRoster, InterventionQueue,
  TopStrugglingConcepts, WeakestConceptBar, ConceptMasteryBarSet, WeeklyProgress,
  WeeklyTeachingInsight, ClassProfileRadar, ActionStack, StudentTodayFocus,
  SnapshotMetrics, EvaluationProgress, Iso25010Instrument, AuditLog,
  IntegrityFlagCount, IntegrityFlagList, IntegrityFlagHistory, IntegrityDrillNotice,
  DesktopOnlyNotice, ExerciseCardList, TestResultList, OpenFullEditorHint,
  CodePreviewSurface, SectionList,
};

export function useFetch(endpoint) {
  const [data, setData] = useState(null);
  const [loading, setLoading] = useState(false);
  useEffect(() => {
    if (!endpoint) return;
    let cancelled = false;
    setLoading(true);
    fetch(endpoint)
      .then((r) => r.ok ? r.json() : null)
      .then((d) => { if (!cancelled) { setData(d); setLoading(false); } })
      .catch(() => { if (!cancelled) setLoading(false); });
    return () => { cancelled = true; };
  }, [endpoint]);
  return { data, loading };
}

export function Widget({ widget, role }) {
  const { data } = useFetch(widget.endpoint);
  if (widget.static) return null;
  if (!shouldShow(widget, data)) return null;
  const Component = WIDGET_MAP[widget.widget];
  if (!Component) return null;
  // Special-case: SectionList is reused; only pass data if defined
  return <Component data={data} role={role} {...(widget.render ? { render: widget.render } : {})} />;
}

export function MobileScreen({ role, path, params = {} }) {
  const config = getConfig(role, 'mobile');
  const screen = config.screens[path] ?? config.screens[`${path}/:id`];
  if (!screen) return <p style={{ padding: 16 }}>404 — unknown screen {path}</p>;

  return (
    <main className="mobile-content">
      {screen.primary && <Widget widget={screen.primary} role={role} />}
      {screen.primaryAction && <Widget widget={screen.primaryAction} role={role} />}
      {screen.secondary?.map((w, i) => <Widget key={`s${i}`} widget={w} role={role} />)}
      {screen.tertiary?.map((w, i) => <Widget key={`t${i}`} widget={w} role={role} />)}
    </main>
  );
}
