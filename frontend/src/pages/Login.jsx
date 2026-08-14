import { useState } from 'react';
import { useNavigate, Link } from 'react-router-dom';
import { Loader2, LogIn, AlertCircle, Info } from 'lucide-react';
import { useAuth } from '../context/AuthContext';
import api from '../services/api';
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

export default function Login() {
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  const [error, setError] = useState('');
  const [loading, setLoading] = useState(false);
  const { login } = useAuth();
  const navigate = useNavigate();
  const params = new URLSearchParams(window.location.search);
  const [info] = useState(
    params.get('verified') === 'true' ? 'Email verified! You can now log in.' :
    params.get('registered') === 'true' ? 'Registration successful! Check your email to verify your account.' :
    ''
  );

  const handleSubmit = async (e) => {
    e.preventDefault();
    setError('');
    setLoading(true);

    try {
      const res = await api.post('/api/auth/login', { email, password });
      login(res.data.user);

      const role = res.data.user.role;
      const dest = role === 'instructor' ? '/instructor/dashboard' : role === 'admin' ? '/admin' : '/student/dashboard';
      navigate(dest, { replace: true });
    } catch (err) {
      setError(err.response?.data?.message || 'Login failed');
    } finally {
      setLoading(false);
    }
  };

  return (
    <AuthShell showBackLink>
      <Card variant="dense">
        <CardHeader className="space-y-1 text-center">
          <div className="mx-auto mb-2 font-mono text-2xl font-bold text-primary">
            Code<span className="text-secondary-foreground">Insight</span>
          </div>
          <CardTitle className="text-2xl font-bold tracking-tight">Welcome back</CardTitle>
          <CardDescription>
            Sign in to continue to CodeInsight · Pampanga State University · CCS
          </CardDescription>
        </CardHeader>

        <CardContent className="space-y-4">
          <div aria-live="polite" className="space-y-3">
            {info && (
              <div className="flex items-start gap-2 rounded-md border border-info/30 bg-info/10 px-3 py-2.5 text-[12.5px] text-info">
                <Info className="mt-0.5 h-3.5 w-3.5 shrink-0" />
                <span>{info}</span>
              </div>
            )}
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

          <form onSubmit={handleSubmit} className="space-y-4">
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
              <Label htmlFor="password">PASSWORD</Label>
              <Input
                id="password"
                type="password"
                value={password}
                onChange={(e) => setPassword(e.target.value)}
                placeholder="••••••••"
                required
                autoComplete="current-password"
              />
            </div>

            <div className="flex justify-end">
              <Link
                to="/forgot-password"
                className="text-xs text-muted-foreground transition-colors hover:text-primary"
              >
                Forgot password?
              </Link>
            </div>

            <Button
              type="submit"
              disabled={loading}
              className="h-11 w-full text-[13px] font-bold"
            >
              {loading ? (
                <>
                  <Loader2 className="mr-2 h-4 w-4 animate-spin" />
                  Signing in...
                </>
              ) : (
                <>
                  <LogIn className="mr-2 h-4 w-4" />
                  Sign In
                </>
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

        <CardFooter className="flex flex-col gap-3 border-t p-6">
          <div className="w-full rounded-md border border-border/60 bg-muted/40 px-3 py-2.5 text-[11px] text-muted-foreground">
            <div className="mb-1 flex items-center gap-1.5 font-semibold text-secondary-foreground">
              <Info className="h-3 w-3" />
              Demo accounts (password: password123)
            </div>
            <div className="font-mono text-[10.5px]">Instructor: instructor@psu.edu</div>
            <div className="font-mono text-[10.5px]">Student: maria@student.psu.edu</div>
          </div>
          <p className="text-xs text-muted-foreground">
            Don&apos;t have an account?{' '}
            <Link to="/register" className="font-medium text-primary hover:underline">
              Sign up
            </Link>
          </p>
        </CardFooter>
        </Card>
      </AuthShell>
  );
}
