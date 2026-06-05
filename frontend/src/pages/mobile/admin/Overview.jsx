import { MobileScreen } from '../MobileScreen.jsx';
import { PullToRefresh } from '../../../components/mobile/PullToRefresh.jsx';

export default function Overview() {
  return (
    <PullToRefresh onRefresh={() => window.location.reload()}>
      <MobileScreen role="admin" path="/admin/overview" />
    </PullToRefresh>
  );
}
