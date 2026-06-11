#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD (long long)(1e9+7)
#define INF (1LL<<60)
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define rep1(i,n) for(ll i = 1; i <= (n); i++)

template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}


// 最大公約数
ll gcd(ll a, ll b)
{
  if(b == 0) return a;
  return gcd(b, a % b);
}

// mod m におけるa の逆元
ll modinv(ll a, ll m) {
  ll b = m, u = 1, v = 0;
  while (b) {
    ll t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}

// 素因数分解
vector<pair<ll, ll>> prim;
void pf(ll n)
{
  ll s = sqrt(n);
  ll r = 0;
  for(ll i = 2; i <= s; i++) {
    if((n % i) == 0) {
      r = 0;
      do {
	r++;
	n = n / i;
      } while((n % i) == 0);
      prim.push_back({i, r});
    }
  }
  if(n > s) {
    prim.push_back({n, 1});
  }
}

void solve()
{
  ll N, M; cin >> N >> M;
  vector<ll> x(M), y(M); rep(i, M) cin >> x[i] >> y[i];
  ll ans = 0;

  vector<ll> cnt(N, 1);
  vector<bool> red(N, false);
  red[0] = true;

  rep(i, M) {
    x[i]--;y[i]--;
    cnt[x[i]] --;
    cnt[y[i]] ++;
    if(red[x[i]]) red[y[i]] = true;
    if(cnt[x[i]] == 0) red[x[i]] = false;
  }
  rep(i, N) ans += red[i] ?  1 : 0;
  
  cout << ans << endl;
}


int main(void)
{
  // ll t; cin >> t; rep(i, t)
  solve();
}
