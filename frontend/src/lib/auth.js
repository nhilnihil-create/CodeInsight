// Ported from Frontend-Design/Frontend-Design/artifacts/codeinsight/src/lib/auth.ts
//
// NOTE: This is a MOCK auth helper used only by the new student pages
// (Dashboard.new, Exercises.new, CodeEditor.new). The real auth path
// lives in context/AuthContext.jsx and is what /login uses.

import { MOCK_USERS } from '../data/mockData';

export const login = (email, role) => {
  const user =
    MOCK_USERS.find((u) => u.email === email && u.role === role) ||
    MOCK_USERS.find((u) => u.role === role);
  localStorage.setItem('codeinsight_user', JSON.stringify(user));
  return user;
};

export const logout = () => {
  localStorage.removeItem('codeinsight_user');
};

export const getCurrentUser = () => {
  const data = localStorage.getItem('codeinsight_user');
  return data ? JSON.parse(data) : null;
};
