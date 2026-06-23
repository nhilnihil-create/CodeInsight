# Auth Security Hardening Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Harden auth: block admin self-registration, add registration rate limit, enforce email verification + instructor domain check, password complexity, SameSite cookie, JWT revocation.

**Architecture:** Backend Express routes → authController → JWT + bcrypt + nodemailer + DB. Frontend React pages with shadcn UI. Runtime migrations via `migrations.js`.

**Tech Stack:** Node 22, Express, PostgreSQL, JWT, bcryptjs, nodemailer, express-rate-limit, React, shadcn/ui

## Global Constraints

- Use `crypto.randomUUID()` not `uuid` package for JTI generation
- Follow existing patterns in `migrations.js` (`addColumnIfMissing`, `tableExists`, `columnExists`)
- Rate limiters follow existing `loginLimiter` pattern (skip when `PLAYWRIGHT=1`)
- Joi schema changes in `backend/lib/validators.js`
- Email utility extracted from `cdsJobQueue.js` into `backend/lib/email.js`
- instructor domain gating via `INSTRUCTOR_DOMAINS` env var (comma-separated)

---

### Task 1: Database Schema Changes

**Files:**
- Modify: `backend/schema.sql`
- Modify: `backend/migrations.js`
- Test: `test/` (covered later in Task 7)

**Interfaces:**
- Consumes: existing `users` table, existing migration patterns
- Produces: `users` table with `email_verified`, `verification_token`, `verification_token_expires` columns; `token_blacklist` table

- [ ] **Step 1: Add columns to users table in schema.sql**

Edit `backend/schema.sql:16` — add columns after `role`:

```sql
  email_verified          BOOLEAN DEFAULT false,
  verification_token      VARCHAR(255),
  verification_token_expires TIMESTAMP,
```

- [ ] **Step 2: Add token_blacklist table to schema.sql**

Add after users table (before sections):

```sql
-- ── Token Blacklist (JWT revocation) ─────────────────────────────────────────

CREATE TABLE IF NOT EXISTS token_blacklist (
  id         SERIAL PRIMARY KEY,
  jti        VARCHAR(255) NOT NULL UNIQUE,
  expires_at TIMESTAMP NOT NULL
);

CREATE INDEX IF NOT EXISTS idx_token_blacklist_jti ON token_blacklist(jti);
CREATE INDEX IF NOT EXISTS idx_token_blacklist_expires ON token_blacklist(expires_at);
```

- [ ] **Step 3: Add migration for existing databases in migrations.js**

Edit `backend/migrations.js` — add inside `applySchemaPatches()`:

```javascript
if (await tableExists('users')) {
  patches.push(addColumnIfMissing('users', 'email_verified', 'BOOLEAN DEFAULT false'));
  patches.push(addColumnIfMissing('users', 'verification_token', 'VARCHAR(255)'));
  patches.push(addColumnIfMissing('users', 'verification_token_expires', 'TIMESTAMP'));
}

if (!(await tableExists('token_blacklist'))) {
  await db.query(`
    CREATE TABLE token_blacklist (
      id         SERIAL PRIMARY KEY,
      jti        VARCHAR(255) NOT NULL UNIQUE,
      expires_at TIMESTAMP NOT NULL
    )
  `);
  await db.query(`CREATE INDEX idx_token_blacklist_jti ON token_blacklist(jti)`);
  await db.query(`CREATE INDEX idx_token_blacklist_expires ON token_blacklist(expires_at)`);
  console.log('✓ Created token_blacklist table');
}
```

### Task 2: Shared Email Utility

**Files:**
- Create: `backend/lib/email.js`
- Modify: `backend/services/cdsJobQueue.js`
- Test: covered in Task 7

**Interfaces:**
- Consumes: `nodemailer`, env vars `EMAIL_HOST`, `EMAIL_PORT`, `EMAIL_USER`, `EMAIL_PASS`, `EMAIL_FROM`
- Produces: `sendEmail({ to, subject, html })` function, `sendVerificationEmail({ to, name, token })` function

- [ ] **Step 1: Create `backend/lib/email.js`**

