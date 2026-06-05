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
import InstructorCommand from './pages/instructor/Command';
import InstructorIntegrityDetail from './pages/instructor/IntegrityDetail';
import InstructorDeveloper from './pages/instructor/Developer';
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
import MobileAdminOverview from './pages/mobile/admin/Overview.jsx';
import MobileAdminEvaluation from './pages/mobile/admin/Evaluation.jsx';
import MobileAdminAudit from './pages/mobile/admin/Audit.jsx';

function ProtectedRoute({ children, requiredRole, pageTitle }) {
  const { isLoggedIn, user } = useAuth();

  if (!isLoggedIn) return <Navigate to="/login" replace />;
  if (requiredRole && user?.role !== requiredRole) {
    const home = user?.role === 'instructor' ? '/instructor/dashboard' : '/student/dashboard';
    return <Navigate to={home} replace />;
  }
  return <Layout pageTitle={pageTitle}>{children}</Layout>;
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
        
        {/* Instructor Routes — design paths canonical */}
        <Route path="/instructor/command" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Command Center">
            <ModeSwitch mobile={<MobileInstructorCommand />} desktop={<InstructorCommand />} />
          </ProtectedRoute>
        } />
        <Route path="/instructor/dashboard" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Dashboard">
            <InstructorDashboard />
          </ProtectedRoute>
        } />
        <Route path="/instructor/heatmap" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Class Heatmap">
            <ModeSwitch mobile={<MobileInstructorCommand />} desktop={<InstructorHeatmap />} />
          </ProtectedRoute>
        } />
        <Route path="/instructor/students" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Students">
            <ModeSwitch mobile={<MobileInstructorStudents />} desktop={<InstructorStudents />} />
          </ProtectedRoute>
        } />
        <Route path="/instructor/students/:id" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Student Detail">
            <InstructorStudentDetail />
          </ProtectedRoute>
        } />
        <Route path="/instructor/exercises" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Exercises">
            <ModeSwitch mobile={<MobileInstructorConcepts />} desktop={<InstructorExercises />} />
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
            <ModeSwitch mobile={<MobileInstructorIntegrity />} desktop={<InstructorIntegrity />} />
          </ProtectedRoute>
        } />
        <Route path="/instructor/integrity/:id" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Flag Detail">
            <InstructorIntegrityDetail />
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
            <ModeSwitch mobile={<MobileInstructorSections />} desktop={<InstructorSections />} />
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
        <Route path="/student/today" element={
          <ProtectedRoute requiredRole="student" pageTitle="Today's Plan">
            <ModeSwitch mobile={<MobileStudentToday />} desktop={<StudentToday />} />
          </ProtectedRoute>
        } />
        <Route path="/student/sections" element={
          <ProtectedRoute requiredRole="student" pageTitle="My Sections">
            <ModeSwitch mobile={<MobileStudentSections />} desktop={<StudentSections />} />
          </ProtectedRoute>
        } />
        <Route path="/student/integrity" element={
          <ProtectedRoute requiredRole="student" pageTitle="Learning Dashboard">
            <StudentIntegrityView />
          </ProtectedRoute>
        } />
        <Route path="/student/recommendations" element={
          <ProtectedRoute requiredRole="student" pageTitle="Recommendations">
            <StudentRecommendations />
          </ProtectedRoute>
        } />
        <Route path="/student" element={
          <ProtectedRoute requiredRole="student" pageTitle="Dashboard">
            <StudentDashboard />
          </ProtectedRoute>
        } />
        <Route path="/student/exercises" element={
          <ProtectedRoute requiredRole="student" pageTitle="Exercises">
            <ModeSwitch mobile={<MobileStudentExercises />} desktop={<StudentExerciseList />} />
          </ProtectedRoute>
        } />
        <Route path="/student/exercises/:exerciseId" element={
          <ProtectedRoute requiredRole="student" pageTitle="Code Editor">
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
          <ProtectedRoute requiredRole="student" pageTitle="Dashboard">
            <ModeSwitch mobile={<MobileStudentToday />} desktop={<StudentDashboard />} />
          </ProtectedRoute>
        } />
        <Route path="/student/code-editor" element={
          <ProtectedRoute requiredRole="student" pageTitle="Code Editor">
            <StudentCodeEditor />
          </ProtectedRoute>
        } />
        <Route path="/student/code-editor/:exerciseId" element={
          <ProtectedRoute requiredRole="student" pageTitle="Code Editor">
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
          <ProtectedRoute requiredRole="admin" pageTitle="Overview">
            <ModeSwitch mobile={<MobileAdminOverview />} desktop={<AdminOverview />} />
          </ProtectedRoute>
        } />
        <Route path="/admin/overview" element={
          <ProtectedRoute requiredRole="admin" pageTitle="Overview">
            <ModeSwitch mobile={<MobileAdminOverview />} desktop={<AdminOverview />} />
          </ProtectedRoute>
        } />
        <Route path="/admin/users" element={
          <ProtectedRoute requiredRole="admin" pageTitle="Users">
            <AdminUsers />
          </ProtectedRoute>
        } />
        <Route path="/admin/sections" element={
          <ProtectedRoute requiredRole="admin" pageTitle="Sections">
            <AdminSectionsOverview />
          </ProtectedRoute>
        } />
        <Route path="/admin/concepts" element={
          <ProtectedRoute requiredRole="admin" pageTitle="Concepts">
            <AdminConcepts />
          </ProtectedRoute>
        } />
        <Route path="/admin/exercises" element={
          <ProtectedRoute requiredRole="admin" pageTitle="Exercises">
            <AdminExercises />
          </ProtectedRoute>
        } />
        <Route path="/admin/evaluation" element={
          <ProtectedRoute requiredRole="admin" pageTitle="Evaluation">
            <AdminEvaluation />
          </ProtectedRoute>
        } />
        <Route path="/admin/audit" element={
          <ProtectedRoute requiredRole="admin" pageTitle="Audit">
            <ModeSwitch mobile={<MobileAdminAudit />} desktop={<div style={{padding: 24}}>Admin audit view (TODO)</div>} />
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
