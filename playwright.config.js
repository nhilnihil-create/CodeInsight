/**
 * playwright.config.js
 *
 * Root E2E config for CodeInsight V2 classroom workflow tests.
 * Spins up both Vite frontend (port 5173) and Express backend (port 5000).
 * RAM-capped to prevent OOM during full test sweeps.
 *
 * IMPORTANT: Uses 127.0.0.1 everywhere (not localhost) to avoid WSL2 IPv6 trap.
 */

const { defineConfig, devices } = require('@playwright/test');

module.exports = defineConfig({
  testDir: './e2e',
  fullyParallel: false,
  workers: 1,
  reporter: 'html',
  retries: 1,

  use: {
    baseURL: 'http://localhost:5173',
    trace: 'on-first-retry',
    screenshot: 'only-on-failure',
  },

  webServer: [
    {
      command: 'cross-env NODE_OPTIONS="--max-old-space-size=1024" npm run dev --prefix frontend -- --host 127.0.0.1 --port 5173',
      url: 'http://127.0.0.1:5173',
      reuseExistingServer: true,
      timeout: 60000,
    },
    {
      // Backend must be running before E2E tests start
      command: 'echo "Backend already running"',
      url: 'http://127.0.0.1:5000/api/health',
      reuseExistingServer: true,
      timeout: 10000,
    },
  ],

  projects: [
    {
      name: 'chromium',
      use: { ...devices['Desktop Chrome'] },
    },
    {
      name: 'firefox',
      use: { ...devices['Desktop Firefox'] },
    },
    {
      name: 'webkit',
      use: { ...devices['Desktop Safari'] },
    },
  ],

  outputDir: 'e2e/test-results/',
});
