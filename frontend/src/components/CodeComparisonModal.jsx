import React, { useState, useEffect } from 'react';
import api from '../services/api';

const CodeComparisonModal = ({
  exerciseId,
  studentId,
  submissionCode,
  onClose
}) => {
  const [exerciseData, setExerciseData] = useState(null);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [editorOptions] = useState({
    theme: 'vs-dark',
    language: 'cpp',
    automaticLayout: true,
    readOnly: true
  });

  useEffect(() => {
    const loadExerciseAndSubmission = async () => {
      try {
        setLoading(true);
        // Fetch exercise to get starter_code (as reference solution placeholder)
        const exerciseResponse = await api.get(`/api/exercises/${exerciseId}`);
        // Fetch submission for this student and exercise
        const submissionResponse = await api.get(`/api/submissions/${studentId}/${exerciseId}`);

        setExerciseData({
          starter_code: exerciseResponse.data.starter_code || '#include <iostream>\nusing namespace std;\n\nint main() {\n    return 0;\n}',
          submission_code: submissionResponse.data.code || ''
        });
        setLoading(false);
      } catch (err) {
        setError('Failed to load exercise or submission data');
        setLoading(false);
        console.error(err);
      }
    };

    if (exerciseId && studentId) {
      loadExerciseAndSubmission();
    }
  }, [exerciseId, studentId]);

  if (loading) {
    return (
      <div className="fixed inset-0 z-50 flex items-center justify-center bg-black bg-opacity-50">
        <div className="bg-white rounded-lg shadow-lg w-full max-w-2xl mx-4 h-[90vh] flex flex-col">
          <div className="px-6 py-4 border-b border-gray-200 flex justify-between items-center">
            <h2 className="text-xl font-bold text-gray-900">Code Comparison</h2>
            <button
              onClick={onClose}
              className="text-gray-500 hover:text-gray-700"
            >
              ×
            </button>
          </div>
          <div className="flex-1 flex p-6">
            <div className="w-1/2 space-y-2">
              <p className="text-sm font-medium text-gray-600">Reference Solution (Starter Code)</p>
              <div className="h-full w-full border rounded bg-gray-100">
                <div className="flex items-center justify-center h-full text-gray-400">
                  Loading...
                </div>
              </div>
            </div>
            <div className="w-1/2 space-y-2">
              <p className="text-sm font-medium text-gray-600">Student Submission</p>
              <div className="h-full w-full border rounded bg-gray-100">
                <div className="flex items-center justify-center h-full text-gray-400">
                  Loading...
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
    );
  }

  if (error) {
    return (
      <div className="fixed inset-0 z-50 flex items-center justify-center bg-black bg-opacity-50">
        <div className="bg-white rounded-lg shadow-lg w-full max-w-2xl mx-4 h-[90vh] flex flex-col">
          <div className="px-6 py-4 border-b border-gray-200 flex justify-between items-center">
            <h2 className="text-xl font-bold text-gray-900">Code Comparison</h2>
            <button
              onClick={onClose}
              className="text-gray-500 hover:text-gray-700"
            >
              ×
            </button>
          </div>
          <div className="flex-1 flex p-6">
            <div className="w-full space-y-4">
              <p className="text-red-500 text-center">{error}</p>
              <button
                onClick={onClose}
                className="w-full px-4 py-2 bg-primary text-white rounded-md hover:bg-primary-dark"
              >
                Close
              </button>
            </div>
          </div>
        </div>
      </div>
    );
  }

  return (
    <div className="fixed inset-0 z-50 flex items-center justify-center bg-black bg-opacity-50">
      <div className="bg-white rounded-lg shadow-lg w-full max-w-2xl mx-4 h-[90vh] flex flex-col">
        <div className="px-6 py-4 border-b border-gray-200 flex justify-between items-center">
          <h2 className="text-xl font-bold text-gray-900">Code Comparison</h2>
          <button
            onClick={onClose}
            className="text-gray-500 hover:text-gray-700"
          >
            ×
          </button>
        </div>
        <div className="flex-1 flex p-6 gap-4">
          {/* Reference Solution */}
          <div className="w-1/2 space-y-2">
            <p className="text-sm font-medium text-gray-600">
              Reference Solution
              <span className="text-xs text-gray-500">(starter code placeholder)</span>
            </p>
            <div className="h-full w-full border rounded">
              {/* Monaco Editor would go here - simplified for now */}
              <div className="h-full w-full p-4 font-mono text-sm bg-gray-50 overflow-auto">
                {exerciseData.starter_code}
              </div>
            </div>
          </div>

          {/* Student Submission */}
          <div className="w-1/2 space-y-2">
            <p className="text-sm font-medium text-gray-600">Student Submission</p>
            <div className="h-full w-full border rounded">
              <div className="h-full w-full p-4 font-mono text-sm bg-gray-50 overflow-auto">
                {exerciseData.submission_code}
              </div>
            </div>
          </div>
        </div>
        <div className="px-6 py-4 border-t border-gray-200 flex justify-end">
          <button
            onClick={onClose}
            className="px-4 py-2 bg-primary text-white rounded-md hover:bg-primary-dark"
          >
            Close
          </button>
        </div>
      </div>
    </div>
  );
};

export default CodeComparisonModal;