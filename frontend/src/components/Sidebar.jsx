import { NavLink, useNavigate, useLocation } from 'react-router-dom';
import { motion, AnimatePresence } from 'framer-motion';
import {
  LayoutDashboard,
  LayoutGrid,
  ListChecks,
  PlusSquare,
  Settings,
  Terminal,
  TrendingUp,
  FileBarChart2,
  PanelLeftClose,
  PanelLeftOpen,
  LogOut,
  ShieldAlert,
  Users,
  User,
  Code,
} from 'lucide-react';
import { useAuth } from '../context/AuthContext';
import { useSidebar } from '../context/SidebarContext';
import { Button } from '@/components/ui/button';
import { Avatar, AvatarFallback } from '@/components/ui/avatar';
import { cn } from '@/lib/utils';
import {
  Tooltip,
  TooltipTrigger,
  TooltipContent,
  TooltipArrow,
  TooltipPortal,
} from '@/components/ui/tooltip';

const spring = { type: 'spring', stiffness: 350, damping: 30 };

const instructorLinks = [
  { to: '/instructor/dashboard',   label: 'Dashboard',   icon: LayoutDashboard, end: true },
  { to: '/instructor/heatmap',     label: 'Heatmap',     icon: LayoutGrid },
  { to: '/instructor/students',    label: 'Students',    icon: Users,           end: true },
  { to: '/instructor/my-sections', label: 'My Sections', icon: ListChecks },
  { to: '/instructor/exercises',   label: 'Exercises',   icon: PlusSquare },
  { to: '/instructor/reports',     label: 'Reports',     icon: FileBarChart2 },
  { to: '/instructor/integrity',   label: 'Integrity',   icon: ShieldAlert },
];

const adminLinks = [
  { to: '/admin',                label: 'Overview',    icon: LayoutDashboard, end: true },
  { to: '/admin/users',          label: 'Users',       icon: Users },
  { to: '/admin/sections',       label: 'Sections',    icon: ListChecks },
  { to: '/admin/concepts',       label: 'Concepts',    icon: Code },
  { to: '/admin/exercises',      label: 'Exercises',   icon: PlusSquare },
  { to: '/admin/evaluation',     label: 'Evaluation',  icon: TrendingUp },
  { to: '/admin/flags',          label: 'Flags',       icon: ShieldAlert },
  { to: '/admin/audit',          label: 'Audit Log',   icon: ShieldAlert },
];

const studentLinks = [
  { to: '/student/dashboard', label: 'My Exercises', icon: Terminal, end: true },
  { to: '/student/progress',  label: 'My Progress',  icon: TrendingUp },
  { to: '/student/profile',   label: 'My Profile',   icon: User },
];

