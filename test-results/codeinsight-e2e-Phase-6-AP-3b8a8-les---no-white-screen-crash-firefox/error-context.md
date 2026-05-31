# Instructions

- Following Playwright test failed.
- Explain why, be concise, respect Playwright best practices.
- Provide a snippet of code with the fix, if possible.

# Test info

- Name: codeinsight-e2e.spec.js >> Phase 6 API Route Fixes >> 1.1: Vite environment variables - no white screen crash
- Location: tests/codeinsight-e2e.spec.js:242:7

# Error details

```
Test timeout of 30000ms exceeded.
```

```
Error: page.waitForLoadState: Test timeout of 30000ms exceeded.
```

# Test source

```ts
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
  183 |   
  184 |   test('Context D: Ana submits with retry and achieves MODERATE CDS', async ({ page }) => {
  185 |     // Login as Ana with token injection
  186 |     await loginWithToken(page, credentials.ana.email, credentials.ana.password, `${BASE_URL}/student/exercises`);
  187 |     
  188 |     // Wait for page load
  189 |     await page.waitForLoadState('networkidle').catch(() => null);
  190 |     
  191 |     // Verify Ana can access exercises
  192 |     const exerciseElements = await page.locator('[data-testid^="exercise-card"]');
  193 |     const isVisible = await exerciseElements.first().isVisible().catch(() => false);
  194 |     expect(isVisible).toBeTruthy();
  195 |     
  196 |     console.log('✅ Context D: Ana exercise interface accessible');
  197 |   });
  198 |   
  199 |   test('Network Validation: No double /api paths or 404s on enrollment', async ({ page }) => {
  200 |     const networkIssues = [];
  201 |     
  202 |     page.on('response', response => {
  203 |       const url = response.url();
  204 |       
  205 |       // Check for double /api
  206 |       if (url.includes('/api/api')) {
  207 |         networkIssues.push(`Double /api path: ${url}`);
  208 |       }
  209 |       
  210 |       // Check for enrollment 404/401
  211 |       if (url.includes('/api/sections') && url.includes('enroll')) {
  212 |         if (response.status() === 404 || response.status() === 401) {
  213 |           networkIssues.push(`Enrollment route error (${response.status()}): ${url}`);
  214 |         }
  215 |       }
  216 |     });
  217 |     
  218 |     // Login as instructor
  219 |     await login(page, credentials.instructor.email, credentials.instructor.password);
  220 |     
  221 |     // Navigate to sections
  222 |     await page.goto(`${BASE_URL}/instructor/sections`);
  223 |     await page.waitForLoadState('networkidle');
  224 |     
  225 |     expect(networkIssues.length).toBe(0);
  226 |     console.log('✅ Network Validation: All API paths valid, no double /api');
  227 |   });
  228 |   
  229 |   test('Database Verification: Enrollments and semester field persisted', async () => {
  230 |     const dbState = await verifyDatabaseState();
  231 |     
  232 |     expect(dbState.enrollmentCount).toBeGreaterThanOrEqual(0);
  233 |     expect(dbState.semesterField).not.toBe('NOT_FOUND');
  234 |     
  235 |     console.log(`✅ Database Verification: ${dbState.enrollmentCount} enrollments, semester='${dbState.semesterField}'`);
  236 |   });
  237 | });
  238 | 
  239 | // Test Suite: Phase 6 API Fixes
  240 | test.describe('Phase 6 API Route Fixes', () => {
  241 |   
  242 |   test('1.1: Vite environment variables - no white screen crash', async ({ page }) => {
  243 |     const errors = [];
  244 |     page.on('console', msg => {
  245 |       if (msg.type() === 'error') {
  246 |         errors.push(msg.text());
  247 |       }
  248 |     });
  249 |     
  250 |     await page.goto(BASE_URL);
> 251 |     await page.waitForLoadState('networkidle');
      |                ^ Error: page.waitForLoadState: Test timeout of 30000ms exceeded.
  252 |     
  253 |     const processRefError = errors.filter(e => e.includes('process is not defined'));
  254 |     expect(processRefError.length).toBe(0);
  255 |     
  256 |     console.log('✅ Test 1.1: Frontend loads without Vite errors');
  257 |   });
  258 |   
  259 |   test('1.2: API base URL - no double /api paths', async ({ page }) => {
  260 |     const apiCalls = [];
  261 |     page.on('request', request => {
  262 |       if (request.url().includes('/api')) {
  263 |         apiCalls.push(request.url());
  264 |       }
  265 |     });
  266 |     
  267 |     await login(page, credentials.instructor.email, credentials.instructor.password);
  268 |     await page.waitForLoadState('networkidle');
  269 |     
  270 |     const doubleApiCalls = apiCalls.filter(url => url.includes('/api/api'));
  271 |     expect(doubleApiCalls.length).toBe(0);
  272 |     
  273 |     console.log(`✅ Test 1.2: All ${apiCalls.length} API calls use single /api path`);
  274 |   });
  275 |   
  276 |   test('1.3: Enrollment endpoint - no 404s or 401s', async ({ page }) => {
  277 |     const enrollmentResponses = [];
  278 |     page.on('response', response => {
  279 |       if (response.url().includes('/enroll')) {
  280 |         enrollmentResponses.push({
  281 |           url: response.url(),
  282 |           status: response.status()
  283 |         });
  284 |       }
  285 |     });
  286 |     
  287 |     await login(page, credentials.instructor.email, credentials.instructor.password);
  288 |     await page.goto(`${BASE_URL}/instructor/sections`);
  289 |     await page.waitForLoadState('networkidle');
  290 |     
  291 |     const errors = enrollmentResponses.filter(r => r.status === 404 || r.status === 401);
  292 |     expect(errors.length).toBe(0);
  293 |     
  294 |     console.log(`✅ Test 1.3: Enrollment endpoint accessible`);
  295 |   });
  296 | });
  297 | 
  298 | // Test Suite: Phase 7 Section Form
  299 | test.describe('Phase 7 Section Form Enhancements', () => {
  300 |   
  301 |   test('2.1: Semester dropdown appears in form', async ({ page }) => {
  302 |     await login(page, credentials.instructor.email, credentials.instructor.password);
  303 |     await page.goto(`${BASE_URL}/instructor/sections`);
  304 |     await page.waitForLoadState('networkidle');
  305 |     
  306 |     // Look for semester field in form
  307 |     const semesterSelect = await page.locator('select[name="semester"]').isVisible().catch(() => false);
  308 |     const semesterInput = await page.locator('input[name="semester"]').isVisible().catch(() => false);
  309 |     
  310 |     expect(semesterSelect || semesterInput).toBeTruthy();
  311 |     
  312 |     console.log('✅ Test 2.1: Semester field visible in section form');
  313 |   });
  314 |   
  315 |   test('2.2: Semester value persists in database', async () => {
  316 |     const dbState = await verifyDatabaseState();
  317 |     expect(dbState.semesterField).toBeTruthy();
  318 |     
  319 |     console.log(`✅ Test 2.2: Semester='${dbState.semesterField}' persisted in database`);
  320 |   });
  321 | });
  322 | 
  323 | export default test;
  324 | 
```