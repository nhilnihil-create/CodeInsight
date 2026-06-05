import { MobileScreen } from '../MobileScreen.jsx';
import { PullToRefresh } from '../../../components/mobile/PullToRefresh.jsx';

export default function Command() {
  return (
    <PullToRefresh onRefresh={() => window.location.reload()}>
      <MobileScreen role="instructor" path="/instructor/command" />
    </PullToRefresh>
  );
}
