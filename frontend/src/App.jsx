import { BrowserRouter, Routes, Route, Navigate } from 'react-router-dom';
import { useAuth } from './context/AuthContext';
import { SidebarProvider } from './context/SidebarContext';
import Landing from './pages/Landing';
import Login from './pages/Login';
import InstructorDashboard from './pages/instructor/Dashboard';
import InstructorSections from './pages/instructor/Sections';
import SectionDetail from './pages/instructor/SectionDetail';
import InstructorCreateExercise from './pages/instructor/CreateExercise';
import InstructorEditExercise from './pages/instructor/EditExercise';
import InstructorAlerts from './pages/instructor/Alerts';
import AcademicIntegrityFlags from './pages/instructor/AcademicIntegrityFlags';
import InstructorDeveloper from './pages/instructor/Developer';
import InstructorReports from './pages/instructor/Reports';
import StudentDashboard from './pages/student/Dashboard';
import StudentExerciseList from './pages/student/Exercises';
import StudentCodeEditor from './pages/student/CodeEditor';
import StudentProgress from './pages/student/Progress';
import StudentProfile from './pages/student/Profile';
import ErrorBoundary from './components/ErrorBoundary';
import Layout from './components/Layout';
import NotFound from './pages/NotFound';

function ProtectedRoute({ children, requiredRole, pageTitle }) {
  const { isLoggedIn, user } = useAuth();

  if (!isLoggedIn) return <Navigate to="/login" replace />;
  if (requiredRole && user?.role !== requiredRole) {
    const home = user?.role === 'instructor' ? '/instructor/dashboard' : '/student/dashboard';
    return <Navigate to={home} replace />;
  }
  return <Layout pageTitle={pageTitle}>{children}</Layout>;
}

function AppContent() {
  return (
    <BrowserRouter>
      <Routes>
        <Route path="/" element={<Landing />} />
        <Route path="/login" element={<Login />} />
        
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
        <Route path="/instructor/sections/:sectionId/academic-integrity" element={
          <ProtectedRoute requiredRole="instructor">
            <AcademicIntegrityFlags />
          </ProtectedRoute>
        } />
        <Route path="/instructor/create-exercise" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorCreateExercise />
          </ProtectedRoute>
        } />
        <Route path="/instructor/exercises/:id/edit" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorEditExercise />
          </ProtectedRoute>
        } />
        <Route path="/instructor/alerts" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorAlerts />
          </ProtectedRoute>
        } />
        <Route path="/instructor/reports" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorReports />
          </ProtectedRoute>
        } />
        <Route path="/instructor/developer" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorDeveloper />
          </ProtectedRoute>
        } />
        
        {/* Student Routes */}
        <Route path="/student" element={
          <ProtectedRoute requiredRole="student" pageTitle="Dashboard">
            <StudentDashboard />
          </ProtectedRoute>
        } />
        <Route path="/student/exercises" element={
          <ProtectedRoute requiredRole="student" pageTitle="Exercises">
            <StudentExerciseList />
          </ProtectedRoute>
        } />
        <Route path="/student/exercises/:exerciseId" element={
          <ProtectedRoute requiredRole="student" pageTitle="Code Editor">
            <StudentCodeEditor />
          </ProtectedRoute>
        } />
        <Route path="/student/progress" element={
          <ProtectedRoute requiredRole="student">
            <StudentProgress />
          </ProtectedRoute>
        } />

        {/* Design-aligned URL paths (new aliases for design nav parity) */}
        <Route path="/student/dashboard" element={
          <ProtectedRoute requiredRole="student" pageTitle="Dashboard">
            <StudentDashboard />
          </ProtectedRoute>
        } />
        <Route path="/student/code-editor" element={
          <ProtectedRoute requiredRole="student" pageTitle="Code Editor">
            <StudentCodeEditor />
          </ProtectedRoute>
        } />
        <Route path="/student/code-editor/:exerciseId" element={
          <ProtectedRoute requiredRole="student" pageTitle="Code Editor">
            <StudentCodeEditor />
          </ProtectedRoute>
        } />
        <Route path="/student/profile" element={
          <ProtectedRoute requiredRole="student">
            <StudentProfile />
          </ProtectedRoute>
        } />
        <Route path="/instructor/dashboard" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorDashboard />
          </ProtectedRoute>
        } />
        <Route path="/instructor/my-sections" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorSections />
          </ProtectedRoute>
        } />
        <Route path="/instructor/students" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorSections />
          </ProtectedRoute>
        } />
        <Route path="/instructor/exercises" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorCreateExercise />
          </ProtectedRoute>
        } />
        <Route path="/instructor/integrity" element={
          <ProtectedRoute requiredRole="instructor">
            <AcademicIntegrityFlags />
          </ProtectedRoute>
        } />
        <Route path="/instructor/warnings" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorAlerts />
          </ProtectedRoute>
        } />
        <Route path="/instructor/violations" element={
          <ProtectedRoute requiredRole="instructor">
            <AcademicIntegrityFlags />
          </ProtectedRoute>
        } />

        <Route path="*" element={<NotFound />} />
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
