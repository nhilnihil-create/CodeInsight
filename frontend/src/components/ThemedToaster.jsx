import { Toaster } from 'sonner';
import { useTheme } from '@/lib/theme';

/**
 * ThemedToaster — sonner toaster that follows the app theme (not the OS).
 * Must render inside <ThemeProvider>. Colors come from CSS variables so
 * both themes stay in sync with the design tokens.
 */
export default function ThemedToaster() {
  const { theme } = useTheme();
  return (
    <Toaster
      theme={theme === 'light' ? 'light' : 'dark'}
      position="top-right"
      richColors
      closeButton
      toastOptions={{
        style: {
          background: 'hsl(var(--popover))',
          border: '1px solid hsl(var(--popover-border))',
          color: 'hsl(var(--popover-foreground))',
        },
      }}
    />
  );
}
