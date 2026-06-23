# Auth Security Hardening

**Date:** 2026-06-23
**Status:** Draft

## Summary

Harden authentication and registration for a capstone-level academic integrity platform. Fixes 6 issues: admin registration backdoor, missing registration rate limit, email verification, password complexity, SameSite cookie, and JWT revocation.

## Changes

### 1. Block Admin Registration

- Remove `'admin'` from the Joi `role` validator in `backend/lib/validators.js` for the `register` schema
- Only `'student'` and `'instructor'` are accepted during self-registration
- Admin accounts are created only via the seed script (`backend/scripts/seed_admin.js`) or direct DB

### 2. Rate Limit Registration

- Add `registrationLimiter` to `backend/routes/auth.js`: 5 requests per 15 minutes per IP
- Apply it to `POST /api/auth/register`
- Preserve existing `loginLimiter` on `POST /api/auth/login`
- Skip rate limiting when `PLAYWRIGHT=1` env var is set (matching existing pattern)

### 3. Email Verification

**Database** (`backend/schema.sql`):
- Add `email_verified` BOOLEAN DEFAULT false to `users` table
- Add `verification_token` VARCHAR(255) nullable
- Add `verification_token_expires` TIMESTAMP nullable

**Registration flow** (`backend/controllers/authController.js`):
- After insert, generate `crypto.randomBytes(32).toString('hex')` as verification token
- Store SHA-256 hash of token in `verification_token`, set `verification_token_expires` to 24 hours
- Send email via nodemailer with link: `{APP_URL}/api/auth/verify-email/{token}`
- Do NOT generate JWT or set session — user must verify before login
- Return 201 with message: "Registration successful. Please check your email to verify your account."

**Instructor domain gating**:
- Read `INSTRUCTOR_DOMAINS` env var (comma-separated, e.g., `"university.edu, college.ac.uk"`)
- If `role === 'instructor'`, extract domain from email and check against list
- If no match, return 400: "Instructor accounts require an institutional email from: {domains}"

**Verify endpoint** (`GET /api/auth/verify-email/:token`):
- Hash the provided token, look up matching `verification_token` in `users` table
- Check `verification_token_expires` has not passed
- Set `email_verified = true`, clear `verification_token` and `verification_token_expires`
- Redirect to frontend login page with `?verified=true` query param
- If token invalid/expired, return 400 with error message
- Option to resend verification email (rate limited: 1 per 60 seconds per email)

**Login change**:
- After password validation, query `email_verified`
- If false, return 403: "Please verify your email before logging in."

**Email config**:
- Reuse existing nodemailer setup from `backend/services/cdsJobQueue.js`
- Extract shared email utility to `backend/lib/email.js` for both CDS notifications and verification
- Add env vars: `EMAIL_HOST`, `EMAIL_PORT`, `EMAIL_USER`, `EMAIL_PASS`, `EMAIL_FROM`, `APP_URL`, `INSTRUCTOR_DOMAINS`

### 4. Password Complexity

- Update Joi schema in `backend/lib/validators.js` for `register` and `resetPassword`:
  - Minimum 8 characters (already exists)
  - At least 1 uppercase letter (`pattern: /[A-Z]/`)
  - At least 1 lowercase letter (`pattern: /[a-z]/`)
  - At least 1 digit (`pattern: /[0-9]/`)
  - At least 1 special character (`pattern: /[^a-zA-Z0-9]/`)
- Update frontend registration form validation to match
- Update demo/test seed password comment to note the new requirements

### 5. SameSite Cookie

- In `backend/controllers/authController.js`, add `sameSite: 'Lax'` to the `COOKIE_OPTS` object used for setting `ci_token`
- In production, use `sameSite: 'Strict'` for additional CSRF protection

### 6. JWT Revocation

- Add `token_blacklist` table to `schema.sql`:
  ```sql
  CREATE TABLE IF NOT EXISTS token_blacklist (
    id         SERIAL PRIMARY KEY,
    jti        VARCHAR(255) NOT NULL UNIQUE,
    expires_at TIMESTAMP NOT NULL
  );
  ```
- Generate `jti` (JWT ID) via `crypto.randomUUID()` on JWT creation and include it in the token payload
- On logout (`POST /api/auth/logout`): extract JTI from cookie, insert into `token_blacklist` with expiry matching token's `exp`
- In `verifyToken` middleware (`backend/middleware/auth.js`): after JWT verification, check if `jti` is blacklisted. If found, return 401
- Periodic cleanup of expired entries via a simple query in the middleware or a setInterval

### Frontend Changes

- `frontend/src/pages/Register.jsx`: Add password complexity hints (show requirements), remove admin option (already done)
- `frontend/src/pages/Login.jsx`: Show "Please verify your email" message if applicable, "Resend verification" link
- `frontend/src/context/AuthContext.jsx`: Handle verified/unverified states

### Environment Variables

Add to `backend/.env.example`:
```
INSTRUCTOR_DOMAINS=university.edu, college.ac.uk
APP_URL=http://localhost:3000
EMAIL_HOST=smtp.example.com
EMAIL_PORT=587
EMAIL_USER=noreply@example.com
EMAIL_PASS=
EMAIL_FROM=noreply@example.com
```

### Verification

- Unit tests for registration validation (admin role rejected, instructor domain check, password complexity)
- Unit tests for email verification flow (token generation, verification, expiry)
- Unit tests for JWT blacklist
- Integration test: register → verify email → login → logout → token rejected
- Run full test suite: `npm test`
- Run lint: `npm run lint`

## Files Modified

| File | Change |
|---|---|
| `backend/schema.sql` | Add columns + token_blacklist table |
| `backend/lib/validators.js` | Remove admin role, add password complexity |
| `backend/controllers/authController.js` | Rewrite register/login/logout flows |
| `backend/middleware/auth.js` | Add JWT blacklist check, generate JTI |
| `backend/routes/auth.js` | Add registration rate limiter |
| `backend/lib/email.js` | New shared email utility |
| `backend/server.js` | No changes expected |
| `backend/.env.example` | Add new env vars |
| `backend/migrations.js` | Add migration for new columns/table |
| `frontend/src/pages/Register.jsx` | Password hints |
| `frontend/src/pages/Login.jsx` | Verification status messages |
| `test/` | New auth security tests |

## Order of Implementation

1. Database changes (schema + migration)
2. Email utility extraction
3. Rate limiter + admin role removal
4. Email verification flow
5. Password complexity validation
6. SameSite cookie
7. JWT revocation (token_blacklist + middleware check)
8. Frontend updates
9. Tests
