#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
int a[100100]; 
int main() {
  int n, x;
  cin >> n >> x;
  rep(i,n) cin >> a[i];
  ll ans = 0;
  rep(i,n-1) {
    ll rem = a[i] + a[i+1] - x;
    if (rem <= 0) continue;
    ans += rem;
    if (rem <= a[i+1]) {
      a[i+1] -= rem;
    }
    else {
      rem -= a[i+1];
      a[i+1] = 0;
      a[i] -= rem;
    }
  }
  cout << ans << endl;
  return 0;
}