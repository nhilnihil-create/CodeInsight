import { useNavigate } from 'react-router-dom';
import { AlertCircle, ArrowLeft } from 'lucide-react';
import {
  Card,
  CardContent,
  CardDescription,
  CardHeader,
  CardTitle,
} from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { useAuth } from '@/context/AuthContext';

/**
 * 404 Not Found
 *
 * Auth-aware: authenticated users see a "go back to your dashboard" prompt,
 * unauthenticated users get a "back to login" prompt. The route's catch-all
 * in App.jsx now renders this page instead of silently redirecting to /login
 * (so deep-links, typos, and post-logout-while-typing paths show a real
 * not-found screen).
 */
export default function NotFound() {
  const navigate = useNavigate();
  const { isLoggedIn, user } = useAuth();
  const home = isLoggedIn
    ? user?.role === 'instructor'
      ? '/instructor'
      : '/student'
    : '/login';

  const homeLabel = isLoggedIn
    ? user?.role === 'instructor'
      ? 'Instructor Dashboard'
      : 'Student Dashboard'
    : 'Login';

  return (
    <div className="flex min-h-screen w-full items-center justify-center bg-background p-6">
      <Card className="max-w-md">
        <CardHeader>
          <div className="mb-2 flex h-12 w-12 items-center justify-center rounded-full bg-destructive/10">
            <AlertCircle className="h-6 w-6 text-destructive" />
          </div>
          <CardTitle className="text-2xl">Page not found</CardTitle>
          <CardDescription>
            The page you were looking for doesn't exist or has been moved.
          </CardDescription>
        </CardHeader>
        <CardContent>
          <Button onClick={() => navigate(home)} className="w-full">
            <ArrowLeft className="mr-2 h-4 w-4" />
            Back to {homeLabel}
          </Button>
        </CardContent>
      </Card>
    </div>
  );
}
