import { createContext, useCallback, useContext } from "react";
import { toast as sonnerToast } from "sonner";

/**
 * Thin wrapper around the `sonner` library. Components call
 *   const { toast } = useToast();
 *   toast({ title: "Saved", description: "Section updated", variant: "success" });
 *
 * We delegate the actual rendering to <Toaster /> (mounted once in main.jsx).
 * This hook is kept stable for any code that already imports it.
 */
const ToastContext = createContext(null);

export function ToastProvider({ children }) {
  const toast = useCallback(({ title, description, variant = "default" }) => {
    const message = title ?? "";
    const opts = { description };

    switch (variant) {
      case "destructive":
        sonnerToast.error(message, opts);
        break;
      case "success":
        sonnerToast.success(message, opts);
        break;
      case "warning":
        sonnerToast.warning(message, opts);
        break;
      case "info":
        sonnerToast.info(message, opts);
        break;
      default:
        sonnerToast(message, opts);
    }
  }, []);

  return (
    <ToastContext.Provider value={{ toast }}>{children}</ToastContext.Provider>
  );
}

export function useToast() {
  const ctx = useContext(ToastContext);
  if (!ctx) {
    // Fallback no-op so components can call useToast() outside the provider.
    return { toast: () => {} };
  }
  return ctx;
}

export default useToast;
