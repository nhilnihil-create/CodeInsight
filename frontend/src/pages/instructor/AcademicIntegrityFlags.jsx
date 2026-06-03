import React, { useState, useEffect } from 'react';
import { useNavigate, useParams } from 'react-router-dom';
import api from '../../services/api';
import IntegrityFlagBadge from '../../components/IntegrityFlagBadge';
import CodeComparisonModal from '../../components/CodeComparisonModal';

const AcademicIntegrityFlags = () => {
  const { sectionId } = useParams();
  const navigate = useNavigate();

  const [flags, setFlags] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [filters, setFilters] = useState({
    flag_type: '',
    student_id: '',
    exercise_id: ''
  });
  const [pagination, setPagination] = useState({
    page: 1,
    limit: 50,
    total: 0,
    totalPages: 0
  });
  const [selectedFlag, setSelectedFlag] = useState(null);
  const [showNoteModal, setShowNoteModal] = useState(false);
  const [showComparisonModal, setShowComparisonModal] = useState(false);
  const [comparisonData, setComparisonData] = useState(null);

  // Fetch flag types for filter dropdown
  const [flagTypes, setFlagTypes] = useState([]);

  useEffect(() => {
    const loadFlags = async () => {
      try {
        setLoading(true);
        const params = new URLSearchParams();
        if (filters.flag_type) params.append('flag_type', filters.flag_type);
        if (filters.student_id) params.append('student_id', filters.student_id);
        if (filters.exercise_id) params.append('exercise_id', filters.exercise_id);
        params.append('page', pagination.page);
        params.append('limit', pagination.limit);

        const response = await api.get(`/api/analytics/sections/${sectionId}/integrity-flags?${params.toString()}`);
        setFlags(response.data.flags);
        setPagination(response.data.pagination);
        setLoading(false);
      } catch (err) {
        setError(err.response?.data?.message || 'Failed to load integrity flags');
        setLoading(false);
      }
    };

    const loadFlagTypes = async () => {
      try {
        // In a real implementation, we might fetch this from an API endpoint
        // For now, we'll use the known flag types from our integrity engine
        setFlagTypes([
          { value: 'HARD_CODING', label: 'Hardcoding Detection' },
          { value: 'BLANK_TEMPLATE', label: 'Blank/Template-only Submission' },
          { value: 'BEHAVIORAL_ANOMALY', label: 'Behavioral Anomaly' },
          { value: 'CODE_GROWTH_ANOMALY', label: 'Code Growth Anomaly' },
          { value: 'PASSIVE_BEHAVIOR_LOG', label: 'Passive Behavior Logging' }
        ]);
      } catch (err) {
        console.warn('Could not load flag types:', err);
      }
    };

    if (sectionId) {
      loadFlags();
      loadFlagTypes();
    }
  }, [sectionId, filters, pagination.page, pagination.limit]);

  const handleFilterChange = (e) => {
    const { name, value } = e.target;
    setFilters(prev => ({
      ...prev,
      [name]: value
    }));
    // Reset to first page when filters change
    setPagination(prev => ({ ...prev, page: 1 }));
  };

  const handlePageChange = (page) => {
    setPagination(prev => ({ ...prev, page }));
  };

  const handleReviewFlag = (flag) => {
    setSelectedFlag(flag);
    setShowNoteModal(true);
  };

  const handleNoteModalClose = () => {
    setSelectedFlag(null);
    setShowNoteModal(false);
  };

  const handleNoteModalSubmit = async (updatedFlag) => {
    try {
      await api.put(`/api/analytics/integrity-flags/${updatedFlag.id}/review`, {
        status: updatedFlag.status,
        instructor_note: updatedFlag.instructor_note
      });

      // Update the flags list
      setFlags(prevFlags =>
        prevFlags.map(flag =>
          flag.id === updatedFlag.id ? updatedFlag : flag
        )
      );

      setShowNoteModal(false);
      setSelectedFlag(null);
    } catch (err) {
      console.error('Failed to update integrity flag:', err);
      // In a real app, we would show an error message to the user
    }
  };

  if (loading) {
    return (
      <div className="space-y-6">
        <div className="flex justify-between items-center">
          <h1 className="text-2xl font-bold">Academic Integrity Flags</h1>
          <button
            onClick={() => navigate(`/instructor/sections/${sectionId}`)}
            className="btn-secondary"
          >
            Back to Section
          </button>
        </div>
        <div className="text-center py-12">
          <div className="animate-spin rounded-full border-4 border-primary border-t-transparent h-12 w-12 mx-auto"></div>
          <p className="mt-4 text-gray-500">Loading integrity flags...</p>
        </div>
      </div>
    );
  }

  if (error) {
    return (
      <div className="space-y-6">
        <div className="flex justify-between items-center">
          <h1 className="text-2xl font-bold">Academic Integrity Flags</h1>
          <button
            onClick={() => navigate(`/instructor/sections/${sectionId}`)}
            className="btn-secondary"
          >
            Back to Section
          </button>
        </div>
        <div className="bg-red-50 border-l-4 border-red-500 text-red-700 p-4">
          {error}
        </div>
      </div>
    );
  }

  return (
    <div className="space-y-6">
      <div className="flex justify-between items-center flex-wrap gap-4">
        <div>
          <h1 className="text-2xl font-bold">Academic Integrity Flags</h1>
          <p className="text-gray-600">
            Monitoring submissions for potential academic integrity concerns
          </p>
        </div>
        <div className="flex items-end gap-3">
          <button
            onClick={() => navigate(`/instructor/sections/${sectionId}`)}
            className="btn-secondary"
          >
            Back to Section
          </button>
        </div>
      </div>

      {/* Filters */}
      <div className="bg-white rounded-lg shadow p-6">
        <div className="grid md:grid-cols-3 gap-4">
          <div>
            <label className="block text-sm font-medium text-gray-700 mb-2">
              Flag Type
            </label>
            <select
              className="w-full px-3 py-2 border border-gray-300 rounded-md focus:outline-none focus:ring-2 focus:ring-primary"
              value={filters.flag_type}
              onChange={handleFilterChange}
              name="flag_type"
            >
              <option value="">All Flag Types</option>
              {flagTypes.map(type => (
                <option key={type.value} value={type.value}>
                  {type.label}
                </option>
              ))}
            </select>
          </div>

          <div>
            <label className="block text-sm font-medium text-gray-700 mb-2">
              Student ID
            </label>
            <input
              type="number"
              className="w-full px-3 py-2 border border-gray-300 rounded-md focus:outline-none focus:ring-2 focus:ring-primary"
              value={filters.student_id || ''}
              onChange={handleFilterChange}
              name="student_id"
              placeholder="Filter by student ID"
            />
          </div>

          <div>
            <label className="block text-sm font-medium text-gray-700 mb-2">
              Exercise ID
            </label>
            <input
              type="number"
              className="w-full px-3 py-2 border border-gray-300 rounded-md focus:outline-none focus:ring-2 focus:ring-primary"
              value={filters.exercise_id || ''}
              onChange={handleFilterChange}
              name="exercise_id"
              placeholder="Filter by exercise ID"
            />
          </div>
        </div>

        <div className="mt-4 flex justify-end">
          <button
            onClick={() => {
              setFilters({ flag_type: '', student_id: '', exercise_id: '' });
              setPagination(prev => ({ ...prev, page: 1 }));
            }}
            className="btn-outline"
          >
            Clear Filters
          </button>
        </div>
      </div>

      {/* Flags Table */}
      <div className="bg-white rounded-lg shadow">
        <div className="overflow-x-auto">
          <table className="min-w-full divide-y divide-gray-200">
            <thead className="bg-gray-50">
              <tr>
                <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">
                  Student
                </th>
                <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">
                  Exercise
                </th>
                <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">
                  Flag Type
                </th>
                <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">
                  Severity
                </th>
                <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">
                  Evidence
                </th>
                <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">
                  Status
                </th>
                <th className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">
                  Actions
                </th>
              </tr>
            </thead>
            <tbody className="bg-white divide-y divide-gray-200">
              {flags.length === 0 ? (
                <tr>
                  <td className="px-6 py-4 text-center text-gray-500" colSpan="7">
                    No integrity flags found matching the current filters.
                  </td>
                </tr>
              ) : (
                flags.map(flag => (
                  <tr key={flag.id} className="hover:bg-gray-50">
                    <td className="px-6 py-4 whitespace-nowrap text-sm text-gray-900">
                      {flag.student_name || 'Unknown Student'}
                    </td>
                    <td className="px-6 py-4 whitespace-nowrap text-sm text-gray-900">
                      {flag.exercise_title || 'Unknown Exercise'}
                    </td>
                    <td className="px-6 py-4 whitespace-nowrap">
                      <IntegrityFlagBadge flagType={flag.flag_type} />
                    </td>
                    <td className="px-6 py-4 whitespace-nowrap text-sm">
                      <span
                        className={`px-2 py-1 text-xs rounded-full
                          ${flag.severity === 'HIGH' ? 'bg-red-100 text-red-800' :
                                flag.severity === 'MEDIUM' ? 'bg-yellow-100 text-yellow-800' :
                                'bg-green-100 text-green-800'}`}
                      >
                        {flag.severity}
                      </span>
                    </td>
                    <td className="px-6 py-4 whitespace-nowrap text-sm text-gray-600 max-w-xs">
                      {flag.evidence ? JSON.stringify(flag.evidence).substring(0, 50) + '...' : 'No evidence'}
                    </td>
                    <td className="px-6 py-4 whitespace-nowrap text-sm">
                      <span
                        className={`px-2 py-1 text-xs rounded-full
                          ${flag.status === 'FLAGGED' ? 'bg-yellow-100 text-yellow-800' :
                                flag.status === 'REVIEWED' ? 'bg-blue-100 text-blue-800' :
                                'bg-gray-100 text-gray-800'}`}
                      >
                        {flag.status}
                      </span>
                    </td>
                    <td className="px-6 py-4 whitespace-nowrap text-sm text-right space-x-2">
                      <button
                        onClick={() => handleReviewFlag(flag)}
                        className="btn-outline btn-sm"
                        disabled={flag.status === 'REVIEWED' || flag.status === 'DISMISSED'}
                      >
                        {flag.status === 'FLAGGED' ? 'Review' : 'View'}
                      </button>
                      {flag.status === 'FLAGGED' && (
                        <button
                          onClick={() => {
                            // In a real implementation, we would have a dismiss function
                            // For now, we'll just treat dismiss as setting status to dismissed
                            handleReviewFlag({ ...flag, status: 'DISMISSED' });
                          }}
                          className="btn-outline btn-sm text-red-600 hover:text-red-800"
                        >
                          Dismiss
                        </button>
                      )}
                    </td>
                  </tr>
                ))
              )}
            </tbody>
          </table>
        </div>

        {/* Pagination */}
        {pagination.total > pagination.limit && (
          <div className="px-6 py-4 border-t border-gray-200 flex justify-between items-center text-sm">
            <span className="text-gray-500">
              Showing {(pagination.page - 1) * pagination.limit + 1}-{Math.min(pagination.page * pagination.limit, pagination.total)} of {pagination.total} flags
            </span>
            <div className="flex space-x-2">
              <button
                onClick={() => handlePageChange(Math.max(1, pagination.page - 1))}
                disabled={pagination.page === 1}
                className="px-3 py-1 border border-gray-300 rounded-md hover:bg-gray-50"
              >
                Previous
              </button>
              <button
                onClick={() => handlePageChange(Math.min(pagination.totalPages, pagination.page + 1))}
                disabled={pagination.page === pagination.totalPages}
                className="px-3 py-1 border border-gray-300 rounded-md hover:bg-gray-50"
              >
                Next
              </button>
            </div>
          </div>
        )}
      </div>

      {showNoteModal && selectedFlag && (
        <IntegrityNoteModal
          flag={selectedFlag}
          onClose={handleNoteModalClose}
          onSubmit={handleNoteModalSubmit}
        />
      )}
    </div>
  );
};

