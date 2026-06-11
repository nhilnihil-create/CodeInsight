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
  int n;
  cin >> n;
  vector<ll> v(3*n);
  rep(i,3*n) cin >> v[i];
  sort(v.rbegin(), v.rend());
  ll ans = 0;
  int c = 0;
  for(int i = 0; i < 3*n; i++) {
    if (c == n) break;
    if (i%2 != 0) {
      c++;
      ans += v[i];
    }
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}