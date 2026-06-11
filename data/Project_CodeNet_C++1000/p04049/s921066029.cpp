#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1000000007;
const int BASE = 27;
const int oo = 1e9;
const double EPS = 1e-9;
const int MX = 2000 + 1;

int n , k, cnt, ans;
vector<pii> E;
vector<int> g[MX];


void dfs(int u , int p , int dist) {
  if (dist > k / 2)cnt++;
  for (auto v : g[u])
    if (v != p)
      dfs(v, u, dist + 1);
}

int main() {
  cin >> n >> k;
  for (int a, b, i = 0; i < n - 1; ++i) {
    scanf("%d%d", &a, &b);
    g[a].pb(b);
    g[b].pb(a);
    E.pb(mp(a, b));
  }
  ans = n;
  for (int it = 0; it < 2; ++it) {
    if (k % 2 == 0) {
      for (int i = 1; i <= n ; ++i) {
        cnt = 0;
        dfs(i, -1, 0);
        ans = min(ans, cnt);
      }
    }
    if (k % 2 == 1) {
      for (auto v : E) {
        cnt = 0;
        dfs(v.x, v.y, 0);
        dfs(v.y, v.x, 0);
        ans = min(ans, cnt);
      }
    }
    k--;
  }
  cout << ans << endl;
  return 0;
}
