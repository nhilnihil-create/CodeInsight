#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

const int N = 3e5;
vector<int> edges[N];
int p[N], dst[N];
int n, K;
set<pair<int, int>, greater<pair<int, int> > > st;

void dfs(int v, int d) {
  dst[v] = d;
  if (dst[v] > K)
    st.insert({dst[v], v});
  for (int u : edges[v]) {
    dfs(u, d + 1);
  }
}

void deleteAll(int v, int d = 0) {
  st.erase({dst[v], v});
  if (d == K - 1) return;
  for (int u : edges[v]) {
    deleteAll(u, d + 1);
  }
}

void solve() {
  cin >> n >> K;
  int ans = 0;
  for (int v = 1; v <= n; v++) {
    int u; cin >> u;
    if (v == 1) {
      ans += (u != 1); p[1] = 1; continue;
    }
    edges[u].push_back(v);
    p[v] = u;
  }
  dfs(1, 0);
  while (!st.empty()) {
    int v = st.begin()->second; st.erase(st.begin());
    int pr = v;
    for (int iter = 0; iter < K - 1; iter++) {
      pr = p[pr];
    }
    deleteAll(pr);
    ans++;
  }
  cout << ans;
}

// CHECK LIMITS (n <= 10^5)
// CHECK CORNER CASES (n == 1)

int main() {
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  cout.setf(ios::fixed), cout.precision(20);
  //cout << 1.0 * clock() / CLOCKS_PER_SEC << endl;
  solve();
}
