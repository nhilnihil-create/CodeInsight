import { useState } from "react";
import {
  Check,
  X,
  Clock,
  Inbox,
  Send,
  Pencil,
  Play,
  FileEdit,
  History as HistoryIcon,
} from "lucide-react";
import { ScrollArea } from "@/components/ui/scroll-area";
import { cn } from "@/lib/utils";

/**
 * SubmissionsPanel
 * Right pane of the desktop workbench. Two sections:
 *   - Submissions  rich cards (status / input / expected / got / timestamp)
 *   - History      timeline of edits, runs, submissions
 *
 * No collapse: panel stays visible (handled by workbench minSize=15).
 *
 * Tokens only.
 */
const STATUS_META = {
  accepted:    { Icon: Check, label: "Passed",       cls: "bg-success/10 text-success border-success/30",     IconCls: "text-success" },
  wrong_answer:{ Icon: X,     label: "Failed",       cls: "bg-destructive/10 text-destructive border-destructive/30", IconCls: "text-destructive" },
  time_limit:  { Icon: Clock, label: "Time Limit",   cls: "bg-warning/10 text-warning border-warning/30",     IconCls: "text-warning" },
  runtime:     { Icon: X,     label: "Runtime",      cls: "bg-destructive/10 text-destructive border-destructive/30", IconCls: "text-destructive" },
  pending:     { Icon: Clock, label: "Pending",      cls: "bg-muted text-muted-foreground border-border",     IconCls: "text-muted-foreground" },
};

const HISTORY_META = {
  submission: { Icon: Send,    IconCls: "text-primary" },
  run:        { Icon: Play,    IconCls: "text-info" },
  edit:       { Icon: Pencil,  IconCls: "text-muted-foreground" },
  open:       { Icon: FileEdit,IconCls: "text-muted-foreground" },
};

export default function SubmissionsPanel({ submissions = [], history = [] }) {
  return (
    <div className="flex flex-col h-full min-h-0 bg-card border-l border-border">
      <Section
        icon={Inbox}
        title="Submissions"
        badge={submissions.length > 0 ? submissions.length : null}
        className="flex-1 min-h-0"
      >
        <SubmissionsList submissions={submissions} />
      </Section>

      <Section
        icon={HistoryIcon}
        title="History"
        className="flex-1 min-h-0 border-t border-border"
      >
        <HistoryList history={history} />
      </Section>
    </div>
  );
}

function Section({ icon: Icon, title, badge, className, children }) {
  return (
    <section className={cn("flex flex-col min-h-0", className)}>
      <header className="flex items-center gap-2 h-9 px-3 border-b border-border bg-card shrink-0">
        <Icon className="h-3.5 w-3.5 text-muted-foreground" strokeWidth={1.5} aria-hidden="true" />
        <h2 className="text-xs font-semibold tracking-tight">{title}</h2>
        {badge != null ? (
          <span className="inline-flex items-center px-1.5 py-0.5 rounded-full text-[10px] font-mono tabular-nums bg-muted text-muted-foreground">
            {badge}
          </span>
        ) : null}
      </header>
      <div className="flex-1 min-h-0 overflow-hidden">{children}</div>
    </section>
  );
}

