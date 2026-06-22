import { Table, TableHeader, TableBody, TableRow, TableHead, TableCell } from '@/components/ui/table';
import { cn } from '@/lib/utils';

export function ResponsiveTable({ columns, data, keyExtractor, onRowClick, emptyMessage = "No data found." }) {
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
                <TableCell colSpan={columns.length} className="text-center text-muted-foreground py-6">
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
                  {columns.map(col => (
                    <TableCell key={col.key}>
                      {col.renderCell?.(item) ?? item[col.key] ?? '—'}
                    </TableCell>
                  ))}
                </TableRow>
              ))
            )}
          </TableBody>
        </Table>
      </div>
    </div>
  );
}
