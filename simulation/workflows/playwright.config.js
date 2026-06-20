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
    command: 'node -e "setInterval(()=>{},86400000)"',
    url: 'http://127.0.0.1:5000/api/health',
    reuseExistingServer: true,
    timeout: 10000,
    ignoreHTTPSErrors: true,
  },

  projects: [
    {
      name: 'chromium',
      use: { ...devices['Desktop Chrome'], headless: false },
    },
  ],
});
