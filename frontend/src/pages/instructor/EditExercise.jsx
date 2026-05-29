import React, { useState, useEffect } from 'react';
import axios from 'axios';
import { useNavigate, useParams } from 'react-router-dom';

const EditExercise = () => {
  const [exercise, setExercise] = useState(null);
  const [formData, setFormData] = useState({
    title: '',
    description: '',
    concept_name: '',
    section_id: '',
    time_limit_minutes: '',
    test_cases: [],
    deadline: '',
    is_draft: false,
    track_ner: true,
    track_nrs: true,
    track_nts: true,
    auto_alert: true
  });
  const navigate = useNavigate();
  const { id } = useParams();

  useEffect(() => {
    const fetchExercise = async () => {
      try {
        const res = await axios.get(`/api/exercises/${id}`);
        setExercise(res.data);
        setFormData({
          title: res.data.title,
          description: res.data.description,
          concept_name: res.data.concept_name,
          section_id: res.data.section_id,
          time_limit_minutes: res.data.time_limit_minutes,
          test_cases: res.data.test_cases,
          deadline: res.data.deadline,
          is_draft: res.data.is_draft,
          track_ner: res.data.track_ner,
          track_nrs: res.data.track_nrs,
          track_nts: res.data.track_nts,
          auto_alert: res.data.auto_alert
        });
      } catch (err) {
        console.error(err);
        navigate('/instructor');
      }
    };

    if (id) {
      fetchExercise();
    }
  }, [id, navigate]);

  const handleInputChange = (e) => {
    const { name, value } = e.target;
    setFormData({ ...formData, [name]: value });
  };

  const handleTestCaseChange = (index, value) => {
    const newTestCases = [...formData.test_cases];
    newTestCases[index] = value;
    setFormData({ ...formData, test_cases: newTestCases });
  };

  const handleAddTestCase = () => {
    setFormData({ ...formData, test_cases: [...formData.test_cases, ''] });
  };

  const handleDeleteTestCase = (index) => {
    const filtered = formData.test_cases.filter((t, i) => i !== index);
    setFormData({ ...formData, test_cases: filtered });
  };

  const handleSubmit = async (e) => {
    e.preventDefault();
    try {
      const accessToken = localStorage.getItem('ci_token');
      const res = await axios.put(
        `/api/exercises/${id}`,
        formData,
        {
          headers: {
            Authorization: `Bearer ${accessToken}`,
            'Content-Type': 'application/json'
          }
        }
      );
      navigate(`/instructor/sections/${res.data.section_id}`);
    } catch (err) {
      console.error(err);
    }
  };

  if (!exercise) return <div>Loading...</div>;

  return (
    <div className='exercise-form-container'>
      <h2>Edit Exercise</h2>
      <form onSubmit={handleSubmit}>
        {/* Title */}
        <div className='form-group'>
          <label>Title</label>
          <input
            type='text'
            name='title'
            value={formData.title}
            onChange={handleInputChange}
            required
          />
        </div>
        {/* Description */}
        <div className='form-group'>
          <label>Description</label>
          <textarea
            name='description'
            value={formData.description}
            onChange={handleInputChange}
            required
          />
        </div>
        {/* Concept Name */}
        <div className='form-group'>
          <label>Concept</label>
          <input
            type='text'
            name='concept_name'
            value={formData.concept_name}
            onChange={handleInputChange}
            required
          />
        </div>
        {/* Section ID */}
        <div className='form-group'>
          <label>Section ID</label>
          <input
            type='number'
            name='section_id'
            value={formData.section_id || ''}
            onChange={handleInputChange}
            required
          />
        </div>
        {/* Time Limit */}
        <div className='form-group'>
          <label>Time Limit (minutes)</label>
          <input
            type='number'
            name='time_limit_minutes'
            value={formData.time_limit_minutes}
            onChange={handleInputChange}
            min='5' max='240'
          />
        </div>
        {/* Test Cases */}
        <div className='form-group'>
          <label>Test Cases (JSON format)</label>
          <div className='test-case-list'>
            {formData.test_cases.map((tc, index) => (
              <div key={index} className='test-case-input'>
                <textarea
                  value={tc}
                  onChange={(e) => handleTestCaseChange(index, e.target.value)}
                  placeholder='Test case #${index + 1}'
                />
                {index !== 0 && (
                  <button
                    type='button'
                    onClick={() => handleDeleteTestCase(index)}
                  >
                    Delete
                  </button>
                )}
              </div>
            ))}
          </div>
          <button
            type='button'
            onClick={handleAddTestCase}
            className='add-more-btn'
          >
            Add Test Case
          </button>
        </div>
        {/* Draft Status */}
        <div className='form-group'>
          <label>
            <input
              type='checkbox'
              name='is_draft'
              checked={formData.is_draft}
              onChange={(e) => setFormData({ ...formData, is_draft: e.target.checked })}
            />
            Draft (not visible to students)
          </label>
        </div>
        {/* Tracking Options */}
        <div className='form-group'>
          <div>
            <label>
              <input
                type='checkbox'
                name='track_ner'
                checked={formData.track_ner}
                onChange={(e) => setFormData({ ...formData, track_ner: e.target.checked })}
              />
              Track NER (Number of Errors Ratio)
            </label>
          </div>
          <div>
            <label>
              <input
                type='checkbox'
                name='track_nrs'
                checked={formData.track_nrs}
                onChange={(e) => setFormData({ ...formData, track_nrs: e.target.checked })}
              />
              Track NRS (Number of Submissions Ratio)
            </label>
          </div>
          <div>
            <label>
              <input
                type='checkbox'
                name='track_nts'
                checked={formData.track_nts}
                onChange={(e) => setFormData({ ...formData, track_nts: e.target.checked })}
              />
              Track NTS (Normalized Time Spent)
            </label>
          </div>
          <div>
            <label>
              <input
                type='checkbox'
                name='auto_alert'
                checked={formData.auto_alert}
                onChange={(e) => setFormData({ ...formData, auto_alert: e.target.checked })}
              />
              Auto-generate alerts for High CDS students
            </label>
          </div>
        </div>
        {/* Deadline */}
        <div className='form-group'>
          <label>Deadline (ISO date string)</label>
          <input
            type='datetime-local'
            name='deadline'
            min={new Date().toISOString().split('.')[0]}
            value={formData.deadline || ''}
            onChange={handleInputChange}
          />
        </div>
        {/* Submit Buttons */}
        <div className='submit-buttons'>
          <button type='submit'>Save Changes</button>
          <button type='button' onClick={() => navigate('/instructor')}>Cancel</button>
        </div>
      </form>
    </div>
  );
};

export default EditExercise;
