#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using vi = vector<ll>;
using vvi = vector<vector<ll>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const ll MOD = 1000000007;
const ll INF = 1000000000;
const ll LINF = 1ll<<50;
template<typename T>
void printv(const vector<T>& s) {
  for(ll i=0;i<(ll)(s.size());++i) {
    cout << s[i];
    if(i == (ll)(s.size())-1) cout << endl;
    else cout << " ";
  }
}
bool bs(ll mid, ll n, ll k, const vector<ll> &a) {
  vector<vector<bool>> dp(n+1, vector<bool>(k, false));
  dp[0][0] = true;
  for(ll i=0;i<n;++i) {
    for(ll j=0;j<k;++j) {
      if(!dp[i][j]) continue;
      dp[i+1][j] = dp[i][j];
      if(i != mid && j + a[i] < k) dp[i+1][j+a[i]] = dp[i][j];
    }
  }
  bool need = false;
  for(ll i=max(0ll, k-a[mid]);i<k;++i) {
    need |= dp[n][i];
  }
  return !need;
}
signed main() {
  cin.tie(0);
  cout << fixed << setprecision(10);
  ll n, k; cin >> n >> k;
  vector<ll> a(n);
  for(ll i=0;i<n;++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  ll l = 0, r = n;
  while(r - l > 1) {
    ll mid = (l + r) / 2;
    if(bs(mid, n, k, a)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  if(l != 0 && l != n-1) cout << l+1 << endl;
  else if(l == 0) cout << (bs(0, n, k, a) ? 1 : 0) << endl;
  else cout << (bs(n-1, n, k, a) ? n : n-1) << endl;
}