function SubmissionsList({ submissions }) {
  if (!submissions || submissions.length === 0) {
    return (
      <div className="h-full flex flex-col items-center justify-center p-6 text-center text-xs text-muted-foreground">
        <Inbox className="h-5 w-5 mb-2 opacity-60" strokeWidth={1.5} />
        No submissions yet.
      </div>
    );
  }

  return (
    <ScrollArea className="h-full">
      <ul className="divide-y divide-border" role="list">
        {submissions.map((s) => {
          const meta = STATUS_META[s.status] ?? STATUS_META.pending;
          const Icon = meta.Icon;
          return (
            <li
              key={s.id}
              className={cn(
                "px-3 py-3 hover:bg-muted/30 cursor-pointer transition-colors",
                "border-l-2",
                s.status === "accepted"
                  ? "border-l-success/60"
                  : s.status === "wrong_answer" || s.status === "runtime"
                    ? "border-l-destructive/60"
                    : s.status === "time_limit"
                      ? "border-l-warning/60"
                      : "border-l-transparent",
              )}
            >
              <div className="flex items-center gap-2.5">
                <div
                  className={cn(
                    "flex h-7 w-7 items-center justify-center rounded-md border shrink-0",
                    meta.cls,
                  )}
                >
                  <Icon className={cn("h-3.5 w-3.5", meta.IconCls)} strokeWidth={2} aria-hidden="true" />
                </div>
                <div className="min-w-0 flex-1">
                  <div className="flex items-center gap-2 min-w-0">
                    <p className="text-sm font-medium truncate">{meta.label}</p>
                    <span className="text-[10px] text-muted-foreground font-mono tabular-nums shrink-0">
                      #{s.id}
                    </span>
                  </div>
                  <p className="text-xs text-muted-foreground">
                    {s.passed}/{s.total} tests · {s.runtime} · {s.memory}
                  </p>
                </div>
                <span className="text-[11px] text-muted-foreground font-mono tabular-nums shrink-0">
                  {s.timestamp}
                </span>
              </div>

              {/* Detail rows: input / expected / got */}
              {(s.input != null || s.expected != null || s.actual != null) ? (
                <dl className="mt-2 grid grid-cols-[auto_1fr] gap-x-2 gap-y-0.5 text-[11px] font-mono">
                  {s.input != null ? (
                    <>
                      <dt className="text-muted-foreground">Input</dt>
                      <dd className="text-foreground truncate">{s.input}</dd>
                    </>
                  ) : null}
                  {s.expected != null ? (
                    <>
                      <dt className="text-muted-foreground">Expected</dt>
                      <dd className="text-foreground truncate">{s.expected}</dd>
                    </>
                  ) : null}
                  {s.actual != null ? (
                    <>
                      <dt className="text-muted-foreground">Got</dt>
                      <dd
                        className={cn(
                          "truncate",
                          s.status === "accepted"
                            ? "text-success"
                            : "text-destructive",
                        )}
                      >
                        {s.actual}
                      </dd>
                    </>
                  ) : null}
                </dl>
              ) : null}
            </li>
          );
        })}
      </ul>
    </ScrollArea>
  );
}

function HistoryList({ history }) {
  if (!history || history.length === 0) {
    return (
      <div className="h-full flex flex-col items-center justify-center p-6 text-center text-xs text-muted-foreground">
        <HistoryIcon className="h-5 w-5 mb-2 opacity-60" strokeWidth={1.5} />
        No history yet.
      </div>
    );
  }

  return (
    <ScrollArea className="h-full">
      <ol className="relative px-4 py-3" role="list">
        <span
          className="absolute left-[27px] top-3 bottom-3 w-px bg-border"
          aria-hidden="true"
        />
        {history.map((h) => {
          const meta = HISTORY_META[h.type] ?? HISTORY_META.edit;
          const Icon = meta.Icon;
          return (
            <li key={h.id} className="relative pl-9 py-2">
              <span
                className={cn(
                  "absolute left-2 top-2.5 flex h-5 w-5 items-center justify-center rounded-full bg-card border border-border",
                )}
                aria-hidden="true"
              >
                <Icon className={cn("h-3 w-3", meta.IconCls)} strokeWidth={1.75} />
              </span>
              <div className="flex items-start justify-between gap-2 min-w-0">
                <p className="text-sm leading-snug">{h.label}</p>
                <span className="text-[11px] text-muted-foreground font-mono tabular-nums shrink-0">
                  {h.timestamp}
                </span>
              </div>
            </li>
          );
        })}
      </ol>
    </ScrollArea>
  );
}
