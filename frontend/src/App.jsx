import { BrowserRouter, Routes, Route, Navigate } from 'react-router-dom';
import { useAuth } from './context/AuthContext';
import { SidebarProvider } from './context/SidebarContext';
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
import InstructorCustomHeatmap from './pages/instructor/CustomHeatmap';
import InstructorCustomTags from './pages/instructor/CustomTags';
import StudentDashboard from './pages/student/Dashboard';
import StudentToday from './pages/student/Today';
import StudentRecommendations from './pages/student/Recommendations';
import StudentSections from './pages/student/Sections';
import StudentIntegrityView from './pages/student/Integrity';
import StudentExerciseList from './pages/student/Exercises';
import StudentCodeEditor from './pages/student/CodeEditor';
import StudentProgress from './pages/student/Progress';
import StudentProfile from './pages/student/Profile';
import ErrorBoundary from './components/ErrorBoundary';
import Layout from './components/Layout';
import NotFound from './pages/NotFound';
import { useMode } from './hooks/use-mobile.js';
import { MobileChrome } from './components/MobileChrome.jsx';

// Mobile page imports (14 total)
import MobileInstructorCommand from './pages/mobile/instructor/Command.jsx';
import MobileInstructorStudents from './pages/mobile/instructor/Students.jsx';
import MobileInstructorConcepts from './pages/mobile/instructor/Concepts.jsx';
import MobileInstructorIntegrity from './pages/mobile/instructor/Integrity.jsx';
import MobileInstructorSections from './pages/mobile/instructor/Sections.jsx';
import MobileStudentToday from './pages/mobile/student/Today.jsx';
import MobileStudentExercises from './pages/mobile/student/Exercises.jsx';
import MobileStudentExerciseDetail from './pages/mobile/student/ExerciseDetail.jsx';
import MobileStudentProgress from './pages/mobile/student/Progress.jsx';
import MobileStudentIntegrity from './pages/mobile/student/Integrity.jsx';
import MobileStudentSections from './pages/mobile/student/Sections.jsx';
import AdminOverview from './pages/admin/Overview';
import AdminUsers from './pages/admin/Users';
import AdminSectionsOverview from './pages/admin/Sections';
import AdminConcepts from './pages/admin/Concepts';
import AdminExercises from './pages/admin/Exercises';
import AdminEvaluation from './pages/admin/Evaluation';
import AdminAudit from './pages/admin/Audit';
import MobileAdminOverview from './pages/mobile/admin/Overview.jsx';
import MobileAdminEvaluation from './pages/mobile/admin/Evaluation.jsx';
import MobileAdminAudit from './pages/mobile/admin/Audit.jsx';

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

function ModeSwitch({ mobile, desktop }) {
  const mode = useMode();
  // Spec §2.2: phone (mobile mode) gets the mobile page; tablet+desktop get desktop.
  // We treat 'tablet' as desktop to avoid forcing a third layout surface (out of v1 scope).
  if (mode === 'mobile' && mobile) return mobile;
  return desktop;
}

