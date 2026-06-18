const { defineConfig, devices } = require('@playwright/test');

module.exports = defineConfig({
  testDir: '.',
  testMatch: '*.spec.js',
  fullyParallel: false,
  workers: 1,
  reporter: 'line',
  retries: 0,
  timeout: 300000,

  use: {
    baseURL: 'http://localhost:5173',
    trace: 'off',
    screenshot: 'off',
    headless: false,
  },

  webServer: {
    command: 'echo "Services already running"',
    url: 'http://localhost:5000/api/health',
    reuseExistingServer: true,
    timeout: 10000,
  },

  projects: [
    {
      name: 'chromium',
      use: { ...devices['Desktop Chrome'], headless: false },
    },
  ],
});
