import { useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { useAuth } from '../context/AuthContext';
import api from '../services/api';

export default function Login() {
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  const [error, setError] = useState('');
  const [loading, setLoading] = useState(false);
  const { login } = useAuth();
  const navigate = useNavigate();

  const handleSubmit = async (e) => {
    e.preventDefault();
    setError('');
    setLoading(true);
    
    try {
      const res = await api.post('/api/auth/login', { email, password });
      login(res.data.token, res.data.user);
      
      const dest = res.data.user.role === 'instructor' ? '/instructor' : '/student';
      navigate(dest, { replace: true });
    } catch (err) {
      setError(err.response?.data?.message || 'Login failed');
    } finally {
      setLoading(false);
    }
  };

  return (
    <div style={{ 
      minHeight: '100vh', 
      background: '#0d1117', 
      display: 'flex', 
      alignItems: 'center', 
      justifyContent: 'center',
      padding: '20px'
    }}>
      <div style={{ width: '100%', maxWidth: '380px' }}>
        {/* Logo */}
        <div style={{ textAlign: 'center', marginBottom: '32px' }}>
          <div style={{ 
            fontFamily: 'DM Mono, monospace', 
            fontSize: '24px', 
            fontWeight: 700,
            color: '#85D2D0', 
            marginBottom: '6px' 
          }}>
            Code<span style={{ color: '#a99dd4' }}>Insight</span>
          </div>
          <div style={{ fontSize: '11px', color: '#8b949e' }}>
            Pampanga State University · CCS
          </div>
        </div>

        {/* Card */}
        <div style={{ 
          background: '#161b22', 
          border: '1px solid #30363d',
          borderRadius: '12px', 
          padding: '28px 24px' 
        }}>
          <div style={{ 
            fontSize: '16px', 
            fontWeight: 700, 
            color: '#e6edf3',
            marginBottom: '20px' 
          }}>Sign in to CodeInsight</div>

          {error && (
            <div style={{ 
              background: 'rgba(248, 113, 113, 0.1)', 
              border: '1px solid rgba(248, 113, 113, 0.3)',
              borderRadius: '7px', 
              padding: '10px 13px', 
              color: '#f87171',
              fontSize: '12.5px', 
              marginBottom: '14px' 
            }}>{error}</div>
          )}

          <form onSubmit={handleSubmit}>
            <div style={{ marginBottom: '14px' }}>
              <label style={{ 
                fontSize: '11px', 
                fontWeight: 600, 
                color: '#8b949e',
                letterSpacing: '0.5px', 
                display: 'block', 
                marginBottom: '5px' 
              }}>
                EMAIL
              </label>
              <input 
                type="email" 
                value={email} 
                onChange={(e) => setEmail(e.target.value)}
                placeholder="your@email.com" 
                required 
                style={{ width: '100%' }}
              />
            </div>

            <div style={{ marginBottom: '20px' }}>
              <label style={{ 
                fontSize: '11px', 
                fontWeight: 600, 
                color: '#8b949e',
                letterSpacing: '0.5px', 
                display: 'block', 
                marginBottom: '5px' 
              }}>
                PASSWORD
              </label>
              <input 
                type="password" 
                value={password} 
                onChange={(e) => setPassword(e.target.value)}
                placeholder="••••••••" 
                required 
                style={{ width: '100%' }}
              />
            </div>

            <button 
              type="submit" 
              disabled={loading}
              style={{
                width: '100%', 
                padding: '11px', 
                background: loading ? '#4a9997' : '#85D2D0',
                border: 'none', 
                borderRadius: '8px', 
                color: '#0a1a1a',
                fontSize: '13px', 
                fontWeight: 700, 
                cursor: loading ? 'not-allowed' : 'pointer'
              }}
            >
              {loading ? 'Signing in...' : 'Sign In'}
            </button>
          </form>

          <div style={{ 
            marginTop: '16px', 
            padding: '12px', 
            background: '#21262d',
            borderRadius: '7px', 
            fontSize: '11px', 
            color: '#8b949e' 
          }}>
            <div style={{ fontWeight: 600, color: '#a99dd4', marginBottom: '4px' }}>
              Demo accounts (password: password123)
            </div>
            <div>Instructor: instructor@psu.edu</div>
            <div>Student: maria@student.psu.edu</div>
          </div>
        </div>
      </div>
    </div>
  );
}
