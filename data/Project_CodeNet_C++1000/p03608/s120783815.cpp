#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define vc vector<char>
#define ii pair<int,int>
#define fi first
#define sc second
#define stoi stoll
#define all(x) (x).begin(),(x).end()
#define get_bit(x, k) ((x >> k) & 1)
// ---------------------------------

const int N = 205;

int dis[N][N];

void chmin(int &a, int b) {
  if (a > b) a = b;
}

void MAIN() {
  int n, m, r;
  cin >> n >> m >> r;
  vector<int> R(r);
  for (auto &i : R) {
    cin >> i;
  }
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    dis[i][j] = 2e9;
  }
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    dis[u][v] = dis[v][u] = w;
  }
  for (int k = 1; k <= n; k++)
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    chmin(dis[i][j], dis[i][k] + dis[k][j]);
  }
  int ans = 2e9;
  sort(all(R));
  do {
    int cal = 0;
    for (int i = 0; i < r - 1; i++) {
      cal += dis[R[i]][R[i + 1]];
    }
    ans = min(ans, cal);
  } while (next_permutation(all(R)));
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
