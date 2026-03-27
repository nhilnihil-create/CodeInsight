import { BrowserRouter, Routes, Route, Navigate } from 'react-router-dom';
import { useAuth } from './context/AuthContext';
import { SidebarProvider } from './context/SidebarContext';
import Login from './pages/Login';
import InstructorDashboard from './pages/instructor/Dashboard';
import InstructorSections from './pages/instructor/Sections';
import SectionDetail from './pages/instructor/SectionDetail';
import InstructorCreateExercise from './pages/instructor/CreateExercise';
import InstructorAlerts from './pages/instructor/Alerts';
import InstructorDeveloper from './pages/instructor/Developer';
import StudentExercises from './pages/student/Exercises';
import StudentExerciseList from './pages/student/ExerciseList';
import StudentCodeEditor from './pages/student/CodeEditor';
import StudentProgress from './pages/student/Progress';
import ErrorBoundary from './components/ErrorBoundary';
import Layout from './components/Layout';

function ProtectedRoute({ children, requiredRole }) {
  const { isLoggedIn, user } = useAuth();

  if (!isLoggedIn) return <Navigate to="/login" replace />;
  if (requiredRole && user?.role !== requiredRole) {
    const home = user?.role === 'instructor' ? '/instructor' : '/student';
    return <Navigate to={home} replace />;
  }
  return <Layout>{children}</Layout>;
}

function AppContent() {
  return (
    <BrowserRouter>
      <Routes>
        <Route path="/login" element={<Login />} />
        <Route path="/" element={<Navigate to="/login" replace />} />
        
        {/* Instructor Routes */}
        <Route path="/instructor" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorDashboard />
          </ProtectedRoute>
        } />
        <Route path="/instructor/sections" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorSections />
          </ProtectedRoute>
        } />
        <Route path="/instructor/sections/:sectionId" element={
          <ProtectedRoute requiredRole="instructor">
            <SectionDetail />
          </ProtectedRoute>
        } />
        <Route path="/instructor/create-exercise" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorCreateExercise />
          </ProtectedRoute>
        } />
        <Route path="/instructor/alerts" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorAlerts />
          </ProtectedRoute>
        } />
        <Route path="/instructor/developer" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorDeveloper />
          </ProtectedRoute>
        } />
        
        {/* Student Routes */}
        <Route path="/student" element={
          <ProtectedRoute requiredRole="student">
            <StudentExercises />
          </ProtectedRoute>
        } />
        <Route path="/student/exercises" element={
          <ProtectedRoute requiredRole="student">
            <StudentExerciseList />
          </ProtectedRoute>
        } />
        <Route path="/student/exercises/:exerciseId" element={
          <ProtectedRoute requiredRole="student">
            <StudentCodeEditor />
          </ProtectedRoute>
        } />
        <Route path="/student/progress" element={
          <ProtectedRoute requiredRole="student">
            <StudentProgress />
          </ProtectedRoute>
        } />
        
        <Route path="*" element={<Navigate to="/login" replace />} />
      </Routes>
    </BrowserRouter>
  );
}

function App() {
  return (
    <ErrorBoundary>
      <SidebarProvider>
        <AppContent />
      </SidebarProvider>
    </ErrorBoundary>
  );
}

export default App;
