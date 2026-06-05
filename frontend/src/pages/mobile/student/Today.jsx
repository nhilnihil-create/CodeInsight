import { MobileScreen } from '../MobileScreen.jsx';
import { PullToRefresh } from '../../../components/mobile/PullToRefresh.jsx';

export default function Today() {
  return (
    <PullToRefresh onRefresh={() => window.location.reload()}>
      <MobileScreen role="student" path="/student/today" />
    </PullToRefresh>
  );
}