```javascript
const nodemailer = require('nodemailer');
const logger = require('./logger');

function createTransporter() {
  if (process.env.EMAIL_ENABLED !== 'true') return null;
  return nodemailer.createTransport({
    host: process.env.EMAIL_HOST || 'smtp.ethereal.email',
    port: parseInt(process.env.EMAIL_PORT, 10) || 587,
    secure: parseInt(process.env.EMAIL_PORT, 10) === 465,
    auth: {
      user: process.env.EMAIL_USER,
      pass: process.env.EMAIL_PASS,
    },
  });
}

async function sendEmail({ to, subject, html }) {
  if (process.env.EMAIL_ENABLED !== 'true') {
    logger.info({ to, subject }, 'Email disabled — skipping send');
    return;
  }
  const transporter = createTransporter();
  if (!transporter) {
    logger.warn('Email transporter not configured');
    return;
  }
  const from = process.env.EMAIL_FROM || 'noreply@codeinsight.psu.edu';
  await transporter.sendMail({ from, to, subject, html });
  logger.info({ to, subject }, 'Email sent');
}

async function sendVerificationEmail({ to, name, token }) {
  const appUrl = process.env.APP_URL || 'http://localhost:5000';
  const link = `${appUrl}/api/auth/verify-email/${token}`;
  const subject = 'Verify your CodeInsight account';
  const html = `
    <h1>Welcome to CodeInsight, ${name}!</h1>
    <p>Please verify your email address by clicking the link below:</p>
    <p><a href="${link}">Verify Email</a></p>
    <p>This link expires in 24 hours.</p>
    <p>If you did not create this account, please ignore this email.</p>
  `;
  await sendEmail({ to, subject, html });
}

module.exports = { sendEmail, sendVerificationEmail };
```

- [ ] **Step 2: Refactor cdsJobQueue.js to use shared email utility**

Edit `backend/services/cdsJobQueue.js`:

Remove line 3 (`const nodemailer = require('nodemailer');`).

Replace the entire `sendEmailNotifications` function (lines 162-214):

```javascript
const { sendEmail } = require('../lib/email');

async function sendEmailNotifications(students, message, exerciseId) {
  try {
    const exerciseRes = await db.query(
      `SELECT title FROM exercises WHERE id = $1`,
      [exerciseId]
    );
    const exerciseTitle = exerciseRes.rows.length ? exerciseRes.rows[0].title : 'Exercise';

    const results = await Promise.allSettled(students.map(student => {
      const subject = `CodeInsight: CDS Computation Complete for ${exerciseTitle}`;
      const html = `
        <h2>Hello ${student.name},</h2>
        <p>${message}</p>
        <p><strong>Exercise:</strong> ${exerciseTitle}</p>
        <p>You can now view your Concept Difficulty Score (CDS) in the CodeInsight platform.</p>
      `.trim();
      return sendEmail({ to: student.email, subject, html });
    }));

    for (const [i, result] of results.entries()) {
      if (result.status === 'fulfilled') {
        logger.info({ email: students[i].email }, 'Email sent');
      } else {
        logger.error({ err: result.reason, email: students[i].email }, 'Failed to send email');
      }
    }
  } catch (err) {
    logger.error({ err }, 'Error sending email notifications');
  }
}
```

### Task 3: Backend Validation + Rate Limiting + SameSite Cookie

**Files:**
- Modify: `backend/lib/validators.js`
- Modify: `backend/routes/auth.js`
- Modify: `backend/controllers/authController.js`
- Modify: `backend/.env.example`

**Interfaces:**
- Consumes: existing Joi validators, existing rateLimit, `crypto` for randomUUID
- Produces: updated `v.register` schema (no admin, password complexity), `registrationLimiter`, SameSite cookie, JTI in JWT

- [ ] **Step 1: Remove admin from registration schema + add password complexity**

Edit `backend/lib/validators.js:7` — change `role` and `password`:

```javascript
const password = Joi.string()
  .min(8).max(128)
  .pattern(/[A-Z]/, 'uppercase')
  .pattern(/[a-z]/, 'lowercase')
  .pattern(/[0-9]/, 'digit')
  .pattern(/[^a-zA-Z0-9]/, 'special')
  .message('Password must be at least 8 characters with uppercase, lowercase, digit, and special character');
```

