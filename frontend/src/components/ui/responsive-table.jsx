import { Fragment } from 'react';
import { Table, TableHeader, TableBody, TableRow, TableHead, TableCell } from '@/components/ui/table';
import { cn } from '@/lib/utils';

/**
 * Column visibility at each breakpoint, driven by the `mobile` key callers
 * pass on column definitions:
 *   - `primary`   → visible at every breakpoint
 *   - `label`     → visible from `sm` up (hidden on phones)
 *   - `hidden`    → visible from `md` up (kept out of the phone layout)
 *   - `actions`   → visible at every breakpoint, right-aligned, no wrapping
 *   - no key      → visible everywhere (backward compatible)
 *
 * Columns that also supply `renderMobileCell` render two cells and toggle
 * between them with `sm:` — the phone variant replaces the desktop one below
 * `sm`. Desktop rendering is unchanged.
 */
function columnVisibilityClass(col) {
  switch (col.mobile) {
    case 'label':
      return 'hidden sm:table-cell';
    case 'hidden':
      return 'hidden md:table-cell';
    case 'actions':
      return 'whitespace-nowrap text-right';
    default:
      return '';
  }
}

export function ResponsiveTable({ columns, data, keyExtractor, onRowClick, emptyMessage = "No data found." }) {
  // Every column renders exactly one visible cell per row at any breakpoint,
  // so the empty/loading row spans the full (visible) column count.
  const colSpan = columns.length;

  return (
    <div className="rounded-xl border border-border bg-card">
      <div className="overflow-x-auto">
        <Table>
          <TableHeader>
            <TableRow>
              {columns.map(col => (
                <TableHead
                  key={col.key}
                  className={cn(
                    col.header === 'Actions' && 'text-right',
                    columnVisibilityClass(col),
                  )}
                >
                  {col.header}
                </TableHead>
              ))}
            </TableRow>
          </TableHeader>
          <TableBody>
            {data.length === 0 ? (
              <TableRow>
                <TableCell colSpan={colSpan} className="text-center text-muted-foreground py-6">
                  {emptyMessage}
                </TableCell>
              </TableRow>
            ) : (
              data.map(item => (
                <TableRow
                  key={keyExtractor(item)}
                  className={cn(onRowClick && "cursor-pointer hover:bg-muted/50")}
                  onClick={() => onRowClick?.(item)}
                >
                  {columns.map(col => {
                    const visibilityClass = columnVisibilityClass(col);
                    const content = col.renderCell?.(item) ?? item[col.key] ?? '—';

                    if (col.renderMobileCell) {
                      return (
                        <Fragment key={col.key}>
                          <TableCell className="sm:hidden">
                            {col.renderMobileCell(item)}
                          </TableCell>
                          <TableCell className={cn('hidden sm:table-cell', visibilityClass)}>
                            {content}
                          </TableCell>
                        </Fragment>
                      );
                    }

                    return (
                      <TableCell key={col.key} className={visibilityClass}>
                        {content}
                      </TableCell>
                    );
                  })}
                </TableRow>
              ))
            )}
          </TableBody>
        </Table>
      </div>
    </div>
  );
}
