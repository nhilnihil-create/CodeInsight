// frontend/src/components/SectionList.test.jsx
// Task 13 gap-fill: SectionList is referenced by MobileScreen.jsx, all 3 mobile
// configs, and the useLayoutConfig.test.js canon set, but the component file
// was never authored. This test pins the wire format and behavior.

import { describe, it, expect, vi } from 'vitest';
import { render, screen, fireEvent } from '@testing-library/react';
import { SectionList } from './SectionList.jsx';

describe('<SectionList>', () => {
  it('renders nothing when data is null', () => {
    const { container } = render(<SectionList data={null} />);
    expect(container).toBeEmptyDOMElement();
  });

  it('renders a row for each section', () => {
    render(
      <SectionList
        data={{ sections: [{ id: 1, name: 'BSCS-3A' }, { id: 2, name: 'BSCS-3B' }] }}
      />
    );
    expect(screen.getByText('BSCS-3A')).toBeInTheDocument();
    expect(screen.getByText('BSCS-3B')).toBeInTheDocument();
  });

  it('renders a View button per row when onView is provided', () => {
    render(
      <SectionList
        data={{ sections: [{ id: 1, name: 'A' }, { id: 2, name: 'B' }, { id: 3, name: 'C' }] }}
        onView={() => {}}
      />
    );
    const viewButtons = screen.getAllByRole('button', { name: /^View / });
    expect(viewButtons).toHaveLength(3);
  });

  it('calls onView(id) when a row View button is clicked', () => {
    const onView = vi.fn();
    render(
      <SectionList
        data={{ sections: [{ id: 7, name: 'Algebra' }, { id: 9, name: 'Biology' }] }}
        onView={onView}
      />
    );
    fireEvent.click(screen.getByRole('button', { name: /View Algebra/ }));
    fireEvent.click(screen.getByRole('button', { name: /View Biology/ }));
    expect(onView).toHaveBeenNthCalledWith(1, 7);
    expect(onView).toHaveBeenNthCalledWith(2, 9);
  });

  it('on mobile mode, rows use the mobile-list-row class', () => {
    const { container } = render(
      <SectionList
        data={{ sections: [{ id: 1, name: 'X' }] }}
        mode="mobile"
      />
    );
    const rows = container.querySelectorAll('li');
    expect(rows.length).toBeGreaterThan(0);
    rows.forEach((row) => {
      expect(row.className).toMatch(/mobile-list-row/);
    });
  });

  it('on desktop mode, rows do NOT use the mobile-list-row class', () => {
    const { container } = render(
      <SectionList
        data={{ sections: [{ id: 1, name: 'X' }] }}
        mode="desktop"
      />
    );
    const rows = container.querySelectorAll('li');
    expect(rows.length).toBeGreaterThan(0);
    rows.forEach((row) => {
      expect(row.className).not.toMatch(/mobile-list-row/);
    });
  });
});
