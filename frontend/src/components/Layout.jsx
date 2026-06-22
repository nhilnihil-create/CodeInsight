import { useLocation } from "react-router-dom";
import { cn } from "@/lib/utils";
import Sidebar from "./Sidebar";
import { useSidebar } from "../context/SidebarContext";

const CODE_EDITOR_EXACT = new Set(["/student/code-editor"]);
const CODE_EDITOR_EXERCISE_RE = /^\/student\/exercises\/[^/]+/;

export default function Layout({ children }) {
  const { pathname } = useLocation();
  const { isOpen } = useSidebar();

  const isCodeEditor =
    CODE_EDITOR_EXACT.has(pathname) ||
    pathname.startsWith("/student/code-editor/") ||
    CODE_EDITOR_EXERCISE_RE.test(pathname);

  return (
    <div className="h-screen w-screen overflow-hidden flex bg-[#0B0F19]">
      <Sidebar />
      <main
        className={cn(
          "flex-1 h-full flex flex-col overflow-hidden transition-[margin] duration-300 ease-in-out",
          isOpen ? "ml-[220px]" : "ml-[70px]"
        )}
      >
        <div
          className={cn(
            "mesh-bg noise-overlay relative flex w-full flex-1 flex-col",
            isCodeEditor
              ? "max-w-none p-0 overflow-hidden"
              : "overflow-y-auto custom-scroll p-6 lg:p-8"
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
