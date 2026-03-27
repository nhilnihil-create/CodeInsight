import { NavLink, useNavigate } from 'react-router-dom';
import { useAuth } from '../context/AuthContext';
import { useSidebar } from '../context/SidebarContext';

export default function Sidebar() {
  const { user, logout } = useAuth();
  const { isOpen, toggleSidebar } = useSidebar();
  const navigate = useNavigate();

  const handleLogout = () => {
    logout();
    navigate('/login', { replace: true });
  };

  const sidebarStyle = {
    width: isOpen ? '220px' : '70px',
    minWidth: isOpen ? '220' : '70px',
    height: '100vh',
    background: '#0f0f1a',
    borderRight: '1px solid #2e2e4a',
    display: 'flex',
    flexDirection: 'column',
    position: 'fixed',
    left: 0,
    top: 0,
    zIndex: 100,
    overflow: 'hidden',
    transition: 'all 0.3s ease'
  };

  const navLinkStyle = ({ isActive }) => ({
    display: 'flex',
    alignItems: 'center',
    gap: '9px',
    padding: '9px 16px',
    fontSize: '12.5px',
    fontWeight: 500,
    color: isActive ? '#85D2D0' : '#8884a0',
    background: isActive ? 'rgba(133,210,208,0.06)' : 'transparent',
    borderLeft: isActive ? '3px solid #85D2D0' : '3px solid transparent',
    textDecoration: 'none',
    transition: 'all 0.15s'
  });

  const instructorLinks = [
    { to: '/instructor', label: 'Dashboard', icon: '📊' },
    { to: '/instructor/sections', label: 'My Sections', icon: '📋' },
    { to: '/instructor/create-exercise', label: 'Create Exercise', icon: '✎' },
    { to: '/instructor/alerts', label: 'Alerts', icon: '🔔' },
    { to: '/instructor/developer', label: 'Developer', icon: '⚙️' }
  ];

  const studentLinks = [
    { to: '/student', label: 'My Exercises', icon: '▤' },
    { to: '/student/progress', label: 'My Progress', icon: '📊' }
  ];

  const links = user?.role === 'instructor' ? instructorLinks : studentLinks;

  return (
    <div style={sidebarStyle}>
      {/* Logo & Toggle */}
      <div style={{ 
        padding: isOpen ? '20px 18px 16px' : '16px 12px',
        borderBottom: '1px solid #2e2e4a',
        display: 'flex',
        alignItems: 'center',
        justifyContent: isOpen ? 'space-between' : 'center',
        minHeight: '70px',
        gap: '12px'
      }}>
        {isOpen && (
          <div>
            <div style={{ 
              fontFamily: 'DM Mono, monospace', 
              fontSize: '15px', 
              fontWeight: 700, 
              color: '#85D2D0' 
            }}>
              Code<span style={{ color: '#a99dd4' }}>Insight</span>
            </div>
            <div style={{ 
              fontSize: '9px', 
              fontWeight: 700, 
              color: '#8884a0',
              marginTop: '4px',
              letterSpacing: '2px',
              textTransform: 'uppercase'
            }}>
              {user?.role === 'instructor' ? 'Instructor' : 'Student'}
            </div>
          </div>
        )}
        <button
          onClick={toggleSidebar}
          style={{
            width: '32px',
            height: '32px',
            background: '#1a1a2e',
            border: '1px solid #2e2e4a',
            borderRadius: '6px',
            color: '#85D2D0',
            cursor: 'pointer',
            fontSize: '16px',
            display: 'flex',
            alignItems: 'center',
            justifyContent: 'center',
            padding: 0,
            transition: 'all 0.2s',
            hover: {
              background: '#484f58'
            },
            flexShrink: 0
          }}
          title={isOpen ? 'Close sidebar' : 'Open sidebar'}
        >
          {isOpen ? '‹' : '›'}
        </button>
      </div>

      {/* Navigation */}
      {isOpen && (
        <nav style={{ flex: 1, padding: '12px 0', overflowY: 'auto' }}>
          {links.map(link => (
            <NavLink key={link.to} to={link.to} style={navLinkStyle} end>
              <span>{link.icon}</span> {link.label}
            </NavLink>
          ))}
        </nav>
      )}

      {/* User Info */}
      {isOpen && (
        <div style={{ 
          padding: '14px 16px', 
          borderTop: '1px solid #2e2e4a' 
        }}>
          <div style={{ display: 'flex', alignItems: 'center', gap: '9px' }}>
            <div style={{
              width: '30px',
              height: '30px',
              borderRadius: '50%',
              background: 'linear-gradient(135deg, #887BB0, #85D2D0)',
              display: 'flex',
              alignItems: 'center',
              justifyContent: 'center',
              fontSize: '11px',
              fontWeight: 700,
              color: 'white',
              flexShrink: 0
            }}>
              {user?.name?.split(' ').map(n => n[0]).join('').slice(0,2).toUpperCase() || '?'}
            </div>
            <div>
              <div style={{ 
                fontSize: '11px', 
                fontWeight: 600, 
                color: '#e8e6f0' 
              }}>{user?.name}</div>
              <div style={{ 
                fontSize: '9px', 
                color: '#8884a0' 
              }}>{user?.email}</div>
            </div>
          </div>
          <button 
            onClick={handleLogout}
            style={{
              marginTop: '10px',
              width: '100%',
              padding: '7px',
              background: 'transparent',
              border: '1px solid #2e2e4a',
              borderRadius: '6px',
              color: '#8884a0',
              fontSize: '11px',
              cursor: 'pointer',
              fontFamily: 'inherit'
            }}
          >
            Logout
          </button>
        </div>
      )}
    </div>
  );
}
