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

const int maxn = (int) 2e5 + 5;
int n;
int b[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  n = 2 * n - 1;
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    b[i]--;
  }
  return true;
}

int a[maxn];

bool check(int x) {
  for (int i = 0; i < n; i++) {
    a[i] = (b[i] >= x);
  }
  int pos = n / 2;
  if (a[pos] == a[pos - 1] || a[pos] == a[pos + 1]) {
    return a[pos];
  }
  int l = pos, r = pos;
  while (l && a[l - 1] != a[l]) {
    l--;
  }
  while (r + 1 < n && a[r + 1] != a[r]) {
    r++;
  }
  if (a[l] == a[r]) {
    return a[l];
  }
  int m = (l + r) / 2;
  if (pos <= m) {
    return a[l];
  } else {
    return a[r];
  }
}

void solve() {
  int l = 0, r = n;
  while (l < r - 1) {
    int m = (l + r) / 2;
    if (check(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  printf("%d\n", l + 1);
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
