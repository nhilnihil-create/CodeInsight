import Sidebar from './Sidebar';
import ThemeToggle from './ThemeToggle';
import { useSidebar } from '../context/SidebarContext';
import { cn } from '@/lib/utils';

/**
 * App shell.
 *
 * PRESERVED:
 *   - {children} API — App.jsx <ProtectedRoute> wrapper does not change
 *   - SidebarContext contract: { isOpen } still drives the main margin
 *
 * CHANGED (per user directive 2026-06-05):
 *   - Removed the sticky page-title header bar. The sidebar already gives
 *     every protected route navigation context, and each page owns its
 *     own internal h1 styling, so the duplicate chrome was unnecessary.
 *     The `pageTitle` prop is accepted (still passed by ProtectedRoute)
 *     for backwards compatibility but is no longer rendered.
 *   - ThemeToggle moved to a fixed top-right corner control so light/dark
 *     teal switching stays one click away on every page.
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
        <div className="w-full max-w-7xl mx-auto p-6 lg:p-8">{children}</div>
      </main>
      <div
        className="fixed right-4 top-4 z-50"
        aria-label="Theme toggle"
        data-page-title={pageTitle}
      >
        <ThemeToggle />
      </div>
    </div>
  );
}