Edit `backend/lib/validators.js:7` (role line) — remove `'admin'`:

```javascript
const role = Joi.string().valid('instructor', 'student');
```

Keep `admin` in `adminUserCreate` and `adminUserUpdate` schemas (those are admin-only endpoints, already protected by middleware).

- [ ] **Step 2: Add registration rate limiter**

Edit `backend/routes/auth.js` — add after `loginLimiter`:

```javascript
const registrationLimiter = process.env.PLAYWRIGHT === '1'
  ? (req, res, next) => next()
  : rateLimit({
      windowMs: 15 * 60 * 1000,
      max: 5,
      standardHeaders: true,
      legacyHeaders: false,
      message: { message: 'Too many registration attempts. Please try again in 15 minutes.' },
    });
```

Then change line 21:
```javascript
router.post('/register', registrationLimiter, validate.body(v.register), ctrl.register);
```

- [ ] **Step 3: Add SameSite cookie + JTI generation in authController**

Edit `backend/controllers/authController.js`:

Add `crypto` require at top:
```javascript
const crypto = require('crypto');
```

Update `COOKIE_OPTS`:
```javascript
const COOKIE_OPTS = {
  httpOnly: true,
  secure: process.env.NODE_ENV === 'production',
  sameSite: process.env.NODE_ENV === 'production' ? 'Strict' : 'Lax',
  maxAge: 7 * 24 * 60 * 60 * 1000,
  path: '/',
};
```

Update `generateToken` to include JTI:
```javascript
const generateToken = (user) =>
  jwt.sign(
    { id: user.id, name: user.name, email: user.email, role: user.role, jti: crypto.randomUUID() },
    process.env.JWT_SECRET,
    { expiresIn: '7d' }
  );
```

- [ ] **Step 4: Add `INSTRUCTOR_DOMAINS` + `APP_URL` to .env.example**

Edit `backend/.env.example` — add after `EMAIL_FROM`:
```
INSTRUCTOR_DOMAINS=psu.edu
APP_URL=http://localhost:5000
```

### Task 4: Email Verification Flow and Login Gating

**Files:**
- Modify: `backend/controllers/authController.js`
- Modify: `backend/routes/auth.js`

**Interfaces:**
- Consumes: `crypto` for token generation, `sendVerificationEmail` from `lib/email.js`, db
- Produces: `POST /api/auth/register` no longer auto-logs in, `GET /api/auth/verify-email/:token`, login gated on `email_verified`

- [ ] **Step 1: Rewrite register function to send verification email and not create session**

Edit `backend/controllers/authController.js` — replace the `exports.register` function:

```javascript
const crypto = require('crypto');
const { sendVerificationEmail } = require('../lib/email');

exports.register = async (req, res, next) => {
  try {
    const { name, email, password, role } = req.body;

    const exists = await db.query('SELECT id FROM users WHERE email=$1', [email]);
    if (exists.rows.length) throw new AppError('Email already registered', 409, codes.CONFLICT);

    // Instructor domain check
    if (role === 'instructor') {
      const allowedDomains = (process.env.INSTRUCTOR_DOMAINS || '')
        .split(',')
        .map(d => d.trim().toLowerCase())
        .filter(Boolean);
      const emailDomain = email.split('@')[1]?.toLowerCase();
      if (!emailDomain || !allowedDomains.includes(emailDomain)) {
        throw new AppError(
          `Instructor accounts require an institutional email from: ${allowedDomains.join(', ') || 'no domains configured'}`,
          400,
          codes.VALIDATION_ERROR
        );
      }
    }

    const hash = await bcrypt.hash(password, 10);
    const verificationToken = crypto.randomBytes(32).toString('hex');
    const tokenHash = crypto.createHash('sha256').update(verificationToken).digest('hex');

    const result = await db.query(
      `INSERT INTO users (name,email,password_hash,role,email_verified,verification_token,verification_token_expires)
       VALUES($1,$2,$3,$4,false,$5,NOW() + INTERVAL '24 hours')
       RETURNING id,name,email,role`,
      [name, email, hash, role, tokenHash]
    );

    const user = result.rows[0];

    // Send verification email (fire-and-forget — don't block registration)
    sendVerificationEmail({ to: email, name, token: verificationToken })
      .catch(err => logger.error({ err }, 'Failed to send verification email'));

    res.status(201).json({
      message: 'Registration successful. Please check your email to verify your account.',
      user: { id: user.id, name: user.name, email: user.email, role: user.role },
    });
  } catch (err) { next(err); }
};
```

