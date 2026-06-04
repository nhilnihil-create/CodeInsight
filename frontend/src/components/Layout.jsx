import Sidebar from './Sidebar';
import { useSidebar } from '../context/SidebarContext';
import { cn } from '@/lib/utils';

/**
 * App shell.
 *
 * PRESERVED:
 *   - {children} API — App.jsx <ProtectedRoute> wrapper does not change
 *   - SidebarContext contract: { isOpen } still drives the main margin
 *
 * REPLACED:
 *   - Added a thin top bar that uses design tokens (border-border / bg-card)
 *     so the page picks up the design's typographic rhythm
 *   - Renders the page title from <title> via the optional `pageTitle` prop
 *   - Children flow in a max-width content area
 */
export default function Layout({ children, pageTitle }) {
  const { isOpen } = useSidebar();

  return (
    <div className="min-h-screen bg-background text-foreground">
      <Sidebar />
      <main
        className={cn(
          'min-h-screen overflow-auto bg-background transition-[margin] duration-300 ease-in-out',
          isOpen ? 'ml-[220px]' : 'ml-[70px]'
        )}
      >
        {pageTitle && (
          <header className="sticky top-0 z-30 border-b border-border bg-card/80 px-6 py-4 backdrop-blur supports-[backdrop-filter]:bg-card/60">
            <h1 className="text-xl font-semibold tracking-tight text-foreground">
              {pageTitle}
            </h1>
          </header>
        )}
        <div className="w-full max-w-7xl mx-auto p-6 lg:p-8">{children}</div>
      </main>
    </div>
  );
}
