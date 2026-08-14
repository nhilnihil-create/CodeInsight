// frontend/playwright.config.js
// Mobile triage E2E config. Spins up Vite dev server on 127.0.0.1:5173 and runs
// the mobile-triage spec under iPhone 12 viewport (375x812).

import { defineConfig, devices } from '@playwright/test';

export default defineConfig({
  testDir: './tests/e2e',
  timeout: 120_000,
  use: {
    baseURL: 'http://localhost:5173',
    trace: 'retain-on-failure',
    navigationTimeout: 90_000,
  },
  projects: [
    // Mobile viewport emulation. Chromium-based Pixel 5 (not WebKit) because
    // Playwright's WebKit builds on Windows are experimental and tap/click
    // stabilization is unreliable; the mobile triage specs force their own
    // 375x812 viewport regardless of the engine.
    { name: 'mobile-chromium', use: { ...devices['Pixel 5'] } },
    { name: 'desktop-chromium', use: { ...devices['Desktop Chrome'] } },
  ],
  webServer: {
    command: 'npm run dev -- --host 127.0.0.1 --port 5173',
    url: 'http://127.0.0.1:5173',
    reuseExistingServer: true,
    timeout: 60_000,
  },
});
