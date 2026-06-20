import React from 'react'
import ReactDOM from 'react-dom/client'
import { QueryClient, QueryClientProvider } from '@tanstack/react-query'
import { Toaster } from 'sonner'
import { TooltipProvider } from '@/components/ui/tooltip'
import App from './App.jsx'
import { AuthProvider } from './context/AuthContext.jsx'
import { EditorPrefsProvider } from './context/EditorPrefsContext.jsx'
import { ToastProvider } from '@/hooks/use-toast'
import './index.css'
import './styles/mobile.css'   // <-- new

// React Query — single client, sensible defaults for a CRUD app.
const queryClient = new QueryClient({
  defaultOptions: {
    queries: {
      staleTime: 30_000,
      refetchOnWindowFocus: false,
      retry: 1,
    },
  },
})

// NOTE: <BrowserRouter> lives inside <App /> so App.jsx owns routing.
// Don't add it here — that would nest routers and confuse useNavigate on errors.
ReactDOM.createRoot(document.getElementById('root')).render(
  <React.StrictMode>
    <QueryClientProvider client={queryClient}>
      <ToastProvider>
        <TooltipProvider delayDuration={150}>
          <AuthProvider>
            <EditorPrefsProvider>
            <App />
            </EditorPrefsProvider>
            <Toaster
              theme="dark"
              position="top-right"
              richColors
              closeButton
              toastOptions={{
                style: {
                  background: '#131d30',
                  border: '1px solid #1e304d',
                  color: '#dce8f5',
                },
              }}
            />
          </AuthProvider>
        </TooltipProvider>
      </ToastProvider>
    </QueryClientProvider>
  </React.StrictMode>,
)
