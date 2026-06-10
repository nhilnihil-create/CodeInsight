import Sidebar from "./Sidebar";
import { useSidebar } from "../context/SidebarContext";
import { useLocation } from "react-router-dom";
import { cn } from "@/lib/utils";

/**
 * App shell — scroll discipline (2026-06-09 refactor).
 *
 * Root:        h-screen overflow-hidden — viewport-locked, no browser scroll.
 * Sidebar:     fixed left, own vertical scroll, decoupled from content.
 * Main:        flex-1 flex flex-col h-full overflow-hidden — no scroll here.
 * ContentPane: THE SOLE scroll container. flex-1 overflow-y-auto with
 *              custom-scroll thin tracking so only this pane scrolls.
 *
 * Code editor exception: Monaco editor is edge-to-edge (no padding, no
 * max-width) and the theme toggle is hidden on it. The code editor paths are:
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
    <div className="flex h-screen bg-slate-950 text-slate-50 overflow-hidden">
      <Sidebar />
      <main
        className={cn(
          "flex h-screen w-full flex-1 flex-col overflow-hidden bg-slate-950/95 transition-[margin] duration-300 ease-in-out",
          isOpen ? "ml-[220px]" : "ml-[70px]"
        )}
      >
        <div
          className={cn(
            "flex w-full flex-1 flex-col overflow-y-auto custom-scroll",
            isCodeEditor ? "max-w-none p-0" : "p-6 lg:p-8"
          )}
        >
          {children}
        </div>
      </main>
    </div>
  );
}
