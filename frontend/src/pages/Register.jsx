import { useState } from 'react';
import { useNavigate, Link } from 'react-router-dom';
import { Loader2, AlertCircle, ArrowLeft, Eye, EyeOff, CheckCircle2, Mail, Key } from 'lucide-react';
import api from '../services/api';
import { useAuth } from '../context/AuthContext';
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
      await api.post('/api/auth/request-otp', { email });
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
      const role = res.data.user.role;
      const dest = role === 'instructor' ? '/instructor/dashboard' : '/student/dashboard';
      navigate(dest, { replace: true });
    } catch (err) {
      setError(err.response?.data?.message || 'Verification failed');
    } finally {
      setLoading(false);
    }
  };

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
              <form onSubmit={handleVerifyOtp} className="space-y-3.5">
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
                  onClick={handleRequestOtp}
                  className="font-medium text-primary hover:underline"
                  disabled={loading}
                >
                  Resend
                </button>
              </p>
              <button
                onClick={() => { setStep('form'); setError(''); }}
                className="text-xs text-muted-foreground hover:text-foreground"
              >
                Use a different email
              </button>
            </CardFooter>
          </Card>
        </div>
      </div>
    );
  }

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
            <CardTitle className="text-2xl font-bold tracking-tight">Create your account</CardTitle>
            <CardDescription>
              Join CodeInsight · Pampanga State University · CCS
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
            <form onSubmit={handleRequestOtp} className="space-y-3.5">
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
                    className={`rounded-md border px-3 py-2.5 text-[13px] font-medium transition-colors ${
                      role === 'student'
                        ? 'border-primary bg-primary/10 text-primary'
                        : 'border-border text-muted-foreground hover:border-primary/50'
                    }`}
                  >
                    Student
                  </button>
                  <button
                    type="button"
                    onClick={() => setRole('instructor')}
                    className={`rounded-md border px-3 py-2.5 text-[13px] font-medium transition-colors ${
                      role === 'instructor'
                        ? 'border-primary bg-primary/10 text-primary'
                        : 'border-border text-muted-foreground hover:border-primary/50'
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
                    className="absolute right-3 top-1/2 -translate-y-1/2 text-muted-foreground hover:text-foreground"
                    tabIndex={-1}
                  >
                    {showPassword ? <EyeOff className="h-4 w-4" /> : <Eye className="h-4 w-4" />}
                  </button>
                </div>
              </div>
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
          </CardContent>
          <CardFooter className="flex justify-center border-t p-6">
            <p className="text-xs text-muted-foreground">
              Already have an account?{' '}
              <Link to="/login" className="font-medium text-primary hover:underline">Sign in</Link>
            </p>
          </CardFooter>
        </Card>
      </div>
    </div>
  );
}
