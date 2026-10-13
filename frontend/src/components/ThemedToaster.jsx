import { Toaster } from 'sonner';
import { useTheme } from '@/lib/theme';

/**
 * ThemedToaster — sonner toaster that follows the app theme (not the OS).
 * Must render inside <ThemeProvider>.
 * DARK uses the exact legacy style values (byte-identical to pre-theme
 * main.jsx); LIGHT uses the design tokens.
 */
const DARK_STYLE = {
  background: '#131d30',
  border: '1px solid #1e304d',
  color: '#dce8f5',
};

const LIGHT_STYLE = {
  background: 'hsl(var(--popover))',
  border: '1px solid hsl(var(--popover-border))',
  color: 'hsl(var(--popover-foreground))',
};

export default function ThemedToaster() {
  const { theme } = useTheme();
  return (
    <Toaster
      theme={theme === 'light' ? 'light' : 'dark'}
      position="top-right"
      richColors
      closeButton
      toastOptions={{
        style: theme === 'light' ? LIGHT_STYLE : DARK_STYLE,
      }}
    />
  );
}
