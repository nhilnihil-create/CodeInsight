import { defineConfig } from 'vite'
import react from '@vitejs/plugin-react'
import tailwindcss from '@tailwindcss/vite'
import path from 'path'

export default defineConfig({
  plugins: [
    react(),
    tailwindcss(),
  ],
  resolve: {
    alias: {
      '@': path.resolve(__dirname, './src'),
    },
  },
  build: {
    rollupOptions: {
      output: {
        manualChunks: {
          'vendor-react': ['react', 'react-dom', 'react-router-dom'],
          'vendor-ui': ['lucide-react', 'recharts'],
          'vendor-query': ['@tanstack/react-query'],
          'vendor-utils': ['clsx', 'tailwind-merge'],
          'pages-instructor': [
            './src/pages/instructor/Dashboard.jsx',
            './src/pages/instructor/Heatmap.jsx',
            './src/pages/instructor/Reports.jsx',
            './src/pages/instructor/ExerciseWorkspace.jsx',
            './src/pages/instructor/Exercises.jsx',
            './src/pages/instructor/Integrity.jsx',
            './src/pages/instructor/Students.jsx',
            './src/pages/instructor/SectionDetail.jsx',
            './src/pages/instructor/StudentDetail.jsx',
            './src/pages/instructor/Developer.jsx',
            './src/pages/instructor/StructureViolations.jsx',
            './src/pages/instructor/AcademicIntegrityFlags.jsx',
            './src/pages/instructor/ClassMicroConceptReport.jsx',
          ],
          'pages-student': [
            './src/pages/student/Dashboard.jsx',
            './src/pages/student/Progress.jsx',
            './src/pages/student/Exercises.jsx',
            './src/pages/student/CodeEditor.jsx',
            './src/pages/student/Profile.jsx',
            './src/pages/student/Integrity.jsx',
            './src/pages/student/Recommendations.jsx',
            './src/pages/student/Today.jsx',
            './src/pages/student/Sections.jsx',
          ],
          'pages-admin': [
            './src/pages/admin/Users.jsx',
            './src/pages/admin/Overview.jsx',
            './src/pages/admin/Sections.jsx',
            './src/pages/admin/Exercises.jsx',
            './src/pages/admin/Concepts.jsx',
            './src/pages/admin/Evaluation.jsx',
          ],

        },
      },
    },
    chunkSizeWarningLimit: 1000,
  },
  server: {
    proxy: {
      '/api': {
        target: 'http://localhost:5000',
        changeOrigin: true
      }
    }
  }
})
