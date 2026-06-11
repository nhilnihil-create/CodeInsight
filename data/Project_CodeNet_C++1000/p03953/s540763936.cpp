#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const long long infll = (long long) 1.01e18;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

#ifdef DEBUG
mt19937 mrand(300); 
#else
mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count()); 
#endif

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 1e5 + 5;
int n;
long long x[maxn];
int m;
long long k;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", &x[i]);
  }
  scanf("%d%lld", &m, &k);
  for (int i = 0; i < m; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  return true;
}

int d[maxn];
int p[maxn];
int used[maxn];

void solve() {
  for (int i = 0; i + 1 < n; i++) {
    d[i] = x[i + 1] - x[i];
  }
  n--;
  for (int i = 0; i < n; i++) {
    p[i] = i;
    used[i] = false;
  }
  for (int i = 0; i < m; i++) {
    swap(p[a[i] - 1], p[a[i]]);
  }
  for (int s = 0; s < n; s++) {
    if (used[s]) {
      continue;
    }
    vector<int> c;
    for (int x = s; !used[x]; x = p[x]) {
      c.push_back(x);
      used[x] = true;
    }
    int sh = k % sz(c);
    for (int i = 0; i < sz(c); i++) {
      int x = c[i], y = c[(i + sh) % sz(c)];
      p[x] = y;
    }
  }
  for (int i = 0; i < n; i++) {
    x[i + 1] = x[i] + d[p[i]];
  }
  for (int i = 0; i <= n; i++) {
    printf("%lld\n", x[i]);
  }
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}