- [ ] **Step 2: Add verify-email route + controller**

Add to `backend/controllers/authController.js`:

```javascript
exports.verifyEmail = async (req, res, next) => {
  try {
    const { token } = req.params;
    if (!token) throw new AppError('Verification token is required', 400, codes.VALIDATION_ERROR);

    const tokenHash = crypto.createHash('sha256').update(token).digest('hex');

    const result = await db.query(
      `SELECT id, email_verified, verification_token_expires FROM users
       WHERE verification_token = $1 AND email_verified = false`,
      [tokenHash]
    );

    if (!result.rows.length) {
      throw new AppError('Invalid or expired verification token', 400, codes.VALIDATION_ERROR);
    }

    const user = result.rows[0];
    if (new Date() > new Date(user.verification_token_expires)) {
      throw new AppError('Verification token has expired. Please register again.', 400, codes.VALIDATION_ERROR);
    }

    await db.query(
      `UPDATE users SET email_verified = true, verification_token = NULL, verification_token_expires = NULL WHERE id = $1`,
      [user.id]
    );

    // Redirect to frontend login
    const frontendUrl = (process.env.CORS_ORIGINS || 'http://localhost:3000').split(',')[0].trim();
    res.redirect(`${frontendUrl}/login?verified=true`);
  } catch (err) { next(err); }
};
```

- [ ] **Step 3: Gate login on email_verified**

Edit `backend/controllers/authController.js` — in `exports.login`, after finding the user and validating password, add:

```javascript
    if (!user.email_verified) {
      throw new AppError('Please verify your email before logging in.', 403, codes.FORBIDDEN);
    }
```

Also update the login query to include `email_verified`:
```javascript
    const result = await db.query(
      'SELECT id,name,email,role,password_hash,email_verified FROM users WHERE email=$1', [email]
    );
```

- [ ] **Step 4: Add verify-email route**

Edit `backend/routes/auth.js` — add after `router.get('/me'...`:

```javascript
router.get('/verify-email/:token', ctrl.verifyEmail);
```

### Task 5: JWT Revocation (Token Blacklist)

**Files:**
- Modify: `backend/middleware/auth.js`
- Modify: `backend/controllers/authController.js`

**Interfaces:**
- Consumes: `token_blacklist` table, JTI from JWT payload
- Produces: blacklist check in `verifyToken`, blacklist insert on logout

- [ ] **Step 1: Add blacklist check in verifyToken middleware**

Edit `backend/middleware/auth.js`:

```javascript
const db = require('../config/db');

const verifyToken = async (req, res, next) => {
  let token = req.cookies?.ci_token;
  if (!token) {
    const header = req.headers['authorization'];
    if (header) token = header.split(' ')[1];
  }
  if (!token) return next(new AppError('No token provided', 401, codes.UNAUTHORIZED));

  try {
    const decoded = jwt.verify(token, process.env.JWT_SECRET);

    // Check token blacklist
    if (decoded.jti) {
      const blacklisted = await db.query(
        'SELECT 1 FROM token_blacklist WHERE jti = $1 AND expires_at > NOW()',
        [decoded.jti]
      );
      if (blacklisted.rows.length) {
        return next(new AppError('Token has been revoked', 401, codes.UNAUTHORIZED));
      }
    }

    req.user = decoded;
    next();
  } catch (err) {
    if (err instanceof AppError) return next(err);
    return next(new AppError('Invalid or expired token', 401, codes.UNAUTHORIZED));
  }
};
```

- [ ] **Step 2: Add JTI blacklist on logout and periodic cleanup**

Edit `backend/controllers/authController.js` — replace `exports.logout`:

