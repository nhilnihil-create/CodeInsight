import { useState } from 'react';
import { useNavigate, Link } from 'react-router-dom';
import { Loader2, AlertCircle, Eye, EyeOff, CheckCircle2, Circle, Mail, Key } from 'lucide-react';
import api from '../services/api';
import { useAuth } from '../context/AuthContext';
import { Button } from '@/components/ui/button';
import { Input } from '@/components/ui/input';
import { Label } from '@/components/ui/label';
import GoogleAuthButton from '@/components/GoogleAuthButton';
import AuthShell from '@/components/auth/AuthShell';
import {
  Card,
  CardContent,
  CardDescription,
  CardFooter,
  CardHeader,
  CardTitle,
} from '@/components/ui/card';

export default function Register() {
  const [step, setStep] = useState('form');
  const [name, setName] = useState('');
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  const [otp, setOtp] = useState('');
  const [role, setRole] = useState('student');
  const [error, setError] = useState('');
  const [loading, setLoading] = useState(false);
  const [showPassword, setShowPassword] = useState(false);
  const { login } = useAuth();
  const navigate = useNavigate();

  const passwordReqs = [
    { label: 'At least 8 characters', test: (p) => p.length >= 8 },
    { label: 'One uppercase letter', test: (p) => /[A-Z]/.test(p) },
    { label: 'One lowercase letter', test: (p) => /[a-z]/.test(p) },
    { label: 'One digit', test: (p) => /[0-9]/.test(p) },
    { label: 'One special character', test: (p) => /[^a-zA-Z0-9]/.test(p) },
  ];

  const handleRequestOtp = async (e) => {
    e.preventDefault();
    setError('');

    const failed = passwordReqs.filter(r => !r.test(password));
    if (failed.length) {
      setError('Password must include: ' + failed.map(r => r.label.toLowerCase()).join(', '));
      return;
    }

    setLoading(true);
    try {
      const res = await api.post('/api/auth/request-otp', { email });
      if (res.data.otp) {
        setOtp(res.data.otp);
      }
      setStep('otp');
    } catch (err) {
      setError(err.response?.data?.message || 'Failed to request verification code');
    } finally {
      setLoading(false);
    }
  };

  const handleVerifyOtp = async (e) => {
    e.preventDefault();
    setError('');
    setLoading(true);

    try {
      const res = await api.post('/api/auth/verify-otp', { email, otp, name, password, role });
      login(res.data.user);
      const userRole = res.data.user.role;
      const dest = userRole === 'instructor' ? '/instructor/dashboard' : '/student/dashboard';
      navigate(dest, { replace: true });
    } catch (err) {
      setError(err.response?.data?.message || 'Verification failed');
    } finally {
      setLoading(false);
    }
  };

  if (step === 'otp') {
    return (
      <AuthShell>
        <Card variant="dense">
          <CardHeader className="space-y-1 text-center">
            <CardTitle className="text-2xl font-bold tracking-tight">Check your email</CardTitle>
            <CardDescription>
              We sent a 6-digit code to <strong>{email}</strong>
            </CardDescription>
          </CardHeader>
          <CardContent className="space-y-4">
            <div aria-live="polite" className="space-y-3">
              {error && (
                <div
                  role="alert"
                  className="flex items-start gap-2 rounded-md border border-destructive/30 bg-destructive/10 px-3 py-2.5 text-[12.5px] text-destructive"
                >
                  <AlertCircle className="mt-0.5 h-3.5 w-3.5 shrink-0" />
                  <span>{error}</span>
                </div>
              )}
            </div>
            <form onSubmit={handleVerifyOtp} className="space-y-4">
              <div className="space-y-1.5">
                <Label htmlFor="otp">VERIFICATION CODE</Label>
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
                  <><Loader2 className="mr-2 h-4 w-4 animate-spin" /> Verifying...</>
                ) : (
                  <><Key className="mr-2 h-4 w-4" /> Verify & Create Account</>
                )}
              </Button>
            </form>
          </CardContent>
          <CardFooter className="flex flex-col gap-3 border-t p-6">
            <p className="text-xs text-muted-foreground">
              Didn't get the code?{' '}
              <button
                type="button"
                onClick={handleRequestOtp}
                className="font-medium text-primary hover:underline disabled:pointer-events-none disabled:opacity-50"
                disabled={loading}
              >
                Resend
              </button>
            </p>
            <button
              type="button"
              onClick={() => { setStep('form'); setError(''); }}
              className="text-xs text-muted-foreground transition-colors hover:text-foreground"
            >
              Use a different email
            </button>
          </CardFooter>
        </Card>
      </AuthShell>
    );
  }

  return (
    <AuthShell showBackLink>
      <Card variant="dense">
        <CardHeader className="space-y-1 text-center">
          <div className="mx-auto mb-2 font-mono text-2xl font-bold text-primary">
            Code<span className="text-secondary-foreground">Insight</span>
          </div>
          <CardTitle className="text-2xl font-bold tracking-tight">Create your account</CardTitle>
          <CardDescription>
            Join CodeInsight · Pampanga State University · CCS
          </CardDescription>
        </CardHeader>
        <CardContent className="space-y-4">
          <div aria-live="polite" className="space-y-3">
            {error && (
              <div
                role="alert"
                className="flex items-start gap-2 rounded-md border border-destructive/30 bg-destructive/10 px-3 py-2.5 text-[12.5px] text-destructive"
              >
                <AlertCircle className="mt-0.5 h-3.5 w-3.5 shrink-0" />
                <span>{error}</span>
              </div>
            )}
          </div>

          <form onSubmit={handleRequestOtp} className="space-y-4">
            <div className="space-y-1.5">
              <Label htmlFor="name">FULL NAME</Label>
              <Input
                id="name"
                type="text"
                value={name}
                onChange={(e) => setName(e.target.value)}
                placeholder="Juan Dela Cruz"
                required
                autoComplete="name"
              />
            </div>
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
            <div className="space-y-1.5">
              <Label>I AM A</Label>
              <div className="grid grid-cols-2 gap-2">
                <button
                  type="button"
                  onClick={() => setRole('student')}
                  aria-pressed={role === 'student'}
                  className={`rounded-md border px-3 py-2.5 text-[13px] font-medium transition-colors focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-ring focus-visible:ring-offset-2 ring-offset-background ${
                    role === 'student'
                      ? 'border-primary bg-primary text-primary-foreground glow-primary'
                      : 'border-border text-muted-foreground hover:border-primary/40 hover:text-foreground'
                  }`}
                >
                  Student
                </button>
                <button
                  type="button"
                  onClick={() => setRole('instructor')}
                  aria-pressed={role === 'instructor'}
                  className={`rounded-md border px-3 py-2.5 text-[13px] font-medium transition-colors focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-ring focus-visible:ring-offset-2 ring-offset-background ${
                    role === 'instructor'
                      ? 'border-primary bg-primary text-primary-foreground glow-primary'
                      : 'border-border text-muted-foreground hover:border-primary/40 hover:text-foreground'
                  }`}
                >
                  Instructor
                </button>
              </div>
            </div>
            <div className="space-y-1.5">
              <Label htmlFor="password">PASSWORD</Label>
              <div className="relative">
                <Input
                  id="password"
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
                  aria-label={showPassword ? 'Hide password' : 'Show password'}
                  aria-pressed={showPassword}
                  className="absolute right-2 top-1/2 -translate-y-1/2 rounded-md p-1.5 text-muted-foreground transition-colors hover:text-foreground focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-ring focus-visible:ring-offset-2 ring-offset-background"
                >
                  {showPassword ? <EyeOff className="h-4 w-4" /> : <Eye className="h-4 w-4" />}
                </button>
              </div>
            </div>
            <div className="space-y-1.5 text-xs text-muted-foreground">
              {passwordReqs.map((r) => (
                <div key={r.label} className="flex items-center gap-1.5">
                  {r.test(password) ? (
                    <CheckCircle2 className="h-3.5 w-3.5 shrink-0 text-success" />
                  ) : (
                    <Circle className="h-3.5 w-3.5 shrink-0" />
                  )}
                  <span className={r.test(password) ? 'text-success' : ''}>{r.label}</span>
                </div>
              ))}
            </div>
            <Button
              type="submit"
              disabled={loading}
              className="h-11 w-full text-[13px] font-bold"
            >
              {loading ? (
                <><Loader2 className="mr-2 h-4 w-4 animate-spin" /> Sending code...</>
              ) : (
                <><Mail className="mr-2 h-4 w-4" /> Send Verification Code</>
              )}
            </Button>
          </form>

          <div className="flex items-center gap-3">
            <div className="glass-divider-h flex-1" />
            <span className="text-[10.5px] font-medium uppercase tracking-widest text-muted-foreground">OR continue with</span>
            <div className="glass-divider-h flex-1" />
          </div>
          <GoogleAuthButton onError={setError} />
        </CardContent>
        <CardFooter className="flex justify-center border-t p-6">
          <p className="text-xs text-muted-foreground">
            Already have an account?{' '}
            <Link to="/login" className="font-medium text-primary hover:underline">Sign in</Link>
          </p>
        </CardFooter>
      </Card>
    </AuthShell>
  );
}
