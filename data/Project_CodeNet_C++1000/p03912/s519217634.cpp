#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;

const int N = 1e5 + 10;
VI f[N];
int p[N];

template<class T>
int SZ(T x) { return x.size(); }

int main() {
#ifdef LOCAL_EXEC
//	freopen("sample.in", "r", stdin);
//	freopen("sample.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    f[x % m].push_back(x);
  }

  for (int x = 0; x < m; x++) {
    sort(f[x].begin(), f[x].end());
    int prv = -1;
    for (int y: f[x]) {
      if (y == prv) {
        p[x]++;
        prv = -1;
      } else {
        prv = y;
      }
    }
  }

  int ans = 0;
  for (int x = 1, y = m - 1; x < y; x++, y--) {
    int cur = min(f[x].size(), f[y].size());
    ans += cur;
    ans += max(0, min(p[x], (SZ(f[x]) - cur) / 2));
    ans += max(0, min(p[y], (SZ(f[y]) - cur) / 2));
  }
  ans += f[0].size() / 2;
  if (m % 2 == 0) ans += f[m / 2].size() / 2;
  cout << ans << endl;

  return 0;
}
