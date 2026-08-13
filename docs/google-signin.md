# Google Sign-In (GIS) Setup Guide

CodeInsight supports signing in / registering with a Google account via the
Google Identity Services (GIS) JavaScript button. This document covers the
one-time Google Cloud Console setup and how the integration is wired.

## How it works

1. The user clicks the **Continue with Google** button on the Login page or the
   first step of the Register page. The button is rendered by Google's
   `accounts.google.com/gsi/client` script (`frontend/src/components/GoogleAuthButton.jsx`).
2. Google returns a signed **ID token** (JWT) to the button callback.
3. The frontend POSTs `{ credential: <id-token> }` to `POST /api/auth/google`
   (rate-limited, Joi-validated, Swagger-documented).
4. The backend verifies the token with `OAuth2Client.verifyIdToken`
   (`google-auth-library`) against `GOOGLE_CLIENT_ID`. The library enforces the
   issuer (`accounts.google.com`) and the audience, so only tokens minted for
   *your* client ID are accepted.
5. New accounts are created with:
   - `password_hash = NULL` (Google-only login — no password)
   - `email_verified = true`
   - `provider = 'google'`, `google_id = sub`, `avatar_url` (truncated to 500 chars)
   - role auto-derived from the email domain (university → `instructor`, else `student`)
6. Existing accounts are **linked** by email or `google_id` — their stored role is
   preserved, never re-classified.
7. A session cookie (`ci_token`) is set exactly like email/password login.

## Prerequisites

- A Google Cloud project with the **Google Identity Services** API available
  (it is enabled by default on new projects; the GIS button needs no billing).

## Step 1 — Create the OAuth client ID

1. Go to the [Google Cloud Console](https://console.cloud.google.com/).
2. Select your project, then **APIs & Services → Credentials**.
3. Click **+ Create Credentials → OAuth client ID**.
4. Application type: **Web application**.
5. Name it something recognizable, e.g. `CodeInsight Web`.
6. **Authorized JavaScript origins** — add every origin that will host the
   frontend button:
   - `http://localhost:5173` (Vite dev server)
   - `http://localhost:3000` (if you serve the built frontend on port 3000)
   - `https://<your-prod-domain>` (production)
7. **Authorized redirect URIs**: leave empty. The GIS button flow (ID token) does
   **not** require redirect URIs — that is only needed for the OAuth 2.0
   authorization-code flow.
8. Click **Create** and copy the resulting **Client ID**
   (format: `xxxxxxxxxxxx-xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx.apps.googleusercontent.com`).
   The Client ID is public — it is shipped to the browser. The **Client Secret**
   is **not** used by this integration and should never be put in the frontend.

## Step 2 — Env vars

Backend (`backend/.env` — copy the keys from `backend/.env.example`):

```env
GOOGLE_CLIENT_ID=xxxxxxxxxxxx-xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx.apps.googleusercontent.com
GOOGLE_CLIENT_SECRET=your-client-secret   # documented only — NOT used by this flow
```

> `GOOGLE_CLIENT_SECRET` is intentionally never read by the code. It is listed
> so the credential is not lost if the integration is later upgraded to the
> authorization-code flow. Do not put it in the frontend.

Frontend (`frontend/.env.local` — copy the keys from `frontend/.env.example`):

```env
VITE_GOOGLE_CLIENT_ID=xxxxxxxxxxxx-xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx.apps.googleusercontent.com
```

**Important**: the frontend `VITE_GOOGLE_CLIENT_ID` and the backend
`GOOGLE_CLIENT_ID` must be the **same value** — the backend uses it as the
audience when verifying the token.

Restart both processes after changing env vars.

## Step 3 — CORS

The backend must allow the frontend origin. `CORS_ORIGINS` in `backend/.env`
is a comma-separated list of allowed origins:

```env
CORS_ORIGINS=http://localhost:5173,http://localhost:3000,https://<your-prod-domain>
```

The GIS token exchange happens through the app's own API (same-origin after
proxy/CORS), so no additional Google-side CORS configuration is needed.

## Step 4 — Database

Run the migration (idempotent, safe to run repeatedly):

```bash
cd backend
npm run migrate
```

This adds to the `users` table (if not already present):

- `google_id VARCHAR(100) UNIQUE`
- `provider VARCHAR(20) DEFAULT 'email'`
- `avatar_url VARCHAR(512)`
- makes `password_hash` nullable

`backend/schema.sql` already declares these for fresh databases.

## Behavior notes

- **Google-only account + password login**: an account created via Google has a
  NULL `password_hash`. If someone tries the email/password form with that email,
  they get a generic `401 Invalid credentials` (never a 500).
- **Email-first account + Google login**: if an existing email-OTP/password
  account signs in with Google, it is linked to the Google account and the stored
  role is preserved. The user can then sign in with either method.
- **Role derivation**: the role comes only from the email-domain classification
  (`determineRole` — university domains → `instructor`, otherwise `student`). The
  Google client never sends a role.
- **Avatar**: `avatar_url` is stored from the Google profile picture, truncated
  to 500 characters.

## Manual test checklist

1. `npm run migrate` succeeds with "✓ Added UNIQUE constraint to users.google_id".
2. Backend logs `PostgreSQL connected` and starts with `GOOGLE_CLIENT_ID` set.
3. Frontend starts with `VITE_GOOGLE_CLIENT_ID` set.
4. On `/login` and `/register`, the **Continue with Google** button renders.
5. Clicking it opens the Google account picker and completes without console errors.
6. First sign-in with a `@gmail.com` account → redirected to `/student/dashboard`;
   the user row in the DB has `provider='google'`, `password_hash=NULL`,
   `email_verified=true`.
7. First sign-in with a university email (e.g. `@psu.edu`) → `/instructor/dashboard`.
8. Sign out, then sign in again with the same Google account → no duplicate row
   (linked by `google_id`).
9. Sign in with Google using the same email as an existing password account →
   the existing account is linked, its role is unchanged, and password login
   still works.
10. With `VITE_GOOGLE_CLIENT_ID` unset: dev shows the muted
    "Google sign-in is not configured" hint; a production build renders nothing.
11. Invalid token path: tamper with the credential (e.g. via devtools) → `401
    Invalid Google sign-in token`, no account created.
