import { MobileScreen } from '../MobileScreen.jsx';
import JoinSectionGate from '@/components/join-section-gate';
import useHasSections from '@/hooks/useHasSections';

export default function Exercises() {
  const { hasSections, checking, recheck } = useHasSections();

  if (checking) return null;
  if (!hasSections) {
    return <JoinSectionGate onJoined={recheck} />;
  }

  return <MobileScreen role="student" path="/student/exercises" />;
}
