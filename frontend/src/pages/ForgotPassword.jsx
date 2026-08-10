import { useState } from 'react';
import { useNavigate, Link } from 'react-router-dom';
import { Loader2, AlertCircle, ArrowLeft, Eye, EyeOff, CheckCircle2, Mail, Key } from 'lucide-react';
import api from '../services/api';
import { Button } from '@/components/ui/button';
import { Input } from '@/components/ui/input';
import { Label } from '@/components/ui/label';
import {
  Card,
  CardContent,
  CardDescription,
  CardFooter,
  CardHeader,
  CardTitle,
} from '@/components/ui/card';

const passwordReqs = [
  { label: 'At least 8 characters', test: (p) => p.length >= 8 },
  { label: 'One uppercase letter', test: (p) => /[A-Z]/.test(p) },
  { label: 'One lowercase letter', test: (p) => /[a-z]/.test(p) },
  { label: 'One digit', test: (p) => /[0-9]/.test(p) },
  { label: 'One special character', test: (p) => /[^a-zA-Z0-9]/.test(p) },
];

/**
 * ForgotPassword
 * 4-step password reset flow (email → otp → password → success).
 * The OTP is only ever consumed server-side by /api/auth/reset-password;
 * the otp step here is a plain input screen.
 */
export default function ForgotPassword() {
  const [step, setStep] = useState('email');
  const [email, setEmail] = useState('');
  const [otp, setOtp] = useState('');
  const [password, setPassword] = useState('');
  const [confirmPassword, setConfirmPassword] = useState('');
  const [error, setError] = useState('');
  const [loading, setLoading] = useState(false);
  const [showPassword, setShowPassword] = useState(false);
  const [showConfirmPassword, setShowConfirmPassword] = useState(false);
  const navigate = useNavigate();

  const confirmMismatch = confirmPassword.length > 0 && password !== confirmPassword;

  const requestReset = async () => {
    setError('');
    setLoading(true);
    try {
      const res = await api.post('/api/auth/forgot-password', { email });
      if (res.data.otp) {
        setOtp(res.data.otp);
      }
      setStep('otp');
    } catch (err) {
      setError(err.response?.data?.message || 'Failed to request password reset');
    } finally {
      setLoading(false);
    }
  };

  const handleEmailSubmit = async (e) => {
    e.preventDefault();
    await requestReset();
  };

  const handleOtpSubmit = (e) => {
    e.preventDefault();
    setError('');
    setStep('password');
  };

  const handlePasswordSubmit = async (e) => {
    e.preventDefault();
    setError('');

    const failed = passwordReqs.filter((r) => !r.test(password));
    if (failed.length) {
      setError('Password must include: ' + failed.map((r) => r.label.toLowerCase()).join(', '));
      return;
    }
    if (confirmMismatch) {
      setError('Passwords do not match');
      return;
    }

    setLoading(true);
    try {
      await api.post('/api/auth/reset-password', { email, otp, password });
      setStep('success');
    } catch (err) {
      const msg = err.response?.data?.message || 'Failed to reset password';
      if (err.response?.status === 400) {
        // Invalid / expired / exhausted OTP — send the user back to the code screen.
        setError(msg);
        setStep('otp');
      } else {
        setError(msg);
      }
    } finally {
      setLoading(false);
    }
  };

  // ---------- OTP step ----------
  if (step === 'otp') {
    return (
      <div className="flex min-h-screen items-center justify-center bg-muted/30 px-4 py-8 text-foreground">
        <div className="w-full max-w-md space-y-4">
          <Card className="border-border/50 shadow-xl">
            <CardHeader className="space-y-1 text-center">
              <CardTitle className="text-2xl font-bold tracking-tight">Check your email</CardTitle>
              <CardDescription>
                We sent a 6-digit code to <strong>{email}</strong>
              </CardDescription>
            </CardHeader>
            <CardContent className="space-y-4">
              {error && (
                <div
                  role="alert"
                  className="flex items-start gap-2 rounded-md border border-destructive/30 bg-destructive/10 px-3 py-2.5 text-[12.5px] text-destructive"
                >
                  <AlertCircle className="mt-0.5 h-3.5 w-3.5 shrink-0" />
                  <span>{error}</span>
                </div>
              )}
              <form onSubmit={handleOtpSubmit} className="space-y-3.5">
                <div className="space-y-1.5">
                  <Label htmlFor="otp">RESET CODE</Label>
                  <Input
                    id="otp"
                    type="text"
                    inputMode="numeric"
                    pattern="[0-9]{6}"
                    value={otp}
                    onChange={(e) => setOtp(e.target.value.replace(/\D/g, '').slice(0, 6))}
                    placeholder="000000"
                    required
                    className="text-center text-2xl tracking-[8px]"
                    maxLength={6}
                    autoFocus
                  />
                </div>
                <Button
                  type="submit"
                  disabled={loading || otp.length !== 6}
                  className="h-11 w-full text-[13px] font-bold"
                >
                  {loading ? (
                    <><Loader2 className="mr-2 h-4 w-4 animate-spin" /> Sending...</>
                  ) : (
                    <><Key className="mr-2 h-4 w-4" /> Continue</>
                  )}
                </Button>
              </form>
            </CardContent>
            <CardFooter className="flex flex-col gap-3 border-t p-6">
              <p className="text-xs text-muted-foreground">
                Didn't get the code?{' '}
                <button
                  onClick={requestReset}
                  className="font-medium text-primary hover:underline"
                  disabled={loading}
                >
                  Resend
                </button>
              </p>
              <button
                onClick={() => { setStep('email'); setOtp(''); setError(''); }}
                className="text-xs text-muted-foreground hover:text-foreground"
              >
                Change email
              </button>
            </CardFooter>
          </Card>
        </div>
      </div>
    );
  }

  // ---------- Success step ----------
  if (step === 'success') {
    return (
      <div className="flex min-h-screen items-center justify-center bg-muted/30 px-4 py-8 text-foreground">
        <div className="w-full max-w-md space-y-4">
          <Card className="border-border/50 shadow-xl">
            <CardHeader className="space-y-1 text-center">
              <div className="mx-auto flex h-14 w-14 items-center justify-center rounded-full bg-green-500/15">
                <CheckCircle2 className="h-7 w-7 text-green-500" strokeWidth={2} />
              </div>
              <CardTitle className="text-2xl font-bold tracking-tight">Password reset successful</CardTitle>
              <CardDescription>
                Your password has been updated. Sign in with your new password to continue.
              </CardDescription>
            </CardHeader>
            <CardContent className="flex flex-col gap-3">
              <Button
                onClick={() => navigate('/login', { replace: true })}
                className="h-11 w-full text-[13px] font-bold"
              >
                Back to login
              </Button>
            </CardContent>
          </Card>
        </div>
      </div>
    );
  }

  // ---------- Password step ----------
  if (step === 'password') {
    return (
      <div className="flex min-h-screen items-center justify-center bg-muted/30 px-4 py-8 text-foreground">
        <div className="w-full max-w-md space-y-4">
          <div className="flex items-center justify-center">
            <Link
              to="/"
              className="inline-flex items-center gap-1.5 text-xs font-medium text-muted-foreground transition-colors hover:text-primary"
            >
              <ArrowLeft className="h-3 w-3" />
              Back to home
            </Link>
          </div>
          <Card className="border-border/50 shadow-xl">
            <CardHeader className="space-y-1 text-center">
              <CardTitle className="text-2xl font-bold tracking-tight">Set a new password</CardTitle>
              <CardDescription>
                Create a new password for <strong>{email}</strong>
              </CardDescription>
            </CardHeader>
            <CardContent className="space-y-4">
              {error && (
                <div
                  role="alert"
                  className="flex items-start gap-2 rounded-md border border-destructive/30 bg-destructive/10 px-3 py-2.5 text-[12.5px] text-destructive"
                >
                  <AlertCircle className="mt-0.5 h-3.5 w-3.5 shrink-0" />
                  <span>{error}</span>
                </div>
              )}
              <form onSubmit={handlePasswordSubmit} className="space-y-3.5">
                <div className="space-y-1.5">
                  <Label htmlFor="newPassword">NEW PASSWORD</Label>
                  <div className="relative">
                    <Input
                      id="newPassword"
                      type={showPassword ? 'text' : 'password'}
                      value={password}
                      onChange={(e) => setPassword(e.target.value)}
                      placeholder="••••••••"
                      required
                      minLength={8}
                      autoComplete="new-password"
                      className="pr-10"
                    />
                    <button
                      type="button"
                      onClick={() => setShowPassword(!showPassword)}
                      className="absolute right-3 top-1/2 -translate-y-1/2 text-muted-foreground hover:text-foreground"
                      tabIndex={-1}
                    >
                      {showPassword ? <EyeOff className="h-4 w-4" /> : <Eye className="h-4 w-4" />}
                    </button>
                  </div>
                </div>
                <div className="space-y-1.5">
                  <Label htmlFor="confirmPassword">CONFIRM PASSWORD</Label>
                  <div className="relative">
                    <Input
                      id="confirmPassword"
                      type={showConfirmPassword ? 'text' : 'password'}
                      value={confirmPassword}
                      onChange={(e) => setConfirmPassword(e.target.value)}
                      placeholder="••••••••"
                      required
                      autoComplete="new-password"
                      className="pr-10"
                    />
                    <button
                      type="button"
                      onClick={() => setShowConfirmPassword(!showConfirmPassword)}
                      className="absolute right-3 top-1/2 -translate-y-1/2 text-muted-foreground hover:text-foreground"
                      tabIndex={-1}
                    >
                      {showConfirmPassword ? <EyeOff className="h-4 w-4" /> : <Eye className="h-4 w-4" />}
                    </button>
                  </div>
                </div>
                {confirmMismatch && (
                  <p className="text-xs text-destructive">Passwords do not match</p>
                )}
                <div className="space-y-1 text-[11px] text-muted-foreground">
                  {passwordReqs.map((r) => (
                    <p key={r.label} className={r.test(password) ? 'text-green-600' : ''}>
                      {r.test(password) ? <CheckCircle2 className="inline h-3 w-3 mr-1" /> : <span className="inline-block w-3 h-3 mr-1" />}
                      {r.label}
                    </p>
                  ))}
                </div>
                <Button
                  type="submit"
                  disabled={loading || confirmMismatch}
                  className="h-11 w-full text-[13px] font-bold"
                >
                  {loading ? (
                    <><Loader2 className="mr-2 h-4 w-4 animate-spin" /> Updating password...</>
                  ) : (
                    <><Key className="mr-2 h-4 w-4" /> Update Password</>
                  )}
                </Button>
              </form>
            </CardContent>
          </Card>
        </div>
      </div>
    );
  }

  // ---------- Email step ----------
  return (
    <div className="flex min-h-screen items-center justify-center bg-muted/30 px-4 py-8 text-foreground">
      <div className="w-full max-w-md space-y-4">
        <div className="flex items-center justify-center">
          <Link
            to="/"
            className="inline-flex items-center gap-1.5 text-xs font-medium text-muted-foreground transition-colors hover:text-primary"
          >
            <ArrowLeft className="h-3 w-3" />
            Back to home
          </Link>
        </div>
        <Card className="border-border/50 shadow-xl">
          <CardHeader className="space-y-1 text-center">
            <div className="mx-auto mb-2 font-mono text-2xl font-bold text-primary">
              Code<span className="text-secondary-foreground">Insight</span>
            </div>
            <CardTitle className="text-2xl font-bold tracking-tight">Reset your password</CardTitle>
            <CardDescription>
              Enter your account email and we&apos;ll send you a password reset code.
            </CardDescription>
          </CardHeader>
          <CardContent className="space-y-4">
            {error && (
              <div
                role="alert"
                className="flex items-start gap-2 rounded-md border border-destructive/30 bg-destructive/10 px-3 py-2.5 text-[12.5px] text-destructive"
              >
                <AlertCircle className="mt-0.5 h-3.5 w-3.5 shrink-0" />
                <span>{error}</span>
              </div>
            )}
            <form onSubmit={handleEmailSubmit} className="space-y-3.5">
              <div className="space-y-1.5">
                <Label htmlFor="email">EMAIL</Label>
                <Input
                  id="email"
                  type="email"
                  value={email}
                  onChange={(e) => setEmail(e.target.value)}
                  placeholder="your@email.com"
                  required
                  autoComplete="email"
                />
              </div>
              <Button
                type="submit"
                disabled={loading}
                className="h-11 w-full text-[13px] font-bold"
              >
                {loading ? (
                  <><Loader2 className="mr-2 h-4 w-4 animate-spin" /> Sending code...</>
                ) : (
                  <><Mail className="mr-2 h-4 w-4" /> Send Reset Code</>
                )}
              </Button>
            </form>
          </CardContent>
          <CardFooter className="flex justify-center border-t p-6">
            <p className="text-xs text-muted-foreground">
              Remembered your password?{' '}
              <Link to="/login" className="font-medium text-primary hover:underline">Sign in</Link>
            </p>
          </CardFooter>
        </Card>
      </div>
    </div>
  );
}
