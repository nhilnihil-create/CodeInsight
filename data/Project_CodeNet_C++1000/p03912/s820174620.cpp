#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 1e5 + 5;
int n, m;
int cnt[maxn];

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < maxn; i++) {
    cnt[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    cnt[x]++;
  }
  return true;
}

vector<int> g[maxn][2];
int res;

void solve() {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 2; j++) {
      g[i][j].clear();
    }
  }
  for (int i = 0; i < maxn; i++) {
    if (cnt[i]) {
      g[i % m][cnt[i] % 2].push_back(cnt[i]);
    }
  }
  res = 0;
  for (int i = 0; i < m; i++) {
    if (2 * i % m == 0) {
      int sum = 0;
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < sz(g[i][j]); k++) {
          sum += g[i][j][k];
        }
      }
      res += sum / 2;
      g[i][0].clear();
      g[i][1].clear();
      continue;
    }
    int j = m - i;
    while (!g[i][1].empty()) {
      if (!g[j][1].empty()) {
        if (g[i][1].back() > 1) {
          g[i][0].push_back(g[i][1].back() - 1);
        }
        g[i][1].pop_back();
        if (g[j][1].back() > 1) {
          g[j][0].push_back(g[j][1].back() - 1);
        }
        g[j][1].pop_back();
        res++;
      } else if (!g[j][0].empty()) {
        if (g[i][1].back() > 1) {
          g[i][0].push_back(g[i][1].back() - 1);
        }
        g[i][1].pop_back();
        g[j][1].push_back(g[j][0].back() - 1);
        g[j][0].pop_back();
        res++;
      } else {
        break;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < sz(g[i][j]); k++) {
        res += g[i][j][k] / 2;
      }
    }
  }
  printf("%d\n", res);
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}