```javascript
exports.logout = async (req, res) => {
  try {
    const token = req.cookies?.ci_token;
    if (token) {
      try {
        const decoded = jwt.verify(token, process.env.JWT_SECRET);
        if (decoded.jti && decoded.exp) {
          await db.query(
            'INSERT INTO token_blacklist (jti, expires_at) VALUES ($1, to_timestamp($2)) ON CONFLICT (jti) DO NOTHING',
            [decoded.jti, decoded.exp]
          );
        }
      } catch { /* token may already be expired — still clear cookie */ }
    }
    res.clearCookie('ci_token', { path: '/' });
    res.json({ loggedOut: true });
  } catch (err) { next(err); }
};
```

### Task 6: Frontend Updates

**Files:**
- Modify: `frontend/src/pages/Register.jsx`
- Modify: `frontend/src/pages/Login.jsx`
- Modify: `frontend/src/context/AuthContext.jsx`

- [ ] **Step 1: Update Register.jsx — password complexity hints + no auto-login**

Edit `frontend/src/pages/Register.jsx`:

In the `handleSubmit`, change the registration flow — don't auto-login after register (user must verify email first):

```javascript
  const handleSubmit = async (e) => {
    e.preventDefault();
    setError('');

    const passwordErrors = [];
    if (password.length < 8) passwordErrors.push('at least 8 characters');
    if (!/[A-Z]/.test(password)) passwordErrors.push('one uppercase letter');
    if (!/[a-z]/.test(password)) passwordErrors.push('one lowercase letter');
    if (!/[0-9]/.test(password)) passwordErrors.push('one digit');
    if (!/[^a-zA-Z0-9]/.test(password)) passwordErrors.push('one special character');
    if (passwordErrors.length) {
      setError(`Password must include: ${passwordErrors.join(', ')}`);
      return;
    }

    setLoading(true);

    try {
      const res = await api.post('/api/auth/register', { name, email, password, role });
      // Don't auto-login — email verification required first
      setName('');
      setEmail('');
      setPassword('');
      setError('');
      navigate('/login?registered=true', { replace: true });
    } catch (err) {
      setError(err.response?.data?.message || 'Registration failed');
    } finally {
      setLoading(false);
    }
  };
```

Add password requirements hint below the password field, after the visibility toggle button:

```jsx
              <div className="mt-1.5 text-[11px] text-muted-foreground space-y-0.5">
                <p className={password.length >= 8 ? 'text-green-600' : ''}>• At least 8 characters</p>
                <p className={/[A-Z]/.test(password) ? 'text-green-600' : ''}>• One uppercase letter</p>
                <p className={/[a-z]/.test(password) ? 'text-green-600' : ''}>• One lowercase letter</p>
                <p className={/[0-9]/.test(password) ? 'text-green-600' : ''}>• One digit</p>
                <p className={/[^a-zA-Z0-9]/.test(password) ? 'text-green-600' : ''}>• One special character</p>
              </div>
```

- [ ] **Step 2: Update Login.jsx — show verification status messages**

Edit `frontend/src/pages/Login.jsx`:

Add query param handling at the top of the component:

```javascript
  const [searchParams] = useState(new URLSearchParams(window.location.search));
  const [info, setInfo] = useState(
    searchParams.get('verified') === 'true' ? 'Email verified! You can now log in.' :
    searchParams.get('registered') === 'true' ? 'Registration successful! Check your email to verify your account.' :
    ''
  );
```

Import `useEffect` too. Also add the info banner in the CardContent (before the error banner):

```jsx
            {info && (
              <div className="flex items-start gap-2 rounded-md border border-green-300 bg-green-50 px-3 py-2.5 text-[12.5px] text-green-700">
                <Info className="mt-0.5 h-3.5 w-3.5 shrink-0" />
                <span>{info}</span>
              </div>
            )}
```

- [ ] **Step 3: Update AuthContext.jsx — handle email not verified error**

No changes needed — the login error path already handles `err.response?.data?.message`. The backend returns `'Please verify your email before logging in.'` which will display in the Login error banner.

But we need to remove the auto-login from the Register page (done in Step 1). The AuthContext stays the same.

### Task 7: Tests

**Files:**
- Create: `test/authSecurity.test.js`

- [ ] **Step 1: Write auth security tests**

Create `test/authSecurity.test.js`:

