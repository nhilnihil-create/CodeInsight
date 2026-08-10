import { BrowserRouter, Routes, Route, Navigate } from 'react-router-dom';
import { useAuth } from './context/AuthContext';
import { SidebarProvider } from './context/SidebarContext';
import { StudentProvider } from './context/StudentContext';
import { ThemeProvider } from './lib/theme.jsx';
import Landing from './pages/Landing';
import Login from './pages/Login';
import Register from './pages/Register';
import InstructorDashboard from './pages/instructor/Dashboard';
import InstructorHeatmap from './pages/instructor/Heatmap';
import InstructorStudents from './pages/instructor/Students';
import InstructorStudentDetail from './pages/instructor/StudentDetail';
import InstructorExercises from './pages/instructor/Exercises';
import ExerciseWorkspace from './pages/instructor/ExerciseWorkspace';
import InstructorReports from './pages/instructor/Reports';
import InstructorExerciseExplorer from './pages/instructor/ExerciseExplorer';
import InstructorIntegrity from './pages/instructor/Integrity';
import InstructorAlerts from './pages/instructor/Alerts';
// Section management — preserved per user directive 2026-06-04
import InstructorSections from './pages/instructor/Sections';
import SectionDetail from './pages/instructor/SectionDetail';
import AcademicIntegrityFlags from './pages/instructor/AcademicIntegrityFlags';
import StructureViolations from './pages/instructor/StructureViolations';
import ClassMicroConceptReport from './pages/instructor/ClassMicroConceptReport';
import InstructorCommand from './pages/instructor/Command';

import StudentDashboard from './pages/student/Dashboard';
import StudentToday from './pages/student/Today';
import StudentRecommendations from './pages/student/Recommendations';
import StudentSections from './pages/student/Sections';
import StudentExerciseList from './pages/student/Exercises';
import StudentCodeEditor from './pages/student/CodeEditor';
import StudentProgress from './pages/student/Progress';
import StudentProfile from './pages/student/Profile';
import ErrorBoundary from './components/ErrorBoundary';
import Layout from './components/Layout';
import RequireSection from './components/require-section';
import NotFound from './pages/NotFound';
import AdminOverview from './pages/admin/Overview';
import AdminUsers from './pages/admin/Users';
import AdminSectionsOverview from './pages/admin/Sections';
import AdminConcepts from './pages/admin/Concepts';
import AdminExercises from './pages/admin/Exercises';
import AdminEvaluation from './pages/admin/Evaluation';
import AdminAudit from './pages/admin/Audit';
import AdminFlags from './pages/admin/Flags';
import AdminSettings from './pages/admin/Settings';

function ProtectedRoute({ children, requiredRole }) {
  const { isLoggedIn, user } = useAuth();

  if (!isLoggedIn) return <Navigate to="/login" replace />;
  if (requiredRole && user?.role !== requiredRole) {
    const home = user?.role === 'instructor'
      ? '/instructor/dashboard'
      : user?.role === 'admin'
        ? '/admin'
        : '/student/dashboard';
    return <Navigate to={home} replace />;
  }
  return <Layout>{children}</Layout>;
}

