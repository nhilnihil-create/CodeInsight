// frontend/src/components/mobile/AppBar.jsx
// Spec §3. Sticky app bar, 48px height, logo + right slot.

import { Link } from 'react-router-dom';

export function AppBar({ title, rightSlot, userMenu }) {
  return (
    <header className="mobile-app-bar">
      <Link to="/" className="mobile-app-bar__logo" aria-label="CodeInsight home">
        <strong>{title}</strong>
      </Link>
      <div className="mobile-app-bar__right">
        {rightSlot === 'avatar' && userMenu}
        {rightSlot === 'menu' && (
          <button
            type="button"
            className="mobile-app-bar__menu"
            aria-label="Open menu"
            onClick={userMenu?.onOpen}
          >☰</button>
        )}
      </div>
    </header>
  );
}
