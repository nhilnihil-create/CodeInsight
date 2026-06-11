import axios from 'axios';

const api = axios.create({
  baseURL: import.meta.env.VITE_API_BASE_URL || 'http://localhost:5000',
  withCredentials: true, // send httpOnly cookie with every request
});

// No Authorization header interceptor — the JWT lives in the httpOnly
// ci_token cookie set by the backend and sent automatically via withCredentials.

api.interceptors.response.use(
  res => res,
  err => {
    if (err.response?.status === 401 && window.location.pathname !== '/login') {
      // Cookie expired or cleared — redirect to login unless already there.
      window.location.href = '/login';
    }
    return Promise.reject(err);
  }
);

export default api;
