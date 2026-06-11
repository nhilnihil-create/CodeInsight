#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll MOD = 1e9 + 7;

vector<ll> mf(100009, -1);

ll modfact(ll n) {
  if (mf[n] != -1) return mf[n];
  if (n == 0) return mf[0] = 1;
  else return mf[n] = n * modfact(n-1) % MOD;
}

int main() {
  ll n, m;
  cin >> n >> m;
  ll ans;
  if (n == m) ans = 2 * modfact(n) * modfact(m) % MOD;
  else if (abs(n - m) == 1) ans = modfact(n) * modfact(m) % MOD;
  else ans = 0;
  cout << ans << endl;
  return 0;
}