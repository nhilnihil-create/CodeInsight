// frontend/vitest.config.js
import { defineConfig } from 'vitest/config';
import react from '@vitejs/plugin-react';

export default defineConfig({
  plugins: [react()],
  test: {
    environment: 'jsdom',
    globals: true,
    setupFiles: ['./src/test/setup.js'],
    // Exclude Playwright E2E specs — those run via `playwright test`, not vitest.
    // Without this, vitest tries to import them and chokes on `test.use()`.
    exclude: ['**/node_modules/**', '**/dist/**', '**/.{idea,git,cache,output}/**', 'tests/e2e/**'],
  },
});
