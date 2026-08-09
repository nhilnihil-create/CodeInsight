// E2E Tests for Join Code Feature
// Tests complete flow: instructor creates section → copies code → student joins

import { test, expect } from '@playwright/test';

// Test credentials (should be in .env.test or similar)
const INSTRUCTOR_EMAIL = 'instructor@psu.edu';
const STUDENT_EMAIL = 'maria@student.psu.edu';
const TEST_PASSWORD = 'password123';

test.describe('Join Code Feature - E2E', () => {
  
  test.describe('Instructor Flow', () => {
    
    test('instructor can see join code in sections list', async ({ page }) => {
      // Login as instructor
      await page.goto('/login');
      await page.getByLabel('EMAIL').fill( INSTRUCTOR_EMAIL);
      await page.getByLabel('PASSWORD').fill(TEST_PASSWORD);
      await page.getByRole('button', { name: 'Sign In' }).click();
      
      // Wait for redirect to dashboard
      await page.waitForURL('/instructor/dashboard');
      
      // Navigate to sections
      await page.goto('/instructor/sections');
      
      // Wait for sections to load
      await page.waitForSelector('text=/[A-Z0-9]{3}-[A-Z0-9]{3}/');
      
      // Verify join code is visible
      const codeElement = await page.locator('text=/[A-Z0-9]{3}-[A-Z0-9]{3}/').first();
      expect(await codeElement.isVisible()).toBeTruthy();
    });

    test('instructor can copy join code from sections list', async ({ page }) => {
      // Grant clipboard permissions
      await page.context().grantPermissions(['clipboard-read', 'clipboard-write']);
      
      // Login as instructor
      await page.goto('/login');
      await page.getByLabel('EMAIL').fill( INSTRUCTOR_EMAIL);
      await page.getByLabel('PASSWORD').fill(TEST_PASSWORD);
      await page.getByRole('button', { name: 'Sign In' }).click();
      
      await page.waitForURL('/instructor/dashboard');
      
      // Navigate to sections
      await page.goto('/instructor/sections');
      
      // Wait for sections to load
      await page.waitForSelector('button[aria-label^="Copy join code"]');
      
      // Click copy button
      const copyButton = page.locator('button[aria-label^="Copy join code"]').first();
      await copyButton.click();
      
      // Verify toast appears
      await expect(page.locator('text=Join code copied to clipboard')).toBeVisible();
    });

    test('instructor can copy join code from section detail', async ({ page }) => {
      await page.context().grantPermissions(['clipboard-read', 'clipboard-write']);
      
      // Login as instructor
      await page.goto('/login');
      await page.getByLabel('EMAIL').fill( INSTRUCTOR_EMAIL);
      await page.getByLabel('PASSWORD').fill(TEST_PASSWORD);
      await page.getByRole('button', { name: 'Sign In' }).click();
      
      await page.waitForURL('/instructor/dashboard');
      
      // Navigate to sections and click first one
      await page.goto('/instructor/sections');
      await page.waitForSelector('text=/[A-Z0-9]{3}-[A-Z0-9]{3}/');
      
      // Click on first section to go to detail
      const sectionLink = page.locator('ul[aria-label="Decision list"] li[role="button"]').first();
      await sectionLink.click();
      
      // Wait for section detail to load
      await page.waitForSelector('text=/[A-Z0-9]{3}-[A-Z0-9]{3}/');
      
      // Click "More actions" dropdown
      await page.click('button[aria-label="More actions"]');
      
      // Click "Copy join code"
      await page.click('text=Copy join code');
      
      // Verify toast
      await expect(page.locator('text=Join code copied to clipboard')).toBeVisible();
    });

    test('instructor can rotate join code', async ({ page }) => {
      // Login as instructor
      await page.goto('/login');
      await page.getByLabel('EMAIL').fill( INSTRUCTOR_EMAIL);
      await page.getByLabel('PASSWORD').fill(TEST_PASSWORD);
      await page.getByRole('button', { name: 'Sign In' }).click();
      
      await page.waitForURL('/instructor/dashboard');
      
      // Navigate to sections and click first one
      await page.goto('/instructor/sections');
      await page.waitForSelector('text=/[A-Z0-9]{3}-[A-Z0-9]{3}/');
      
      // Get current code
      const oldCode = await page.locator('text=/[A-Z0-9]{3}-[A-Z0-9]{3}/').first().textContent();
      
      // Click on first section
      const sectionLink = page.locator('ul[aria-label="Decision list"] li[role="button"]').first();
      await sectionLink.click();
      
      // Wait for section detail
      await page.waitForSelector('text=/[A-Z0-9]{3}-[A-Z0-9]{3}/');
      
      // Click "More actions" dropdown
      await page.click('button[aria-label="More actions"]');
      
      // Click "Rotate join code"
      await page.click('text=Rotate join code');
      
      // Verify toast with new code
      await expect(page.locator('text=New join code:')).toBeVisible();
      
      // Verify new code is different (page should refresh)
      await page.waitForTimeout(1000);
      const newCode = await page.locator('text=/[A-Z0-9]{3}-[A-Z0-9]{3}/').first().textContent();
      expect(newCode).not.toBe(oldCode);
    });
  });

  test.describe('Student Flow', () => {
    
    test('student can join section with valid code', async ({ page }) => {
      // First, create a fresh section to get a valid join code
      await page.goto('/login');
      await page.getByLabel('EMAIL').fill(INSTRUCTOR_EMAIL);
      await page.getByLabel('PASSWORD').fill(TEST_PASSWORD);
      await page.getByRole('button', { name: 'Sign In' }).click();
      
      await page.waitForURL('/instructor/dashboard');
      await page.goto('/instructor/sections');

      const sectionName = `E2E Join ${Date.now()}`;
      await page.click('button:has-text("New Section")');
      await page.fill('input[id="create-name"]', sectionName);
      await page.fill('input[id="create-course"]', 'E2E101');
      await page.click('button:has-text("Create Section")');
      await page.waitForSelector(`text=${sectionName}`);

      const row = page.locator('ul[aria-label="Decision list"] li[role="button"]').filter({ hasText: sectionName });
      const copyBtn = row.locator('button[aria-label^="Copy join code"]');
      await expect(copyBtn).toBeVisible();
      const validCode = (await copyBtn.getAttribute('aria-label')).replace('Copy join code ', '').trim();
      
      // Logout instructor
      await page.goto('/api/auth/logout');
      
      // Login as student
      await page.goto('/login');
      await page.getByLabel('EMAIL').fill( STUDENT_EMAIL);
      await page.getByLabel('PASSWORD').fill(TEST_PASSWORD);
      await page.getByRole('button', { name: 'Sign In' }).click();
      
      await page.waitForURL('/student/dashboard');
      
      // Navigate to sections
      await page.goto('/student/sections');
      
      // Wait for join form
      await page.waitForSelector('input[placeholder*="K7P"]');
      
      // Enter code
      await page.fill('input[placeholder*="K7P"]', validCode);
      
      // Click join
      await page.click('button:has-text("Join")');
      
      // Verify success toast
      await expect(page.locator('text=Successfully joined the section!')).toBeVisible();
    });

    test('student sees error for invalid code', async ({ page }) => {
      // Login as student
      await page.goto('/login');
      await page.getByLabel('EMAIL').fill( STUDENT_EMAIL);
      await page.getByLabel('PASSWORD').fill(TEST_PASSWORD);
      await page.getByRole('button', { name: 'Sign In' }).click();
      
      await page.waitForURL('/student/dashboard');
      
      // Navigate to sections
      await page.goto('/student/sections');
      await page.waitForSelector('input[placeholder*="K7P"]');
      
      // Enter invalid code
      await page.fill('input[placeholder*="K7P"]', 'INVALID');
      
      // Click join
      await page.click('button:has-text("Join")');
      
      // Verify error toast
      await expect(page.locator('text=Invalid join code').first()).toBeVisible();
    });

    test('student sees error for already enrolled', async ({ page }) => {
      // First, create a fresh section to get a valid join code
      await page.goto('/login');
      await page.getByLabel('EMAIL').fill(INSTRUCTOR_EMAIL);
      await page.getByLabel('PASSWORD').fill(TEST_PASSWORD);
      await page.getByRole('button', { name: 'Sign In' }).click();
      
      await page.waitForURL('/instructor/dashboard');
      await page.goto('/instructor/sections');

      const sectionName = `E2E Join ${Date.now()}`;
      await page.click('button:has-text("New Section")');
      await page.fill('input[id="create-name"]', sectionName);
      await page.fill('input[id="create-course"]', 'E2E101');
      await page.click('button:has-text("Create Section")');
      await page.waitForSelector(`text=${sectionName}`);

      const row = page.locator('ul[aria-label="Decision list"] li[role="button"]').filter({ hasText: sectionName });
      const copyBtn = row.locator('button[aria-label^="Copy join code"]');
      await expect(copyBtn).toBeVisible();
      const validCode = (await copyBtn.getAttribute('aria-label')).replace('Copy join code ', '').trim();
      
      // Logout and login as student
      await page.goto('/api/auth/logout');
      await page.goto('/login');
      await page.getByLabel('EMAIL').fill( STUDENT_EMAIL);
      await page.getByLabel('PASSWORD').fill(TEST_PASSWORD);
      await page.getByRole('button', { name: 'Sign In' }).click();
      
      await page.waitForURL('/student/dashboard');
      
      // Join section
      await page.goto('/student/sections');
      await page.waitForSelector('input[placeholder*="K7P"]');
      await page.fill('input[placeholder*="K7P"]', validCode);
      await page.click('button:has-text("Join")');
      
      // Wait for success
      await expect(page.locator('text=Successfully joined the section!')).toBeVisible();
      
      // Try to join again
      await page.fill('input[placeholder*="K7P"]', validCode);
      await page.click('button:has-text("Join")');
      
      // Verify already enrolled error
      await expect(page.locator('text=You are already enrolled in this section.').first()).toBeVisible();
    });

    test('code input auto-formats to uppercase with hyphen', async ({ page }) => {
      // Login as student
      await page.goto('/login');
      await page.getByLabel('EMAIL').fill( STUDENT_EMAIL);
      await page.getByLabel('PASSWORD').fill(TEST_PASSWORD);
      await page.getByRole('button', { name: 'Sign In' }).click();
      
      await page.waitForURL('/student/dashboard');
      
      // Navigate to sections
      await page.goto('/student/sections');
      await page.waitForSelector('input[placeholder*="K7P"]');
      
      const input = page.locator('input[placeholder*="K7P"]');
      
      // Type lowercase without hyphen
      await input.fill('abc123');
      
      // Verify it's formatted
      expect(await input.inputValue()).toBe('ABC-123');
    });

    test('join button disabled until code is 7 characters', async ({ page }) => {
      // Login as student
      await page.goto('/login');
      await page.getByLabel('EMAIL').fill( STUDENT_EMAIL);
      await page.getByLabel('PASSWORD').fill(TEST_PASSWORD);
      await page.getByRole('button', { name: 'Sign In' }).click();
      
      await page.waitForURL('/student/dashboard');
      
      // Navigate to sections
      await page.goto('/student/sections');
      await page.waitForSelector('input[placeholder*="K7P"]');
      
      const input = page.locator('input[placeholder*="K7P"]');
      const button = page.locator('button:has-text("Join")');
      
      // Button should be disabled initially
      expect(await button.isDisabled()).toBeTruthy();
      
      // Type partial code
      await input.fill('ABC');
      expect(await button.isDisabled()).toBeTruthy();
      
      // Type full code
      await input.fill('ABC-123');
      expect(await button.isDisabled()).toBeFalsy();
    });
  });

  test.describe('Full Flow', () => {
    
    test('complete flow: create section → copy code → student joins', async ({ page }) => {
      // === PART 1: Instructor creates section ===
      await page.goto('/login');
      await page.getByLabel('EMAIL').fill( INSTRUCTOR_EMAIL);
      await page.getByLabel('PASSWORD').fill(TEST_PASSWORD);
      await page.getByRole('button', { name: 'Sign In' }).click();
      
      await page.waitForURL('/instructor/dashboard');
      
      // Go to sections
      await page.goto('/instructor/sections');
      
      // Create a fresh section with a unique name — the old constant name collided with
      // stale sections persisted in the DB from prior runs
      const sectionName = `E2E Full ${Date.now()}`;
      await page.click('button:has-text("New Section")');
      
      // Fill form
      await page.fill('input[id="create-name"]', sectionName);
      await page.fill('input[id="create-course"]', 'E2E101');
      
      // Submit
      await page.click('button:has-text("Create Section")');
      
      // Wait for section to appear
      await page.waitForSelector(`text=${sectionName}`);
      
      // Get the new section's code from the row filtered by the unique name — the old
      // regex grabbed the first DOM match, which could be a stale section from a prior run
      const row = page.locator('ul[aria-label="Decision list"] li[role="button"]').filter({ hasText: sectionName });
      const copyBtn = row.locator('button[aria-label^="Copy join code"]');
      await expect(copyBtn).toBeVisible();
      const joinCode = (await copyBtn.getAttribute('aria-label')).replace('Copy join code ', '').trim();
      
      // === PART 2: Student joins with code ===
      
      // Logout
      await page.goto('/api/auth/logout');
      
      // Login as student
      await page.goto('/login');
      await page.getByLabel('EMAIL').fill( STUDENT_EMAIL);
      await page.getByLabel('PASSWORD').fill(TEST_PASSWORD);
      await page.getByRole('button', { name: 'Sign In' }).click();
      
      await page.waitForURL('/student/dashboard');
      
      // Go to sections
      await page.goto('/student/sections');
      await page.waitForSelector('input[placeholder*="K7P"]');
      
      // Enter code
      await page.fill('input[placeholder*="K7P"]', joinCode);
      
      // Join
      await page.click('button:has-text("Join")');
      
      // Verify success
      await expect(page.locator('text=Successfully joined the section!')).toBeVisible();
      
      // Verify section appears in student's list. The student page renders enrolled
      // sections as Cards with an <h3>{section.name}</h3> (verified in
      // frontend/src/pages/student/Sections.jsx) — use the unique name with .first()
      // to guard against any duplicate text on the page.
      await expect(page.getByText(sectionName).first()).toBeVisible();
    });
  });
});