function AppContent() {
  return (
    <BrowserRouter>
      <Routes>
        <Route path="/" element={<Landing />} />
        <Route path="/login" element={<Login />} />
        <Route path="/register" element={<Register />} />
        
        {/* Instructor Routes — design paths canonical */}
        <Route path="/instructor/command" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorCommand />
          </ProtectedRoute>
        } />
        <Route path="/instructor/dashboard" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorDashboard />
          </ProtectedRoute>
        } />
        <Route path="/instructor/heatmap" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorHeatmap />
          </ProtectedRoute>
        } />
        <Route path="/instructor/students" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorStudents />
          </ProtectedRoute>
        } />
        <Route path="/instructor/students/:id" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorStudentDetail />
          </ProtectedRoute>
        } />
        <Route path="/instructor/exercises" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorExercises />
          </ProtectedRoute>
        } />
        <Route path="/instructor/explorer" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorExerciseExplorer />
          </ProtectedRoute>
        } />
        <Route path="/instructor/exercises/new" element={
          <ProtectedRoute requiredRole="instructor">
            <ExerciseWorkspace />
          </ProtectedRoute>
        } />
        <Route path="/instructor/exercises/workspace" element={
          <ProtectedRoute requiredRole="instructor">
            <ExerciseWorkspace />
          </ProtectedRoute>
        } />
        <Route path="/instructor/exercises/bulk-create" element={
          <ProtectedRoute requiredRole="instructor">
            <Navigate to="/instructor/exercises/workspace" replace />
          </ProtectedRoute>
        } />
        <Route path="/instructor/exercises/:id/edit" element={
          <ProtectedRoute requiredRole="instructor">
            <ExerciseWorkspace />
          </ProtectedRoute>
        } />
        <Route path="/instructor/create-exercise" element={
          <ProtectedRoute requiredRole="instructor">
            <Navigate to="/instructor/exercises/new" replace />
          </ProtectedRoute>
        } />
        <Route path="/instructor/warnings" element={
          <Navigate to="/instructor/integrity" replace />
        } />
        <Route path="/instructor/reports" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorReports />
          </ProtectedRoute>
        } />
        <Route path="/instructor/violations" element={
          <Navigate to="/instructor/integrity" replace />
        } />
        <Route path="/instructor/integrity" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorIntegrity />
          </ProtectedRoute>
        } />
        <Route path="/instructor/integrity/:id" element={
          <Navigate to="/instructor/integrity" replace />
        } />

        {/* Instructor alias routes (CodeInsight paths kept working) */}
        <Route path="/instructor" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorDashboard />
          </ProtectedRoute>
        } />
        {/* /instructor/create-exercise is an alias for the design form;
            /instructor/alerts is the Intervention Queue; /instructor/{warnings,violations}
            redirect to the unified /integrity page. */}
        <Route path="/instructor/create-exercise" element={
          <ProtectedRoute requiredRole="instructor">
            <Navigate to="/instructor/exercises/new" replace />
          </ProtectedRoute>
        } />
        <Route path="/instructor/alerts" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorAlerts />
          </ProtectedRoute>
        } />
        {/* Section management routes — PRESERVED per user directive 2026-06-04.
            /instructor/my-sections and /instructor/sections stay on the legacy
            Sections.jsx / SectionDetail.jsx / AcademicIntegrityFlags.jsx files. */}
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
        <Route path="/instructor/sections/:sectionId/structure-violations" element={
          <ProtectedRoute requiredRole="instructor">
            <StructureViolations />
          </ProtectedRoute>
        } />
        <Route path="/instructor/sections/:sectionId/micro-concepts" element={
          <ProtectedRoute requiredRole="instructor">
            <ClassMicroConceptReport />
          </ProtectedRoute>
        } />

        <Route path="/instructor/my-sections" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorSections />
          </ProtectedRoute>
        } />

        {/* Student Routes */}
        <Route path="/student/today" element={
          <ProtectedRoute requiredRole="student">
            <RequireSection><StudentToday /></RequireSection>
          </ProtectedRoute>
        } />
        <Route path="/student/sections" element={
          <ProtectedRoute requiredRole="student">
            <StudentSections />
          </ProtectedRoute>
        } />
        <Route path="/student/recommendations" element={
          <ProtectedRoute requiredRole="student">
            <RequireSection><StudentRecommendations /></RequireSection>
          </ProtectedRoute>
        } />
        <Route path="/student" element={
          <ProtectedRoute requiredRole="student">
            <RequireSection><StudentDashboard /></RequireSection>
          </ProtectedRoute>
        } />
        <Route path="/student/exercises" element={
          <ProtectedRoute requiredRole="student">
            <RequireSection><StudentExerciseList /></RequireSection>
          </ProtectedRoute>
        } />
        <Route path="/student/exercises/:exerciseId" element={
          <ProtectedRoute requiredRole="student">
            <RequireSection><StudentCodeEditor /></RequireSection>
          </ProtectedRoute>
        } />
        <Route path="/student/progress" element={
          <ProtectedRoute requiredRole="student">
            <RequireSection><StudentProgress /></RequireSection>
          </ProtectedRoute>
        } />

        {/* Design-aligned URL paths (new aliases for design nav parity) */}
        <Route path="/student/dashboard" element={
          <ProtectedRoute requiredRole="student">
            <RequireSection><StudentDashboard /></RequireSection>
          </ProtectedRoute>
        } />
        <Route path="/student/code-editor" element={
          <ProtectedRoute requiredRole="student">
            <RequireSection><StudentCodeEditor /></RequireSection>
          </ProtectedRoute>
        } />
        <Route path="/student/code-editor/:exerciseId" element={
          <ProtectedRoute requiredRole="student">
            <RequireSection><StudentCodeEditor /></RequireSection>
          </ProtectedRoute>
        } />
        <Route path="/student/profile" element={
          <ProtectedRoute requiredRole="student">
            <RequireSection><StudentProfile /></RequireSection>
          </ProtectedRoute>
        } />

        {/* Admin routes */}
        <Route path="/admin" element={
          <ProtectedRoute requiredRole="admin">
            <AdminOverview />
          </ProtectedRoute>
        } />
        <Route path="/admin/overview" element={
          <ProtectedRoute requiredRole="admin">
            <AdminOverview />
          </ProtectedRoute>
        } />
        <Route path="/admin/users" element={
          <ProtectedRoute requiredRole="admin">
            <AdminUsers />
          </ProtectedRoute>
        } />
        <Route path="/admin/sections" element={
          <ProtectedRoute requiredRole="admin">
            <AdminSectionsOverview />
          </ProtectedRoute>
        } />
        <Route path="/admin/concepts" element={
          <ProtectedRoute requiredRole="admin">
            <AdminConcepts />
          </ProtectedRoute>
        } />
        <Route path="/admin/exercises" element={
          <ProtectedRoute requiredRole="admin">
            <AdminExercises />
          </ProtectedRoute>
        } />
        <Route path="/admin/evaluation" element={
          <ProtectedRoute requiredRole="admin">
            <AdminEvaluation />
          </ProtectedRoute>
        } />
        <Route path="/admin/audit" element={
          <ProtectedRoute requiredRole="admin">
            <AdminAudit />
          </ProtectedRoute>
        } />
        <Route path="/admin/flags" element={
          <ProtectedRoute requiredRole="admin">
            <AdminFlags />
          </ProtectedRoute>
        } />
        <Route path="/admin/settings" element={
          <ProtectedRoute requiredRole="admin">
            <AdminSettings />
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
          <StudentProvider>
            <AppContent />
          </StudentProvider>
        </ThemeProvider>
      </SidebarProvider>
    </ErrorBoundary>
  );
}

export default App;
