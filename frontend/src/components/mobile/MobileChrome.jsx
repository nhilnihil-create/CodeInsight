// frontend/src/components/mobile/MobileChrome.jsx
// AppBar + BottomNav wrapper used inside the route tree on mobile mode.
// Reads role-specific chrome from the layout config.

import { useMode } from '../../hooks/use-mobile.js';
import { useAuth } from '../../context/AuthContext.jsx';
import { getConfig } from '../../config/useLayoutConfig.js';
import { AppBar } from './AppBar.jsx';
import { BottomNav } from './BottomNav.jsx';

export function MobileChrome() {
  const mode = useMode();
  const { user } = useAuth();
  if (mode !== 'mobile' || !user) return null;

  const role = user.role;
  // Admin role sometimes stored as 'admin', sometimes as 'staff' — guard both
  const cfgRole = role === 'admin' || role === 'staff' ? 'admin' : role;
  const cfg = getConfig(cfgRole, 'mobile');
  if (!cfg?.chrome) return null;

  return (
    <>
      <AppBar title={cfg.chrome.appBar?.title ?? 'CodeInsight'} rightSlot={cfg.chrome.appBar?.rightSlot} />
      <BottomNav items={cfg.chrome.bottomNav?.items ?? []} />
    </>
  );
}
