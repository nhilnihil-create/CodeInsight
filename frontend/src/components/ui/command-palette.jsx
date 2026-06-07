import { useEffect } from "react";
import { Command } from "cmdk";

/**
 * CommandPalette
 * Global ⌘K / Ctrl+K command palette. Built on cmdk.
 *
 * Props
 *   - open     boolean  (controlled by parent)
 *   - onClose  () => void
 *   - groups   Array<{ heading: string, items: Array<{ id, icon, label, kbd?, onSelect? }> }>
 *
 * Trigger   global Cmd+K / Ctrl+K listener (in useEffect) — dispatches a
 *           'codeinsight:toggle-palette' CustomEvent that the parent listens to
 *           and uses to flip its `open` state. The component itself does not
 *           own the open state.
 *
 * Container fixed inset-0 z-50 bg-black/50
 * Inner     max-w-lg mx-auto mt-[20vh] rounded-lg border border-border
 *           bg-popover shadow-md overflow-hidden
 * Input     h-12 px-4 text-sm border-b border-border bg-transparent outline-none
 * Item      flex items-center gap-3 px-4 h-10 text-sm cursor-pointer
 *           hover:bg-accent rounded-md transition-colors
 *
 * Tokens only.
 */
export default function CommandPalette({ open, onClose, groups = [] }) {
  useEffect(() => {
    const handler = (e) => {
      if ((e.metaKey || e.ctrlKey) && e.key.toLowerCase() === "k") {
        e.preventDefault();
        window.dispatchEvent(
          new CustomEvent("codeinsight:toggle-palette"),
        );
      }
    };
    window.addEventListener("keydown", handler);
    return () => window.removeEventListener("keydown", handler);
  }, []);

  return (
    <Command.Dialog
      open={open}
      onOpenChange={(next) => {
        if (!next) onClose?.();
      }}
      label="Command palette"
      className="fixed inset-0 z-50 bg-black/50"
      shouldFilter
    >
      <div className="max-w-lg mx-auto mt-[20vh] rounded-lg border border-border bg-popover shadow-md overflow-hidden">
        <Command.Input
          placeholder="Type a command or search…"
          className="h-12 px-4 text-sm border-b border-border bg-transparent outline-none w-full text-foreground placeholder:text-muted-foreground"
        />
        <Command.List className="max-h-80 overflow-y-auto p-2">
          <Command.Empty className="px-4 py-6 text-sm text-muted-foreground text-center">
            No results found.
          </Command.Empty>
          {groups.map((group) => (
            <Command.Group
              key={group.heading}
              heading={group.heading}
              className="px-1 py-1 [&_[cmdk-group-heading]]:px-3 [&_[cmdk-group-heading]]:py-1.5 [&_[cmdk-group-heading]]:text-[10px] [&_[cmdk-group-heading]]:font-semibold [&_[cmdk-group-heading]]:uppercase [&_[cmdk-group-heading]]:tracking-wider [&_[cmdk-group-heading]]:text-muted-foreground"
            >
              {group.items.map((item) => (
                <Command.Item
                  key={item.id}
                  value={item.label}
                  onSelect={() => {
                    item.onSelect?.();
                  }}
                  className="flex items-center gap-3 px-4 h-10 text-sm cursor-pointer rounded-md transition-colors text-foreground hover:bg-accent aria-selected:bg-accent"
                >
                  {item.icon ? (
                    <span
                      className="shrink-0 text-muted-foreground"
                      aria-hidden="true"
                    >
                      {item.icon}
                    </span>
                  ) : null}
                  <span className="flex-1 truncate">{item.label}</span>
                  {item.kbd ? (
                    <kbd className="text-[10px] font-mono text-muted-foreground bg-muted px-1.5 py-0.5 rounded border border-border">
                      {item.kbd}
                    </kbd>
                  ) : null}
                </Command.Item>
              ))}
            </Command.Group>
          ))}
        </Command.List>
      </div>
    </Command.Dialog>
  );
}
