// frontend/src/components/mobile/BottomNav.jsx
// Spec §3, §3.1. Role-specific bottom tab bar.

import { Link, useLocation } from 'react-router-dom';

const ICONS = {
  home:    '⌂', alert: '⚠', users: '👥', diamond: '◇', flag: '⚑', grid: '☷',
  sun:     '☀', chart: '▤', cog: '⚙',
};

export function BottomNav({ items }) {
  const { pathname } = useLocation();
  const activeKey = items.find(it => pathname.startsWith(it.route))?.key;

  return (
    <nav className="mobile-bottom-nav" aria-label="Primary">
      {items.map((it) => {
        const isActive = activeKey === it.key;
        return (
          <Link
            key={it.key}
            to={it.route}
            className={`mobile-bottom-nav__item${isActive ? ' mobile-bottom-nav__item--active' : ''}`}
            aria-current={isActive ? 'page' : undefined}
          >
            <span aria-hidden="true">{ICONS[it.icon] ?? '●'}</span>
            <span>{it.label}</span>
          </Link>
        );
      })}
    </nav>
  );
}