export default function Sidebar() {
  const { user, logout } = useAuth();
  const { isOpen, toggleSidebar } = useSidebar();
  const navigate = useNavigate();
  const { pathname } = useLocation();

  const links = user?.role === 'admin' ? adminLinks
    : user?.role === 'instructor' ? instructorLinks
    : studentLinks;

  const initials = (user?.name || '?')
    .split(' ')
    .map((n) => n[0])
    .join('')
    .slice(0, 2)
    .toUpperCase();

  const handleLogout = async () => {
    await logout();
    navigate('/login', { replace: true });
  };

  return (
    <aside
      className={cn(
        'fixed left-0 top-0 z-40 h-full flex flex-col justify-between',
        'bg-[#0E1322]/80 backdrop-blur-xl border-r border-white/[0.04]',
        'text-sidebar-foreground transition-[width] duration-300 ease-in-out overflow-hidden',
        isOpen ? 'w-[220px]' : 'w-[70px]'
      )}
    >
      {/* ── Brand Header ─────────────────────────────────── */}
      <div
        className={cn(
          'flex min-h-[70px] items-center gap-3',
          isOpen ? 'justify-between px-[18px] py-5' : 'justify-center px-2 py-4'
        )}
      >
        <AnimatePresence mode="wait">
          {isOpen && (
            <motion.div
              key="brand"
              initial={{ opacity: 0, x: -8 }}
              animate={{ opacity: 1, x: 0 }}
              exit={{ opacity: 0, x: -8 }}
              transition={{ duration: 0.15 }}
              className="min-w-0"
            >
              <div className="font-mono text-[15px] font-bold text-primary">
                Code<span className="text-secondary-foreground">Insight</span>
              </div>
              <div className="mt-1 text-[9px] font-bold uppercase tracking-[2px] text-muted-foreground">
                {user?.role === 'admin' ? 'Admin'
                : user?.role === 'instructor' ? 'Instructor'
                : 'Student'}
              </div>
            </motion.div>
          )}
        </AnimatePresence>

        <Button
          variant="outline"
          size="icon"
          onClick={toggleSidebar}
          aria-label={isOpen ? 'Close sidebar' : 'Open sidebar'}
          title={isOpen ? 'Close sidebar' : 'Open sidebar'}
          className="h-8 w-8 shrink-0 border-white/[0.08] bg-transparent hover:bg-white/[0.06]"
        >
          {isOpen ? (
            <PanelLeftClose className="h-4 w-4" />
          ) : (
            <PanelLeftOpen className="h-4 w-4" />
          )}
        </Button>
      </div>

      {/* ── Navigation Links ─────────────────────────────── */}
      <nav
        className={cn(
          'flex-1 overflow-y-auto px-3 py-2',
          !isOpen && 'flex flex-col items-center'
        )}
      >
        <div className="relative flex flex-col gap-1">
          {links.map((link) => {
            const Icon = link.icon;
            const isActive = link.end
              ? pathname === link.to
              : pathname.startsWith(link.to);

            if (!isOpen) {
              /* ── Collapsed: floating glass pill icons ── */
              return (
                <Tooltip key={link.to}>
                  <TooltipTrigger asChild>
                    <NavLink
                      to={link.to}
                      end={link.end}
                      className="relative flex h-10 w-10 items-center justify-center rounded-xl text-muted-foreground transition-all duration-200 hover:bg-white/[0.03] hover:text-white"
                    >
                      {isActive && (
                        <motion.div
                          layoutId="collapsedIndicator"
                          className="absolute inset-0 rounded-xl bg-white/[0.06] border border-white/[0.08] text-emerald-400"
                          transition={spring}
                          style={{ zIndex: 0 }}
                        />
                      )}
                      <Icon className={cn('relative z-10 h-[18px] w-[18px]', isActive && 'text-emerald-400')} />
                    </NavLink>
                  </TooltipTrigger>
                  <TooltipPortal>
                    <TooltipContent side="right" sideOffset={12}>
                      {link.label}
                      <TooltipArrow />
                    </TooltipContent>
                  </TooltipPortal>
                </Tooltip>
              );
            }

            /* ── Expanded: sliding gradient indicator ── */
            return (
              <NavLink
                key={link.to}
                to={link.to}
                end={link.end}
                className="relative flex items-center gap-2.5 rounded-xl px-4 py-2.5 text-[12.5px] font-medium text-muted-foreground transition-colors hover:text-white/80"
              >
                {isActive && (
                  <motion.div
                    layoutId="expandedIndicator"
                    className="absolute inset-0 rounded-xl bg-gradient-to-r from-emerald-500/10 to-transparent border-l-2 border-emerald-400"
                    transition={spring}
                    style={{ zIndex: 0 }}
                  />
                )}
                <Icon className={cn('relative z-10 h-4 w-4 shrink-0', isActive && 'text-emerald-400')} />
                <span className={cn('relative z-10', isActive && 'text-emerald-400')}>{link.label}</span>
              </NavLink>
            );
          })}
        </div>
      </nav>

      {/* ── Footer Profile ───────────────────────────────── */}
      <div className="relative mt-auto">
        {/* Gradient mesh separator — replaces hard border-t */}
        <div className="pointer-events-none h-8 bg-gradient-to-t from-[#0E1322]/90 via-[#0E1322]/40 to-transparent" />

        <div
          className={cn(
            'px-4 pb-4 pt-1',
            !isOpen && 'flex flex-col items-center'
          )}
        >
          {isOpen ? (
            <div className="flex items-center gap-2.5">
              <Avatar className="h-[30px] w-[30px] ring-2 ring-white/[0.08]">
                <AvatarFallback className="bg-primary text-primary-foreground text-[11px] font-bold">
                  {initials}
                </AvatarFallback>
              </Avatar>
              <div className="min-w-0 flex-1">
                <div className="truncate text-[11px] font-semibold text-foreground">
                  {user?.name}
                </div>
                <div className="truncate text-[9px] text-muted-foreground">
                  {user?.email}
                </div>
              </div>
            </div>
          ) : (
            <Tooltip>
              <TooltipTrigger asChild>
                <button
                  onClick={handleLogout}
                  aria-label={`Logout ${user?.name || 'user'}`}
                  className="rounded-full transition-all duration-200 hover:ring-2 hover:ring-emerald-400/40"
                >
                  <Avatar className="h-9 w-9 ring-2 ring-white/[0.08]">
                    <AvatarFallback className="bg-primary text-primary-foreground text-[11px] font-bold">
                      {initials}
                    </AvatarFallback>
                  </Avatar>
                </button>
              </TooltipTrigger>
              <TooltipPortal>
                <TooltipContent side="right" sideOffset={12}>
                  Logout
                  <TooltipArrow />
                </TooltipContent>
              </TooltipPortal>
            </Tooltip>
          )}

          <AnimatePresence>
            {isOpen && (
              <motion.div
                key="logout-btn"
                initial={{ opacity: 0, height: 0 }}
                animate={{ opacity: 1, height: 'auto' }}
                exit={{ opacity: 0, height: 0 }}
                transition={{ duration: 0.15 }}
              >
                <Button
                  variant="outline"
                  size="sm"
                  onClick={handleLogout}
                  className="mt-2.5 w-full text-[11px] text-muted-foreground border-white/[0.08] bg-transparent hover:bg-white/[0.04] hover:text-white"
                >
                  <LogOut className="mr-2 h-3 w-3" />
                  Logout
                </Button>
              </motion.div>
            )}
          </AnimatePresence>
        </div>
      </div>
    </aside>
  );
}
