import { useState } from "react";
import { Loader2, LogIn } from "lucide-react";
import { toast } from "sonner";
import { Button } from "@/components/ui/button";
import { Input } from "@/components/ui/input";
import StudentDashboardShell from "@/components/student-dashboard-shell";
import api from "@/services/api";

function formatJoinCode(value) {
  const cleaned = value.toUpperCase().replace(/[^A-Z0-9]/g, "");
  if (cleaned.length > 3) {
    return cleaned.slice(0, 3) + "-" + cleaned.slice(3, 6);
  }
  return cleaned;
}

function getJoinErrorMessage(error) {
  const status = error.response?.status;
  const data = error.response?.data;

  if (status === 404) return "Invalid join code. Please check the code and try again.";
  if (status === 403) {
    if (data?.error?.includes("full")) return "This section is full. Contact your instructor for availability.";
    if (data?.error?.includes("closed")) return "This section is not accepting new students at this time.";
    return "You cannot join this section.";
  }
  if (status === 409) return "You are already enrolled in this section.";
  if (status === 401) return "Please log in to join a section.";
  return data?.error || data?.message || "Failed to join section. Please try again.";
}

export default function JoinSectionGate({ onJoined }) {
  const [joinCode, setJoinCode] = useState("");
  const [joining, setJoining] = useState(false);
  const [error, setError] = useState(null);

  const handleCodeChange = (e) => {
    setJoinCode(formatJoinCode(e.target.value));
    setError(null);
  };

  const handleJoin = async () => {
    setError(null);
    setJoining(true);
    try {
      await api.post("/api/sections/join", { code: joinCode });
      toast.success("Successfully joined the section!");
      setJoinCode("");
      if (onJoined) onJoined();
    } catch (err) {
      const msg = getJoinErrorMessage(err);
      toast.error(msg);
      setError(msg);
    } finally {
      setJoining(false);
    }
  };

  return (
    <StudentDashboardShell>
      <div className="flex flex-col items-center justify-center py-16 px-6">
        <div className="w-full max-w-sm space-y-6 text-center">
          <div className="mx-auto h-14 w-14 rounded-full bg-gradient-to-br from-teal-400 to-emerald-500 flex items-center justify-center">
            <LogIn className="h-6 w-6 text-slate-950" strokeWidth={2} />
          </div>
          <div className="space-y-2">
            <h1 className="text-xl font-semibold text-foreground">Join a Section</h1>
            <p className="text-sm text-muted-foreground">
              Enter the join code provided by your instructor to get started.
            </p>
          </div>
          <div className="space-y-3">
            {error && (
              <p className="text-sm text-destructive">{error}</p>
            )}
            <div className="flex gap-2">
              <Input
                placeholder="e.g. K7P-3QX"
                value={joinCode}
                onChange={handleCodeChange}
                onKeyDown={(e) => e.key === "Enter" && joinCode.length === 7 && handleJoin()}
                maxLength={7}
                disabled={joining}
                className="font-mono h-10 text-center text-lg tracking-widest"
              />
              <Button
                size="lg"
                disabled={joinCode.length < 7 || joining}
                onClick={handleJoin}
                className="bg-gradient-to-r from-teal-400 to-emerald-500 text-slate-950 font-semibold hover:shadow-[0_0_24px_rgba(45,212,191,0.4)] transition-shadow duration-300"
              >
                {joining ? (
                  <Loader2 className="h-4 w-4 animate-spin" />
                ) : (
                  "Join"
                )}
              </Button>
            </div>
            <p className="text-xs text-muted-foreground/50">
              Ask your instructor for the 6-character code (e.g. K7P-3QX).
            </p>
          </div>
        </div>
      </div>
    </StudentDashboardShell>
  );
}
