#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  rep(i,n) cin >> v[i];
  int ans = 0;
  rep(i,n) {
    int l = v[i] - 0;
    int r = abs(v[i] - k);
    int u = min(l, r);
    ans += 2 * u;
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}