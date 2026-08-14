import { Link } from 'react-router-dom';
import { ArrowLeft } from 'lucide-react';

export default function AuthShell({ showBackLink = false, children }) {
  return (
    <div className="mesh-bg flex min-h-dvh flex-col px-4 py-8 text-foreground">
      <div className="m-auto flex w-full max-w-md flex-col gap-4">
        {showBackLink && (
          <div className="flex items-center justify-center">
            <Link
              to="/"
              className="inline-flex items-center gap-1.5 text-xs font-medium text-muted-foreground transition-colors hover:text-primary"
            >
              <ArrowLeft className="h-3 w-3" /> Back to home
            </Link>
          </div>
        )}
        {children}
      </div>
    </div>
  );
}
