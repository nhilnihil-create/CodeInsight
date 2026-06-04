import { BrowserRouter, Routes, Route, Navigate } from 'react-router-dom';
import { useAuth } from './context/AuthContext';
import { SidebarProvider } from './context/SidebarContext';
import { ThemeProvider } from './lib/theme.jsx';
import Landing from './pages/Landing';
import Login from './pages/Login';
import InstructorDashboard from './pages/instructor/Dashboard';
import InstructorHeatmap from './pages/instructor/Heatmap';
import InstructorStudents from './pages/instructor/Students';
import InstructorStudentDetail from './pages/instructor/StudentDetail';
import InstructorExercises from './pages/instructor/Exercises';
import InstructorExerciseForm from './pages/instructor/ExerciseForm';
import InstructorWarnings from './pages/instructor/Warnings';
import InstructorReports from './pages/instructor/Reports';
import InstructorViolations from './pages/instructor/Violations';
import InstructorIntegrity from './pages/instructor/Integrity';
// Section management — preserved per user directive 2026-06-04
import InstructorSections from './pages/instructor/Sections';
import SectionDetail from './pages/instructor/SectionDetail';
import AcademicIntegrityFlags from './pages/instructor/AcademicIntegrityFlags';
import InstructorDeveloper from './pages/instructor/Developer';
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
        
        {/* Instructor Routes — design paths canonical */}
        <Route path="/instructor/dashboard" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Dashboard">
            <InstructorDashboard />
          </ProtectedRoute>
        } />
        <Route path="/instructor/heatmap" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Class Heatmap">
            <InstructorHeatmap />
          </ProtectedRoute>
        } />
        <Route path="/instructor/students" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Students">
            <InstructorStudents />
          </ProtectedRoute>
        } />
        <Route path="/instructor/students/:id" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Student Detail">
            <InstructorStudentDetail />
          </ProtectedRoute>
        } />
        <Route path="/instructor/exercises" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Exercises">
            <InstructorExercises />
          </ProtectedRoute>
        } />
        <Route path="/instructor/exercises/new" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="New Exercise">
            <InstructorExerciseForm />
          </ProtectedRoute>
        } />
        <Route path="/instructor/exercises/:id/edit" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Edit Exercise">
            <InstructorExerciseForm />
          </ProtectedRoute>
        } />
        <Route path="/instructor/warnings" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Early Warnings">
            <InstructorWarnings />
          </ProtectedRoute>
        } />
        <Route path="/instructor/reports" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Reports">
            <InstructorReports />
          </ProtectedRoute>
        } />
        <Route path="/instructor/violations" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Structure Violations">
            <InstructorViolations />
          </ProtectedRoute>
        } />
        <Route path="/instructor/integrity" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Academic Integrity">
            <InstructorIntegrity />
          </ProtectedRoute>
        } />
        <Route path="/instructor/developer" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Developer">
            <InstructorDeveloper />
          </ProtectedRoute>
        } />

        {/* Instructor alias routes (CodeInsight paths kept working) */}
        <Route path="/instructor" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Dashboard">
            <InstructorDashboard />
          </ProtectedRoute>
        } />
        {/* /instructor/create-exercise and /instructor/alerts are aliases for the design forms */}
        <Route path="/instructor/create-exercise" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="New Exercise">
            <InstructorExerciseForm />
          </ProtectedRoute>
        } />
        <Route path="/instructor/alerts" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Early Warnings">
            <InstructorWarnings />
          </ProtectedRoute>
        } />
        {/* Section management routes — PRESERVED per user directive 2026-06-04.
            /instructor/my-sections and /instructor/sections stay on the legacy
            Sections.jsx / SectionDetail.jsx / AcademicIntegrityFlags.jsx files. */}
        <Route path="/instructor/sections" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Sections">
            <InstructorSections />
          </ProtectedRoute>
        } />
        <Route path="/instructor/sections/:sectionId" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Section Detail">
            <SectionDetail />
          </ProtectedRoute>
        } />
        <Route path="/instructor/sections/:sectionId/academic-integrity" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Academic Integrity">
            <AcademicIntegrityFlags />
          </ProtectedRoute>
        } />
        <Route path="/instructor/my-sections" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Sections">
            <InstructorSections />
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

        <Route path="*" element={<NotFound />} />
      </Routes>
    </BrowserRouter>
  );
}

function App() {
  return (
    <ErrorBoundary>
      <SidebarProvider>
        <ThemeProvider>
          <AppContent />
        </ThemeProvider>
      </SidebarProvider>
    </ErrorBoundary>
  );
}

export default App;
