# Instructions

- Following Playwright test failed.
- Explain why, be concise, respect Playwright best practices.
- Provide a snippet of code with the fix, if possible.

# Test info

- Name: codeinsight-e2e.spec.js >> Phase 7 Section Form Enhancements >> 2.1: Semester dropdown appears in form
- Location: tests/codeinsight-e2e.spec.js:301:7

# Error details

```
Error: expect(received).toBeTruthy()

Received: false
```

# Page snapshot

```yaml
- generic [ref=e2]:
  - generic [ref=e3]:
    - generic [ref=e4]:
      - generic [ref=e5]:
        - generic [ref=e6]: CodeInsight
        - generic [ref=e7]: Instructor
      - button "‹" [ref=e8] [cursor=pointer]
    - navigation [ref=e9]:
      - link "📊 Dashboard" [ref=e10]:
        - /url: /instructor
        - generic [ref=e11]: 📊
        - text: Dashboard
      - link "📋 My Sections" [ref=e12]:
        - /url: /instructor/sections
        - generic [ref=e13]: 📋
        - text: My Sections
      - link "✎ Create Exercise" [ref=e14]:
        - /url: /instructor/create-exercise
        - generic [ref=e15]: ✎
        - text: Create Exercise
      - link "🔔 Alerts" [ref=e16]:
        - /url: /instructor/alerts
        - generic [ref=e17]: 🔔
        - text: Alerts
      - link "⚙️ Developer" [ref=e18]:
        - /url: /instructor/developer
        - generic [ref=e19]: ⚙️
        - text: Developer
    - generic [ref=e20]:
      - generic [ref=e21]:
        - generic [ref=e22]: JD
        - generic [ref=e23]:
          - generic [ref=e24]: Juan Dela Cruz
          - generic [ref=e25]: instructor@psu.edu
      - button "Logout" [ref=e26] [cursor=pointer]
  - main [ref=e27]:
    - generic [ref=e28]:
      - generic [ref=e29]:
        - generic [ref=e30]:
          - generic [ref=e31]: My Sections
          - generic [ref=e32]: AY 2025–2026 · 5 active sections · 0001401 total students
        - button "+ New Section" [ref=e33] [cursor=pointer]
      - generic [ref=e34]:
        - 'link "ss cc 2025 - 2026 · Sem 2 0 Students 0 Concepts 0 Alerts Class Difficulty Avg CDS: - 0 exercises assigned ✓ All on track" [ref=e35]':
          - /url: /instructor/sections/7
          - generic [ref=e36] [cursor=pointer]:
            - generic [ref=e38]:
              - generic [ref=e39]: ss
              - generic [ref=e40]: cc
            - generic [ref=e41]:
              - generic [ref=e42]: 2025 - 2026 · Sem 2
              - generic [ref=e43]:
                - generic [ref=e44]:
                  - generic [ref=e45]: "0"
                  - generic [ref=e46]: Students
                - generic [ref=e48]:
                  - generic [ref=e49]: "0"
                  - generic [ref=e50]: Concepts
                - generic [ref=e52]:
                  - generic [ref=e53]: "0"
                  - generic [ref=e54]: Alerts
              - generic [ref=e56]:
                - generic [ref=e57]: Class Difficulty
                - generic [ref=e58]: "Avg CDS: -"
              - generic [ref=e61]:
                - generic [ref=e62]: 0 exercises assigned
                - generic [ref=e63]: ✓ All on track
        - 'link "CC203 BIST - 4H 2026 - 2027 · Sem 1 0 Students 0 Concepts 0 Alerts Class Difficulty Avg CDS: - 0 exercises assigned ✓ All on track" [ref=e64]':
          - /url: /instructor/sections/6
          - generic [ref=e65] [cursor=pointer]:
            - generic [ref=e67]:
              - generic [ref=e68]: CC203
              - generic [ref=e69]: BIST - 4H
            - generic [ref=e70]:
              - generic [ref=e71]: 2026 - 2027 · Sem 1
              - generic [ref=e72]:
                - generic [ref=e73]:
                  - generic [ref=e74]: "0"
                  - generic [ref=e75]: Students
                - generic [ref=e77]:
                  - generic [ref=e78]: "0"
                  - generic [ref=e79]: Concepts
                - generic [ref=e81]:
                  - generic [ref=e82]: "0"
                  - generic [ref=e83]: Alerts
              - generic [ref=e85]:
                - generic [ref=e86]: Class Difficulty
                - generic [ref=e87]: "Avg CDS: -"
              - generic [ref=e90]:
                - generic [ref=e91]: 0 exercises assigned
                - generic [ref=e92]: ✓ All on track
        - 'link "CS102 BSCS - 1A 2025 - 2026 · Sem 1 1 Students 0 Concepts 0 Alerts Class Difficulty Avg CDS: - 0 exercises assigned ✓ All on track" [ref=e93]':
          - /url: /instructor/sections/5
          - generic [ref=e94] [cursor=pointer]:
            - generic [ref=e96]:
              - generic [ref=e97]: CS102
              - generic [ref=e98]: BSCS - 1A
            - generic [ref=e99]:
              - generic [ref=e100]: 2025 - 2026 · Sem 1
              - generic [ref=e101]:
                - generic [ref=e102]:
                  - generic [ref=e103]: "1"
                  - generic [ref=e104]: Students
                - generic [ref=e106]:
                  - generic [ref=e107]: "0"
                  - generic [ref=e108]: Concepts
                - generic [ref=e110]:
                  - generic [ref=e111]: "0"
                  - generic [ref=e112]: Alerts
              - generic [ref=e114]:
                - generic [ref=e115]: Class Difficulty
                - generic [ref=e116]: "Avg CDS: -"
              - generic [ref=e119]:
                - generic [ref=e120]: 0 exercises assigned
                - generic [ref=e121]: ✓ All on track
        - 'link "CS101 BSIT-3H-E2E AY-2026 · Sem 1 40 Students 1 Concepts 7 Alerts Class Difficulty Avg CDS: 0.47 1 exercises assigned ⚠ 7 need intervention" [ref=e122]':
          - /url: /instructor/sections/4
          - generic [ref=e123] [cursor=pointer]:
            - generic [ref=e125]:
              - generic [ref=e126]: CS101
              - generic [ref=e127]: BSIT-3H-E2E
            - generic [ref=e128]:
              - generic [ref=e129]: AY-2026 · Sem 1
              - generic [ref=e130]:
                - generic [ref=e131]:
                  - generic [ref=e132]: "40"
                  - generic [ref=e133]: Students
                - generic [ref=e135]:
                  - generic [ref=e136]: "1"
                  - generic [ref=e137]: Concepts
                - generic [ref=e139]:
                  - generic [ref=e140]: "7"
                  - generic [ref=e141]: Alerts
              - generic [ref=e143]:
                - generic [ref=e144]: Class Difficulty
                - generic [ref=e145]: "Avg CDS: 0.47"
              - generic [ref=e150]:
                - generic [ref=e151]: 1 exercises assigned
                - generic [ref=e152]: ⚠ 7 need intervention
        - 'link "ITELEC 4 BSIT - 3H 2025-2026 · Sem 1 1 Students 1 Concepts 1 Alerts Class Difficulty Avg CDS: - 1 exercises assigned ⚠ 1 need intervention" [ref=e153]':
          - /url: /instructor/sections/3
          - generic [ref=e154] [cursor=pointer]:
            - generic [ref=e156]:
              - generic [ref=e157]: ITELEC 4
              - generic [ref=e158]: BSIT - 3H
            - generic [ref=e159]:
              - generic [ref=e160]: 2025-2026 · Sem 1
              - generic [ref=e161]:
                - generic [ref=e162]:
                  - generic [ref=e163]: "1"
                  - generic [ref=e164]: Students
                - generic [ref=e166]:
                  - generic [ref=e167]: "1"
                  - generic [ref=e168]: Concepts
                - generic [ref=e170]:
                  - generic [ref=e171]: "1"
                  - generic [ref=e172]: Alerts
              - generic [ref=e174]:
                - generic [ref=e175]: Class Difficulty
                - generic [ref=e176]: "Avg CDS: -"
              - generic [ref=e179]:
                - generic [ref=e180]: 1 exercises assigned
                - generic [ref=e181]: ⚠ 1 need intervention
        - button "+ Create New Section" [ref=e182] [cursor=pointer]:
          - generic [ref=e183]: +
          - generic [ref=e184]: Create New Section
      - generic [ref=e185]:
        - generic [ref=e186]: Recent Activity — All Sections
        - generic [ref=e187]:
          - generic [ref=e188]:
            - generic [ref=e190]:
              - text: Maria Reyes triggered
              - generic [ref=e191]: High difficulty
              - text: alert on Loops
            - generic [ref=e192]: Sum 1 to N...
            - generic [ref=e193]: 19 hrs ago
          - generic [ref=e194]:
            - generic [ref=e196]:
              - text: Test Student 36 triggered
              - generic [ref=e197]: High difficulty
              - text: alert on Conditionals
            - generic [ref=e198]: Sum 1 to N...
            - generic [ref=e199]: 22 hrs ago
          - generic [ref=e200]:
            - generic [ref=e202]:
              - text: Test Student 33 triggered
              - generic [ref=e203]: High difficulty
              - text: alert on Conditionals
            - generic [ref=e204]: Sum 1 to N...
            - generic [ref=e205]: 22 hrs ago
          - generic [ref=e206]:
            - generic [ref=e208]:
              - text: Test Student 29 triggered
              - generic [ref=e209]: High difficulty
              - text: alert on Conditionals
            - generic [ref=e210]: Sum 1 to N...
            - generic [ref=e211]: 22 hrs ago
          - generic [ref=e212]:
            - generic [ref=e214]:
              - text: Test Student 16 triggered
              - generic [ref=e215]: High difficulty
              - text: alert on Conditionals
            - generic [ref=e216]: Sum 1 to N...
            - generic [ref=e217]: 22 hrs ago
```

# Test source

```ts
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
  251 |     await page.waitForLoadState('networkidle');
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
> 310 |     expect(semesterSelect || semesterInput).toBeTruthy();
      |                                             ^ Error: expect(received).toBeTruthy()
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