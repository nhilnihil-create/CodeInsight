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

long long n;

bool read() {
  if (scanf("%lld", &n) < 1) {
    return false;
  }
  return true;
}

int cur;

vector<int> get(long long n) {
  if (n == 1) {
    vector<int> ans = {cur, cur};
    cur++;
    return ans;
  }
  if (n & 1) {
    auto ans = get(n >> 1);
    int k = sz(ans) / 2;
    ans.insert(ans.begin() + k, cur);
    ans.push_back(cur);
    cur++;
    return ans;
  }
  auto ans = get(n - 1);
  int k = sz(ans) / 2;
  ans.insert(ans.begin() + k, cur);
  ans.insert(ans.begin() + k, cur);
  cur++;
  return ans;
}

void solve() {
  cur = 1;
  vector<int> ans = get(n);
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
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
