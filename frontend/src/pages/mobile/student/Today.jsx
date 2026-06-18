import { MobileScreen } from '../MobileScreen.jsx';
import { PullToRefresh } from '../../../components/mobile/PullToRefresh.jsx';
import JoinSectionGate from '@/components/join-section-gate';
import useHasSections from '@/hooks/useHasSections';

export default function Today() {
  const { hasSections, checking, recheck } = useHasSections();

  if (checking) return null;
  if (!hasSections) {
    return <JoinSectionGate onJoined={recheck} />;
  }

  return (
    <PullToRefresh onRefresh={() => window.location.reload()}>
      <MobileScreen role="student" path="/student/today" />
    </PullToRefresh>
  );
}
