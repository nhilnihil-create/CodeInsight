import { NavLink, useNavigate } from 'react-router-dom';
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

/**
 * App sidebar.
 *
 * PRESERVED from the previous implementation:
 *   - SidebarContext contract: { isOpen, toggleSidebar }
 *   - AuthContext usage: useAuth() returns { user, logout }
 *   - Same nav links, same role-based filtering
 *   - handleLogout navigates to /login with replace:true
 *   - User initials derived from user.name (first letter of first 2 words)
 *
 * REPLACED:
 *   - Hard-coded dark teal hexes → semantic tokens (bg-sidebar, text-foreground, etc.)
 *   - Custom avatar gradient → shadcn Avatar + AvatarFallback
 *   - Now matches Frontend-Design's light HSL token system from index.css
 */
export default function Sidebar() {
  const { user, logout } = useAuth();
  const { isOpen, toggleSidebar } = useSidebar();
  const navigate = useNavigate();

  const handleLogout = () => {
    logout();
    navigate('/login', { replace: true });
  };

  const instructorLinks = [
    { to: '/instructor/dashboard',  label: 'Dashboard',   icon: LayoutDashboard, end: true },
    { to: '/instructor/heatmap',    label: 'Heatmap',     icon: LayoutGrid },
    { to: '/instructor/students',   label: 'Students',    icon: Users,           end: true },
    { to: '/instructor/my-sections',label: 'My Sections', icon: ListChecks },
    { to: '/instructor/exercises',  label: 'Exercises',   icon: PlusSquare },
    { to: '/instructor/reports',    label: 'Reports',     icon: FileBarChart2 },
    { to: '/instructor/integrity',  label: 'Integrity',   icon: ShieldAlert },
    { to: '/instructor/developer',  label: 'Developer',   icon: Settings },
  ];

  const studentLinks = [
    { to: '/student/dashboard', label: 'My Exercises', icon: Terminal, end: true },
    { to: '/student/progress', label: 'My Progress', icon: TrendingUp },
    { to: '/student/profile', label: 'My Profile', icon: User },
  ];

  const links = user?.role === 'instructor' ? instructorLinks : studentLinks;

  const initials = (user?.name || '?')
    .split(' ')
    .map((n) => n[0])
    .join('')
    .slice(0, 2)
    .toUpperCase();

  return (
    <aside
      className={cn(
        'fixed left-0 top-0 z-40 flex h-screen flex-col overflow-hidden border-r border-sidebar-border bg-sidebar text-sidebar-foreground transition-[width] duration-300 ease-in-out',
        isOpen ? 'w-[220px]' : 'w-[70px]'
      )}
    >
      {/* Header / brand */}
      <div
        className={cn(
          'flex min-h-[70px] items-center border-b border-sidebar-border gap-3',
          isOpen ? 'justify-between px-[18px] py-5' : 'justify-center px-2 py-4'
        )}
      >
        {isOpen && (
          <div className="min-w-0">
            <div className="font-mono text-[15px] font-bold text-primary">
              Code<span className="text-secondary-foreground">Insight</span>
            </div>
            <div className="mt-1 text-[9px] font-bold uppercase tracking-[2px] text-muted-foreground">
              {user?.role === 'instructor' ? 'Instructor' : 'Student'}
            </div>
          </div>
        )}

        <Button
          variant="outline"
          size="icon"
          onClick={toggleSidebar}
          aria-label={isOpen ? 'Close sidebar' : 'Open sidebar'}
          title={isOpen ? 'Close sidebar' : 'Open sidebar'}
          className="h-8 w-8 shrink-0"
        >
          {isOpen ? (
            <PanelLeftClose className="h-4 w-4" />
          ) : (
            <PanelLeftOpen className="h-4 w-4" />
          )}
        </Button>
      </div>

      {/* Nav — always rendered, just changes layout when collapsed */}
      <nav className={cn('flex-1 overflow-y-auto py-3', !isOpen && 'flex flex-col items-center')}>
        {links.map((link) => {
          const Icon = link.icon;
          const item = (
            <NavLink
              to={link.to}
              end={link.end}
              className={({ isActive }) =>
                cn(
                  'flex items-center transition-colors',
                  isOpen
                    ? 'gap-2.5 px-4 py-2.5 text-[12.5px] font-medium'
                    : 'h-10 w-10 justify-center rounded-md',
                  isActive
                    ? isOpen
                      ? 'border-l-[3px] border-sidebar-primary bg-sidebar-accent text-sidebar-primary'
                      : 'bg-sidebar-accent text-sidebar-primary'
                    : isOpen
                      ? 'border-l-[3px] border-transparent text-muted-foreground hover:bg-sidebar-accent hover:text-sidebar-accent-foreground'
                      : 'text-muted-foreground hover:bg-sidebar-accent hover:text-sidebar-accent-foreground'
                )
              }
            >
              <Icon className="h-4 w-4 shrink-0" />
              {isOpen && <span>{link.label}</span>}
            </NavLink>
          );

          // In collapsed mode, wrap with a Radix tooltip so the label is discoverable
          if (!isOpen) {
            return (
              <Tooltip key={link.to}>
                <TooltipTrigger asChild>{item}</TooltipTrigger>
                <TooltipPortal>
                  <TooltipContent side="right" sideOffset={8}>
                    {link.label}
                    <TooltipArrow />
                  </TooltipContent>
                </TooltipPortal>
              </Tooltip>
            );
          }
          return <div key={link.to}>{item}</div>;
        })}
      </nav>

      {/* User + logout */}
      <div
        className={cn(
          'border-t border-sidebar-border',
          isOpen ? 'px-4 py-3.5' : 'flex justify-center py-3'
        )}
      >
        {isOpen ? (
          <div className="flex items-center gap-2.5">
            <Avatar className="h-[30px] w-[30px]">
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
                className="rounded-full transition-transform hover:scale-105"
              >
                <Avatar className="h-9 w-9">
                  <AvatarFallback className="bg-primary text-primary-foreground text-[11px] font-bold">
                    {initials}
                  </AvatarFallback>
                </Avatar>
              </button>
            </TooltipTrigger>
            <TooltipPortal>
              <TooltipContent side="right" sideOffset={8}>
                Logout
                <TooltipArrow />
              </TooltipContent>
            </TooltipPortal>
          </Tooltip>
        )}

        {isOpen && (
          <Button
            variant="outline"
            size="sm"
            onClick={handleLogout}
            className="mt-2.5 w-full text-[11px] text-muted-foreground"
          >
            <LogOut className="mr-2 h-3 w-3" />
            Logout
          </Button>
        )}
      </div>
    </aside>
  );
}
