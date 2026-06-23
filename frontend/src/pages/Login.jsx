import { useState } from 'react';
import { useNavigate, Link } from 'react-router-dom';
import { Loader2, LogIn, AlertCircle, Info, ArrowLeft } from 'lucide-react';
import { useAuth } from '../context/AuthContext';
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
            <CardTitle className="text-2xl font-bold tracking-tight">Welcome back</CardTitle>
            <CardDescription>
              Sign in to continue to CodeInsight · Pampanga State University · CCS
            </CardDescription>
          </CardHeader>

          <CardContent className="space-y-4">
            {info && (
              <div className="flex items-start gap-2 rounded-md border border-green-300 bg-green-50 px-3 py-2.5 text-[12.5px] text-green-700">
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

            <form onSubmit={handleSubmit} className="space-y-3.5">
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
          </CardContent>

          <CardFooter className="flex flex-col gap-3 border-t p-6">
            <div className="w-full rounded-md bg-muted px-3 py-2.5 text-[11px] text-muted-foreground">
              <div className="mb-1 flex items-center gap-1.5 font-semibold text-secondary-foreground">
                <Info className="h-3 w-3" />
                Demo accounts (password: password123)
              </div>
              <div>Instructor: instructor@psu.edu</div>
              <div>Student: maria@student.psu.edu</div>
            </div>
            <p className="text-xs text-muted-foreground">
              Don&apos;t have an account?{' '}
              <Link to="/register" className="font-medium text-primary hover:underline">
                Sign up
              </Link>
            </p>
          </CardFooter>
        </Card>
      </div>
    </div>
  );
}
