// frontend/src/components/mobile/BottomNav.test.jsx
import { describe, it, expect } from 'vitest';
import { render, screen } from '@testing-library/react';
import { MemoryRouter } from 'react-router-dom';
import { BottomNav } from './BottomNav.jsx';

const items = [
  { key: 'a', label: 'Alpha',  icon: 'home',  route: '/a' },
  { key: 'b', label: 'Bravo',  icon: 'users', route: '/b' },
  { key: 'c', label: 'Charlie', icon: 'cog',  route: '/c' },
];

describe('<BottomNav>', () => {
  it('renders one link per item with the tap-target CSS class', () => {
    render(<MemoryRouter><BottomNav items={items} activeKey="a" /></MemoryRouter>);
    const links = screen.getAllByRole('link');
    expect(links).toHaveLength(3);
    links.forEach(btn => {
      expect(btn.className).toMatch(/mobile-bottom-nav__item\b/);
    });
  });

  it('marks the active item with the active class', () => {
    render(
      <MemoryRouter initialEntries={['/b']}>
        <BottomNav items={items} activeKey="b" />
      </MemoryRouter>
    );
    const buttons = screen.getAllByRole('link');
    expect(buttons[1].className).toMatch(/mobile-bottom-nav__item--active/);
    expect(buttons[0].className).not.toMatch(/mobile-bottom-nav__item--active/);
  });
});
