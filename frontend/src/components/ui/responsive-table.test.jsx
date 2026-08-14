import { describe, it, expect, vi } from 'vitest';
import { render, screen, fireEvent } from '@testing-library/react';
import { ResponsiveTable } from './responsive-table';

const data = [
  { id: 1, name: 'Alice', tier: 'critical', score: 0.82 },
  { id: 2, name: 'Bob', tier: 'strong', score: 0.25 },
];

const columns = [
  { key: 'name', header: 'Student', mobile: 'primary' },
  { key: 'tier', header: 'Tier', mobile: 'label' },
  { key: 'score', header: 'Score', mobile: 'hidden' },
  { key: 'actions', header: 'Actions', mobile: 'actions', renderCell: () => <button>Open</button> },
];

describe('ResponsiveTable', () => {
  it('renders every column when no mobile keys are present (backward compatible)', () => {
    const plainColumns = [
      { key: 'name', header: 'Student' },
      { key: 'tier', header: 'Tier' },
    ];
    render(<ResponsiveTable columns={plainColumns} data={data} keyExtractor={(r) => String(r.id)} />);

    expect(screen.getByRole('columnheader', { name: 'Student' })).not.toHaveClass('hidden');
    expect(screen.getByRole('columnheader', { name: 'Tier' })).not.toHaveClass('hidden');
    expect(screen.getAllByRole('row')).toHaveLength(data.length + 1);
  });

  it('maps mobile column keys to the expected responsive classes', () => {
    render(<ResponsiveTable columns={columns} data={data} keyExtractor={(r) => String(r.id)} />);

    // primary → always visible
    expect(screen.getByRole('columnheader', { name: 'Student' })).not.toHaveClass('hidden');
    // label → hidden below sm
    expect(screen.getByRole('columnheader', { name: 'Tier' })).toHaveClass('hidden', 'sm:table-cell');
    // hidden → hidden below md
    expect(screen.getByRole('columnheader', { name: 'Score' })).toHaveClass('hidden', 'md:table-cell');
    // actions → always visible, right-aligned, no wrap
    expect(screen.getByRole('columnheader', { name: 'Actions' })).toHaveClass('text-right');
  });

  it('applies visibility classes to data cells from the mobile key mapping', () => {
    render(<ResponsiveTable columns={columns} data={data} keyExtractor={(r) => String(r.id)} />);

    const rows = screen.getAllByRole('row').slice(1);
    const aliceCells = rows[0].querySelectorAll('td');
    // name (primary, visible) / tier (hidden sm) / score (hidden md) / actions (actions)
    expect(aliceCells[0]).not.toHaveClass('hidden');
    expect(aliceCells[1]).toHaveClass('hidden', 'sm:table-cell');
    expect(aliceCells[2]).toHaveClass('hidden', 'md:table-cell');
    expect(aliceCells[3]).toHaveClass('text-right', 'whitespace-nowrap');
  });

  it('swaps renderMobileCell below sm while keeping the desktop cell unchanged', () => {
    const dualColumns = [
      { key: 'name', header: 'Student', mobile: 'primary' },
      {
        key: 'actions',
        header: 'Actions',
        mobile: 'actions',
        renderCell: (r) => <button>Edit</button>,
        renderMobileCell: (r) => <button>Open</button>,
      },
    ];
    render(<ResponsiveTable columns={dualColumns} data={data} keyExtractor={(r) => String(r.id)} />);

    const row = screen.getAllByRole('row')[1];
    const cells = row.querySelectorAll('td');
    expect(cells).toHaveLength(3); // name + mobile action + desktop action
    expect(cells[1]).toHaveClass('sm:hidden');
    expect(cells[1]).toHaveTextContent('Open');
    expect(cells[2]).toHaveClass('hidden', 'sm:table-cell');
    expect(cells[2]).toHaveTextContent('Edit');
  });

  it('spans the empty message across every configured column', () => {
    render(<ResponsiveTable columns={columns} data={[]} keyExtractor={(r) => String(r.id)} emptyMessage="Nothing here" />);

    const emptyCell = screen.getByText('Nothing here').closest('td');
    expect(emptyCell).toHaveAttribute('colspan', String(columns.length));
  });

  it('renders row content from renderCell or the raw data field', () => {
    render(<ResponsiveTable columns={columns} data={data} keyExtractor={(r) => String(r.id)} />);
    expect(screen.getAllByText('Alice')[0]).toBeTruthy();
  });

  it('calls onRowClick with the item', () => {
    const onRowClick = vi.fn();
    render(<ResponsiveTable columns={columns} data={data} keyExtractor={(r) => String(r.id)} onRowClick={onRowClick} />);
    fireEvent.click(screen.getAllByText('Alice')[0].closest('tr'));
    expect(onRowClick).toHaveBeenCalledWith(data[0]);
  });
});