function AppContent() {
  return (
    <BrowserRouter>
      <MobileChrome />
      <Routes>
        <Route path="/" element={<Landing />} />
        <Route path="/login" element={<Login />} />
        <Route path="/register" element={<Register />} />
        
        {/* Instructor Routes — design paths canonical */}
        <Route path="/instructor/command" element={
          <ProtectedRoute requiredRole="instructor">
            <ModeSwitch mobile={<MobileInstructorCommand />} desktop={<InstructorCommand />} />
          </ProtectedRoute>
        } />
        <Route path="/instructor/dashboard" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorDashboard />
          </ProtectedRoute>
        } />
        <Route path="/instructor/heatmap" element={
          <ProtectedRoute requiredRole="instructor">
            <ModeSwitch mobile={<MobileInstructorCommand />} desktop={<InstructorHeatmap />} />
          </ProtectedRoute>
        } />
        <Route path="/instructor/students" element={
          <ProtectedRoute requiredRole="instructor">
            <ModeSwitch mobile={<MobileInstructorStudents />} desktop={<InstructorStudents />} />
          </ProtectedRoute>
        } />
        <Route path="/instructor/students/:id" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorStudentDetail />
          </ProtectedRoute>
        } />
        <Route path="/instructor/exercises" element={
          <ProtectedRoute requiredRole="instructor">
            <ModeSwitch mobile={<MobileInstructorConcepts />} desktop={<InstructorExercises />} />
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
            <ModeSwitch mobile={<MobileInstructorIntegrity />} desktop={<InstructorIntegrity />} />
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
            <ModeSwitch mobile={<MobileInstructorSections />} desktop={<InstructorSections />} />
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
        <Route path="/instructor/sections/:sectionId/custom-heatmap" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorCustomHeatmap />
          </ProtectedRoute>
        } />
        <Route path="/instructor/sections/:sectionId/custom-tags" element={
          <ProtectedRoute requiredRole="instructor">
            <InstructorCustomTags />
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
            <ModeSwitch mobile={<MobileStudentToday />} desktop={<StudentToday />} />
          </ProtectedRoute>
        } />
        <Route path="/student/sections" element={
          <ProtectedRoute requiredRole="student">
            <ModeSwitch mobile={<MobileStudentSections />} desktop={<StudentSections />} />
          </ProtectedRoute>
        } />
        <Route path="/student/integrity" element={
          <ProtectedRoute requiredRole="student">
            <StudentIntegrityView />
          </ProtectedRoute>
        } />
        <Route path="/student/recommendations" element={
          <ProtectedRoute requiredRole="student">
            <StudentRecommendations />
          </ProtectedRoute>
        } />
        <Route path="/student" element={
          <ProtectedRoute requiredRole="student">
            <StudentDashboard />
          </ProtectedRoute>
        } />
        <Route path="/student/exercises" element={
          <ProtectedRoute requiredRole="student">
            <ModeSwitch mobile={<MobileStudentExercises />} desktop={<StudentExerciseList />} />
          </ProtectedRoute>
        } />
        <Route path="/student/exercises/:exerciseId" element={
          <ProtectedRoute requiredRole="student">
            <ModeSwitch mobile={<MobileStudentExerciseDetail />} desktop={<StudentCodeEditor />} />
          </ProtectedRoute>
        } />
        <Route path="/student/progress" element={
          <ProtectedRoute requiredRole="student">
            <ModeSwitch mobile={<MobileStudentProgress />} desktop={<StudentProgress />} />
          </ProtectedRoute>
        } />

        {/* Design-aligned URL paths (new aliases for design nav parity) */}
        <Route path="/student/dashboard" element={
          <ProtectedRoute requiredRole="student">
            <ModeSwitch mobile={<MobileStudentToday />} desktop={<StudentDashboard />} />
          </ProtectedRoute>
        } />
        <Route path="/student/code-editor" element={
          <ProtectedRoute requiredRole="student">
            <StudentCodeEditor />
          </ProtectedRoute>
        } />
        <Route path="/student/code-editor/:exerciseId" element={
          <ProtectedRoute requiredRole="student">
            <ModeSwitch mobile={<MobileStudentExerciseDetail />} desktop={<StudentCodeEditor />} />
          </ProtectedRoute>
        } />
        <Route path="/student/profile" element={
          <ProtectedRoute requiredRole="student">
            <ModeSwitch mobile={<MobileStudentIntegrity />} desktop={<StudentProfile />} />
          </ProtectedRoute>
        } />

        {/* Admin routes */}
        <Route path="/admin" element={
          <ProtectedRoute requiredRole="admin">
            <ModeSwitch mobile={<MobileAdminOverview />} desktop={<AdminOverview />} />
          </ProtectedRoute>
        } />
        <Route path="/admin/overview" element={
          <ProtectedRoute requiredRole="admin">
            <ModeSwitch mobile={<MobileAdminOverview />} desktop={<AdminOverview />} />
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
            <ModeSwitch mobile={<MobileAdminAudit />} desktop={<AdminAudit />} />
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
