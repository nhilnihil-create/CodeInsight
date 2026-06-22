import { defineConfig } from 'vite'
import react from '@vitejs/plugin-react'
import tailwindcss from '@tailwindcss/vite'
import { VitePWA } from 'vite-plugin-pwa'
import path from 'path'

export default defineConfig({
  plugins: [
    react(),
    tailwindcss(),
    VitePWA({
      registerType: 'autoUpdate',
      includeAssets: ['icon.svg'],
      manifest: {
        name: 'CodeInsight',
        short_name: 'CodeInsight',
        description: 'Programming education analytics and integrity platform',
        theme_color: '#0c1220',
        background_color: '#0c1220',
        display: 'standalone',
        orientation: 'portrait-primary',
        start_url: '/',
        scope: '/',
        icons: [
          {
            src: '/icon.svg',
            sizes: 'any',
            type: 'image/svg+xml',
            purpose: 'any',
          },
        ],
      },
      workbox: {
        globPatterns: ['**/*.{js,css,html,svg,png,woff2}'],
        runtimeCaching: [
          {
            urlPattern: /^\/api\/.*/i,
            handler: 'NetworkFirst',
            options: {
              cacheName: 'api-cache',
              expiration: {
                maxEntries: 100,
                maxAgeSeconds: 60 * 60 * 24,
              },
              networkTimeoutSeconds: 10,
            },
          },
        ],
      },
    }),
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
    host: '0.0.0.0',
    proxy: {
      '/api': {
        target: 'http://localhost:5000',
        changeOrigin: true
      }
    }
  }
})