// Modal for instructor notes (local — no separate component file yet)
const IntegrityNoteModal = ({ flag, onClose, onSubmit }) => {
  const [note, setNote] = useState(flag.instructor_note || '');
  const [status, setStatus] = useState(flag.status || 'FLAGGED');

  const handleSubmit = async (e) => {
    e.preventDefault();
    onSubmit({
      ...flag,
      instructor_note: note,
      status
    });
  };

  return (
    <div className="fixed inset-0 z-50 flex items-center justify-center bg-black bg-opacity-50">
      <div className="bg-white rounded-lg shadow-lg w-full max-w-md mx-4">
        <div className="px-6 py-4 border-b border-gray-200">
          <h2 className="text-xl font-bold text-gray-900">
            {flag.status === 'FLAGGED' ? 'Review Integrity Flag' : 'View Integrity Flag'}
          </h2>
          <button
            onClick={onClose}
            className="float-right text-gray-500 hover:text-gray-700"
          >
            ×
          </button>
        </div>
        <form onSubmit={handleSubmit} className="px-6 py-4 space-y-4">
          <div>
            <label className="block text-sm font-medium text-gray-700 mb-2">
              Status
            </label>
            <select
              value={status}
              onChange={(e) => setStatus(e.target.value)}
              className="w-full px-3 py-2 border border-gray-300 rounded-md focus:outline-none focus:ring-2 focus:ring-primary"
            >
              <option value="FLAGGED">Flagged</option>
              <option value="REVIEWED">Reviewed</option>
              <option value="DISMISSED">Dismissed</option>
            </select>
          </div>

          <div>
            <label className="block text-sm font-medium text-gray-700 mb-2">
              Instructor Note
            </label>
            <textarea
              value={note}
              onChange={(e) => setNote(e.target.value)}
              className="w-full px-3 py-2 border border-gray-300 rounded-md focus:outline-none focus:ring-2 focus-ring-primary h-24"
              placeholder="Add notes about your review or actions taken..."
            />
          </div>

          <div className="flex justify-end space-x-3">
            <button
              type="button"
              onClick={onClose}
              className="px-4 py-2 bg-gray-200 text-gray-800 rounded-md hover:bg-gray-300"
            >
              Cancel
            </button>
            <button
              type="submit"
              className="px-4 py-2 bg-primary text-white rounded-md hover:bg-primary-dark"
            >
              {flag.status === 'FLAGGED' ? 'Save Review' : 'Update'}
            </button>
          </div>
        </form>
      </div>
    </div>
  );
};

export default AcademicIntegrityFlags;