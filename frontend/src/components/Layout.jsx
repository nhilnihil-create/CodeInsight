import { useEffect } from "react";
import { useLocation } from "react-router-dom";
import { Menu } from "lucide-react";
import { cn } from "@/lib/utils";
import Sidebar from "./Sidebar";
import { useSidebar } from "../context/SidebarContext";

const CODE_EDITOR_EXACT = new Set(["/student/code-editor"]);
const CODE_EDITOR_EXERCISE_RE = /^\/student\/exercises\/[^/]+/;

export default function Layout({ children }) {
  const { pathname } = useLocation();
  const { isOpen, toggleSidebar, setOpen } = useSidebar();

  const isCodeEditor =
    CODE_EDITOR_EXACT.has(pathname) ||
    pathname.startsWith("/student/code-editor/") ||
    CODE_EDITOR_EXERCISE_RE.test(pathname);

  // Close the off-canvas drawer on navigation (mobile only; the desktop
  // sidebar must keep its own open/collapsed state).
  useEffect(() => {
    if (!window.matchMedia("(min-width: 1024px)").matches) {
      setOpen(false);
    }
  }, [pathname, setOpen]);

  return (
    <div className="h-dvh w-screen overflow-hidden flex bg-[#0B0F19]">
      <Sidebar />
      {isOpen && (
        <div
          className="fixed inset-0 z-30 bg-black/50 lg:hidden"
          onClick={() => setOpen(false)}
          aria-hidden="true"
        />
      )}
      {!isCodeEditor && !isOpen && (
        <button
          type="button"
          onClick={toggleSidebar}
          aria-label="Open navigation"
          className="fixed top-3 left-3 z-50 lg:hidden flex h-10 w-10 items-center justify-center rounded-xl border border-white/[0.08] bg-[#0E1322]/80 text-muted-foreground backdrop-blur-xl"
        >
          <Menu className="h-5 w-5" />
        </button>
      )}
      <main
        className={cn(
          "flex-1 h-full flex flex-col overflow-hidden transition-[margin] duration-300 ease-in-out",
          isOpen ? "ml-0 lg:ml-[220px]" : "ml-0 lg:ml-[70px]"
        )}
      >
        <div
          className={cn(
            "mesh-bg noise-overlay relative flex w-full flex-1 flex-col",
            isCodeEditor
              ? "max-w-none p-0 overflow-hidden"
              : "overflow-y-auto custom-scroll p-6 lg:p-8 pt-16 lg:pt-8"
          )}
        >
          <div
            className={cn(
              "relative z-10",
              isCodeEditor && "flex-1 min-h-0 flex flex-col"
            )}
          >
            {children}
          </div>
        </div>
      </main>
    </div>
  );
}
