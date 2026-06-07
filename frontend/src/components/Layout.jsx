import Sidebar from "./Sidebar";
import ThemeToggle from "./ThemeToggle";
import { useSidebar } from "../context/SidebarContext";
import { useLocation } from "react-router-dom";
import { cn } from "@/lib/utils";

/**
 * App shell.
 *
 * - Sidebar: fixed h-screen, drives the main margin via SidebarContext.
 * - Main:    h-screen, flex column, overflow-hidden, ml-[220|70] for sidebar.
 * - Content: flex column, overflow-auto, with the standard
 *            max-w-7xl mx-auto p-6 lg:p-8 gutter.
 *
 * Code editor exception: the Monaco editor is edge-to-edge and the
 * theme toggle is hidden on it. The code editor paths are:
 *   - /student/code-editor
 *   - /student/code-editor/:exerciseId
 *   - /student/exercises/:exerciseId  (the exercise detail IS the editor)
 * The bare /student/exercises list page is NOT a code editor and keeps
 * the standard gutter.
 *
 * `pageTitle` was removed (2026-06-06): it was never rendered — Layout
 * just dropped it on the floor. Page-level headers now live in
 * <StudentDashboardShell> instead.
 */
const CODE_EDITOR_EXACT = new Set(["/student/code-editor"]);
const CODE_EDITOR_EXERCISE_RE = /^\/student\/exercises\/[^/]+/;

export default function Layout({ children }) {
  const { isOpen } = useSidebar();
  const { pathname } = useLocation();

  const isCodeEditor =
    CODE_EDITOR_EXACT.has(pathname) ||
    pathname.startsWith("/student/code-editor/") ||
    CODE_EDITOR_EXERCISE_RE.test(pathname);

  return (
    <div className="flex h-screen bg-background text-foreground overflow-hidden">
      <Sidebar />
      <main
        className={cn(
          "flex h-screen w-full flex-1 flex-col overflow-hidden bg-background transition-[margin] duration-300 ease-in-out",
          isOpen ? "ml-[220px]" : "ml-[70px]"
        )}
      >
        <div
          className={cn(
            "flex w-full flex-1 flex-col overflow-auto",
            isCodeEditor ? "max-w-none p-0" : "max-w-7xl mx-auto p-6 lg:p-8"
          )}
        >
          {children}
        </div>
      </main>
      {!isCodeEditor ? (
        <div className="fixed right-4 top-4 z-50" aria-label="Theme toggle">
          <ThemeToggle />
        </div>
      ) : null}
    </div>
  );
}