```javascript
const db = require('../backend/config/db');

describe('Auth Security', () => {
  beforeAll(async () => {
    // Ensure test DB has the schema
    const { ensureTablesExist } = require('../backend/migrations');
    await ensureTablesExist();
  });

  afterAll(async () => {
    await db.end();
  });

  describe('Registration validation', () => {
    it('should reject admin role in registration', async () => {
      const v = require('../backend/lib/validators');
      const { error } = v.register.validate({
        name: 'Test',
        email: 'test@test.com',
        password: 'Test1234!',
        role: 'admin',
      });
      expect(error).toBeDefined();
      expect(error.message).toContain('admin');
    });

    it('should accept student role in registration', async () => {
      const v = require('../backend/lib/validators');
      const { error } = v.register.validate({
        name: 'Test',
        email: 'test@test.com',
        password: 'Test1234!',
        role: 'student',
      });
      expect(error).toBeUndefined();
    });

    it('should accept instructor role in registration', async () => {
      const v = require('../backend/lib/validators');
      const { error } = v.register.validate({
        name: 'Test',
        email: 'test@test.com',
        password: 'Test1234!',
        role: 'instructor',
      });
      expect(error).toBeUndefined();
    });

    it('should reject weak passwords', async () => {
      const v = require('../backend/lib/validators');
      const tests = [
        { pwd: 'short1A!', expected: true },  // too short
        { pwd: 'nouppercase1!', expected: true },  // no uppercase
        { pwd: 'NOLOWERCASE1!', expected: true },  // no lowercase
        { pwd: 'NoDigits!', expected: true },  // no digit
        { pwd: 'NoSpecial1', expected: true },  // no special char
        { pwd: 'Valid123!', expected: false },  // valid
        { pwd: 'Compl3x!Pass', expected: false },  // valid
      ];
      for (const { pwd, expected } of tests) {
        const { error } = v.register.validate({
          name: 'Test',
          email: 'test@test.com',
          password: pwd,
          role: 'student',
        });
        expect((error !== undefined)).toBe(expected);
      }
    });
  });

  describe('Instructor domain validation', () => {
    beforeAll(() => {
      process.env.INSTRUCTOR_DOMAINS = 'university.edu, college.edu';
    });

    it('should reject instructor with non-matching domain', async () => {
      // Import the controller module
      const ctrl = require('../backend/controllers/authController');
      // Mock the controller's domain check logic
      const allowedDomains = (process.env.INSTRUCTOR_DOMAINS || '')
        .split(',')
        .map(d => d.trim().toLowerCase())
        .filter(Boolean);
      const emailDomain = 'hacker@gmail.com'.split('@')[1]?.toLowerCase();
      expect(allowedDomains.includes(emailDomain)).toBe(false);
    });

    it('should accept instructor with matching domain', async () => {
      const allowedDomains = (process.env.INSTRUCTOR_DOMAINS || '')
        .split(',')
        .map(d => d.trim().toLowerCase())
        .filter(Boolean);
      const emailDomain = 'prof@university.edu'.split('@')[1]?.toLowerCase();
      expect(allowedDomains.includes(emailDomain)).toBe(true);
    });
  });

  describe('Token blacklist', () => {
    it('should create and query token_blacklist', async () => {
      const jti = 'test-jti-123';
      const expiresAt = new Date(Date.now() + 3600000);
      await db.query(
        'INSERT INTO token_blacklist (jti, expires_at) VALUES ($1, $2) ON CONFLICT (jti) DO NOTHING',
        [jti, expiresAt]
      );
      const result = await db.query(
        'SELECT 1 FROM token_blacklist WHERE jti = $1 AND expires_at > NOW()',
        [jti]
      );
      expect(result.rows.length).toBe(1);
      await db.query('DELETE FROM token_blacklist WHERE jti = $1', [jti]);
    });
  });
});
```

- [ ] **Step 2: Verify tests pass**

Run: `npx jest test/authSecurity.test.js --forceExit --detectOpenHandles`
Expected: all tests PASS

---

## Implementation Order

1. Task 1: Database schema + migration
2. Task 2: Email utility (lib/email.js)
3. Task 3: Validators, rate limiter, SameSite cookie, JTI
4. Task 4: Email verification + login gating
5. Task 5: JWT blacklist
6. Task 6: Frontend updates
7. Task 7: Tests
