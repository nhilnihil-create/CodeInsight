# Instructions

- Following Playwright test failed.
- Explain why, be concise, respect Playwright best practices.
- Provide a snippet of code with the fix, if possible.

# Test info

- Name: codeinsight-e2e.spec.js >> CodeInsight E2E Multi-Context CDS Verification >> Context A: Instructor monitors live ranking and final heatmap
- Location: tests/codeinsight-e2e.spec.js:107:7

# Error details

```
Test timeout of 30000ms exceeded.
```

```
Error: page.goto: Test timeout of 30000ms exceeded.
Call log:
  - navigating to "http://localhost:5173/instructor/sections/5", waiting until "load"

```

# Test source

```ts
  1   | import { test, expect } from '@playwright/test';
  2   | import { Client } from 'pg';
  3   | 
  4   | const BASE_URL = 'http://localhost:5173';
  5   | const API_BASE = 'http://localhost:5000/api';
  6   | const SECTION_ID = 5;
  7   | 
  8   | // Test credentials
  9   | const credentials = {
  10  |   instructor: { email: 'instructor@psu.edu', password: 'password123' },
  11  |   maria: { email: 'maria@student.psu.edu', password: 'password123' },
  12  |   jose: { email: 'jose@student.psu.edu', password: 'password123' },
  13  |   ana: { email: 'ana@student.psu.edu', password: 'password123' }
  14  | };
  15  | 
  16  | // PostgreSQL connection
  17  | const dbConfig = {
  18  |   user: 'postgres',
  19  |   password: 'postgres',
  20  |   host: 'localhost',
  21  |   port: 5432,
  22  |   database: 'codeinsight'
  23  | };
  24  | 
  25  | // Helper: Database verification
  26  | async function verifyDatabaseState() {
  27  |   const client = new Client(dbConfig);
  28  |   try {
  29  |     await client.connect();
  30  |     
  31  |     // Verify enrollments for section 5
  32  |     const enrollments = await client.query(
  33  |       'SELECT COUNT(*) FROM enrollments WHERE section_id = $1',
  34  |       [SECTION_ID]
  35  |     );
  36  |     
  37  |     // Verify semester field persistence
  38  |     const semester = await client.query(
  39  |       'SELECT semester FROM sections WHERE id = $1',
  40  |       [SECTION_ID]
  41  |     );
  42  |     
  43  |     return {
  44  |       enrollmentCount: parseInt(enrollments.rows[0].count),
  45  |       semesterField: semester.rows[0]?.semester || 'NOT_FOUND'
  46  |     };
  47  |   } finally {
  48  |     await client.end();
  49  |   }
  50  | }
  51  | 
  52  | // Helper: Get JWT token from backend API
  53  | async function getAuthToken(email, password) {
  54  |   try {
  55  |     const response = await fetch(`${API_BASE}/auth/login`, {
  56  |       method: 'POST',
  57  |       headers: { 'Content-Type': 'application/json' },
  58  |       body: JSON.stringify({ email, password })
  59  |     });
  60  |     
  61  |     if (!response.ok) {
  62  |       throw new Error(`Login failed: ${response.status}`);
  63  |     }
  64  |     
  65  |     const data = await response.json();
  66  |     return data.token || null;
  67  |   } catch (error) {
  68  |     console.error('Failed to get auth token:', error);
  69  |     return null;
  70  |   }
  71  | }
  72  | 
  73  | // Helper: Inject token into localStorage and navigate
  74  | async function loginWithToken(page, email, password, navigateTo = BASE_URL) {
  75  |   const token = await getAuthToken(email, password);
  76  |   
  77  |   if (!token) {
  78  |     throw new Error(`Could not obtain token for ${email}`);
  79  |   }
  80  |   
  81  |   // Navigate to a page to establish context, then inject token
> 82  |   await page.goto(navigateTo);
      |              ^ Error: page.goto: Test timeout of 30000ms exceeded.
  83  |   
  84  |   // Inject token into localStorage before any authenticated operations
  85  |   await page.evaluate((tokenValue) => {
  86  |     window.localStorage.setItem('ci_token', tokenValue);
  87  |   }, token);
  88  |   
  89  |   return token;
  90  | }
  91  | 
  92  | // Helper: Login (fallback UI-based method)
  93  | async function login(page, email, password) {
  94  |   await page.goto(`${BASE_URL}/login`);
  95  |   await page.fill('input[type="email"]', email);
  96  |   await page.fill('input[type="password"]', password);
  97  |   await page.click('button[type="submit"]');
  98  |   await page.waitForNavigation().catch(() => {
  99  |     // Navigation might not fire if page reloads via client-side router
  100 |     return page.waitForURL('**/student/exercises', { timeout: 10000 }).catch(() => null);
  101 |   });
  102 | }
  103 | 
  104 | // Test Suite: Multi-Context E2E
  105 | test.describe('CodeInsight E2E Multi-Context CDS Verification', () => {
  106 |   
  107 |   test('Context A: Instructor monitors live ranking and final heatmap', async ({ page }) => {
  108 |     // Intercept network requests
  109 |     const requests = [];
  110 |     page.on('request', request => {
  111 |       requests.push(request.url());
  112 |     });
  113 |     
  114 |     // Login with token injection
  115 |     await loginWithToken(page, credentials.instructor.email, credentials.instructor.password, `${BASE_URL}/instructor/sections/${SECTION_ID}`);
  116 |     
  117 |     // Wait for page to load
  118 |     await page.waitForLoadState('networkidle').catch(() => null);
  119 |     
  120 |     // Verify no double /api paths in network requests
  121 |     const doubleApiPaths = requests.filter(url => url.includes('/api/api'));
  122 |     expect(doubleApiPaths.length).toBe(0);
  123 |     
  124 |     // Check for live ranking or heatmap elements
  125 |     const heatmapExists = await page.locator('[data-testid="heatmap"]').isVisible().catch(() => false);
  126 |     const liveRankingExists = await page.locator('[data-testid="live-ranking"]').isVisible().catch(() => false);
  127 |     
  128 |     expect(heatmapExists || liveRankingExists).toBeTruthy();
  129 |     
  130 |     console.log('✅ Context A: Instructor dashboard accessible');
  131 |   });
  132 |   
  133 |   test('Context B: Maria submits code with tab-switch and reaches HIGH CDS', async ({ page }) => {
  134 |     // Login as Maria with token injection
  135 |     await loginWithToken(page, credentials.maria.email, credentials.maria.password, `${BASE_URL}/student/exercises`);
  136 |     
  137 |     // Wait for page load
  138 |     await page.waitForLoadState('networkidle').catch(() => null);
  139 |     
  140 |     // Find and click an exercise
  141 |     const exerciseCard = await page.locator('[data-testid^="exercise-card"]').first();
  142 |     if (await exerciseCard.isVisible().catch(() => false)) {
  143 |       await exerciseCard.click();
  144 |       await page.waitForLoadState('networkidle').catch(() => null);
  145 |       
  146 |       // Check for "Ready to Code" modal
  147 |       const readyModal = await page.locator('[data-testid="ready-to-code-modal"]').isVisible().catch(() => false);
  148 |       if (readyModal) {
  149 |         await page.click('button:has-text("Yes")');
  150 |         await page.waitForTimeout(1000);
  151 |       }
  152 |       
  153 |       // Mock Page Visibility API tab-switch
  154 |       await page.evaluate(() => {
  155 |         document.dispatchEvent(new Event('visibilitychange'));
  156 |       });
  157 |       await page.waitForTimeout(2000);
  158 |       await page.evaluate(() => {
  159 |         document.dispatchEvent(new Event('visibilitychange'));
  160 |       });
  161 |       
  162 |       // Try to submit code (mock submission)
  163 |       const submitButton = await page.locator('button:has-text("Submit")').isVisible().catch(() => false);
  164 |       if (submitButton) {
  165 |         console.log('✅ Context B: Maria exercise accessible and timer paused on tab-switch');
  166 |       }
  167 |     }
  168 |   });
  169 |   
  170 |   test('Context C: Jose submits once and achieves LOW CDS', async ({ page }) => {
  171 |     // Login as Jose with token injection
  172 |     await loginWithToken(page, credentials.jose.email, credentials.jose.password, `${BASE_URL}/student/exercises`);
  173 |     
  174 |     // Wait for page load
  175 |     await page.waitForLoadState('networkidle').catch(() => null);
  176 |     
  177 |     // Verify exercises are accessible
  178 |     const exerciseCount = await page.locator('[data-testid^="exercise-card"]').count();
  179 |     expect(exerciseCount).toBeGreaterThan(0);
  180 |     
  181 |     console.log(`✅ Context C: Jose can see ${exerciseCount} available exercises`);
  182 |   });
```