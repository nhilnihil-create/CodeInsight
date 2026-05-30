import React, { useState } from 'react';
import api from '../services/api';

const EnrollStudentsModal = ({ sectionId, onClose, onSuccess }) => {
  const [emails, setEmails] = useState('');
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState('');
  const [success, setSuccess] = useState('');

  const handleSubmit = async (e) => {
    e.preventDefault();
    setError('');
    setSuccess('');
    setLoading(true);

    try {
      const emailList = emails
        .split('\n')
        .map(e => e.trim())
        .filter(e => e.length > 0);

      if (emailList.length === 0) {
        setError('Please enter at least one email address');
        setLoading(false);
        return;
      }

      const response = await api.post(`/api/sections/${sectionId}/enroll`, { emails: emailList });
      setSuccess(response.data.message);
      setEmails('');
      
      setTimeout(() => {
        onSuccess?.();
        onClose();
      }, 1500);
    } catch (err) {
      setError(err.response?.data?.message || 'Failed to enroll students');
    } finally {
      setLoading(false);
    }
  };

  return (
    <div style={{
      position: 'fixed',
      top: 0,
      left: 0,
      right: 0,
      bottom: 0,
      background: 'rgba(0,0,0,0.6)',
      display: 'flex',
      alignItems: 'center',
      justifyContent: 'center',
      zIndex: 1000,
      fontFamily: 'DM Sans, sans-serif'
    }}>
      <div style={{
        background: '#131d30',
        border: '1px solid #1e304d',
        borderRadius: '12px',
        padding: '28px',
        width: '90%',
        maxWidth: '450px',
        boxShadow: '0 20px 60px rgba(0,0,0,0.4)'
      }}>
        <h2 style={{ margin: '0 0 20px 0', color: '#ffffff', fontSize: '18px', fontWeight: 700 }}>
          Enroll Students
        </h2>
        
        <p style={{ color: '#8884a0', fontSize: '13px', marginBottom: '18px', lineHeight: '1.5' }}>
          Enter student email addresses (one per line). Students must already have accounts.
        </p>

        <form onSubmit={handleSubmit}>
          <textarea
            value={emails}
            onChange={(e) => setEmails(e.target.value)}
            placeholder="student1@example.com&#10;student2@example.com&#10;student3@example.com"
            style={{
              width: '100%',
              minHeight: '120px',
              padding: '12px',
              background: '#0f1a1a',
              border: '1px solid #1e304d',
              borderRadius: '8px',
              color: '#ffffff',
              fontFamily: 'DM Sans, sans-serif',
              fontSize: '13px',
              resize: 'vertical',
              boxSizing: 'border-box',
              marginBottom: '16px'
            }}
            disabled={loading}
          />

          {error && (
            <div style={{
              background: 'rgba(239,68,68,0.1)',
              border: '1px solid #ef4444',
              color: '#fca5a5',
              padding: '10px 12px',
              borderRadius: '6px',
              fontSize: '12px',
              marginBottom: '16px'
            }}>
              {error}
            </div>
          )}

          {success && (
            <div style={{
              background: 'rgba(34,197,94,0.1)',
              border: '1px solid #22c55e',
              color: '#86efac',
              padding: '10px 12px',
              borderRadius: '6px',
              fontSize: '12px',
              marginBottom: '16px'
            }}>
              {success}
            </div>
          )}

          <div style={{ display: 'flex', gap: '12px', justifyContent: 'flex-end' }}>
            <button
              type="button"
              onClick={onClose}
              disabled={loading}
              style={{
                padding: '10px 20px',
                background: 'rgba(255,255,255,0.1)',
                border: '1px solid #1e304d',
                color: '#ffffff',
                borderRadius: '8px',
                cursor: loading ? 'not-allowed' : 'pointer',
                fontSize: '13px',
                fontWeight: 600,
                fontFamily: 'DM Sans, sans-serif',
                opacity: loading ? 0.5 : 1
              }}
            >
              Cancel
            </button>
            <button
              type="submit"
              disabled={loading}
              style={{
                padding: '10px 20px',
                background: '#85D2D0',
                border: 'none',
                color: '#0f1a1a',
                borderRadius: '8px',
                cursor: loading ? 'not-allowed' : 'pointer',
                fontSize: '13px',
                fontWeight: 600,
                fontFamily: 'DM Sans, sans-serif',
                opacity: loading ? 0.7 : 1
              }}
            >
              {loading ? 'Enrolling...' : 'Enroll Students'}
            </button>
          </div>
        </form>
      </div>
    </div>
  );
};

export default EnrollStudentsModal;
