import { useState } from "react";
import { useNavigate } from "react-router-dom";
import { Loader2, LogIn, ArrowLeft, LogOut } from "lucide-react";
import { toast } from "sonner";
import { Button } from "@/components/ui/button";
import { Input } from "@/components/ui/input";
import { useAuth } from "@/context/AuthContext";
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

/**
 * JoinSectionGate
 * Standalone full-screen join-by-code gate (no sidebar, no shell).
 *
 * Props
 *   - onJoined  () => void — called after a successful join
 *   - onBack    () => void — when provided, renders a "Back to classes" link
 */
export default function JoinSectionGate({ onJoined, onBack }) {
  const [joinCode, setJoinCode] = useState("");
  const [joining, setJoining] = useState(false);
  const [error, setError] = useState(null);
  const { logout } = useAuth();
  const navigate = useNavigate();

  const handleLogout = async () => {
    await logout();
    navigate("/login", { replace: true });
  };

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
      // 409 means the student is already enrolled — treat it as success
      // in disguise: confirm with a toast, clear the input, and hand off to
      // the caller instead of showing a dead-end error.
      if (err.response?.status === 409) {
        toast.success(getJoinErrorMessage(err));
        setJoinCode("");
        if (onBack) onBack();
        if (onJoined) onJoined();
      } else {
        const msg = getJoinErrorMessage(err);
        toast.error(msg);
        setError(msg);
      }
    } finally {
      setJoining(false);
    }
  };

  return (
    <div className="mesh-bg noise-overlay min-h-screen bg-[#0B0F19] text-foreground">
      <div className="relative z-10 mx-auto max-w-6xl px-6 py-8">
        {/* Top bar */}
        <div className="flex items-center justify-between gap-4 mb-10">
          {onBack ? (
            <button
              type="button"
              onClick={onBack}
              className="inline-flex items-center gap-1.5 text-xs font-medium text-muted-foreground transition-colors hover:text-primary"
            >
              <ArrowLeft className="h-3.5 w-3.5" strokeWidth={2} />
              Back to classes
            </button>
          ) : <span />}
          <Button
            variant="ghost"
            size="sm"
            onClick={handleLogout}
            className="text-muted-foreground hover:text-foreground"
          >
            <LogOut className="h-4 w-4 mr-1.5" strokeWidth={2} />
            Logout
          </Button>
        </div>

        <div className="flex flex-col items-center justify-center">
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
      </div>
    </div>
  );
}
