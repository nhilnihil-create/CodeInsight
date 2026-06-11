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
/*
レート 1-399：灰色
レート 400-799：茶色
レート 800-1199：緑色
レート 1200-1599：水色
レート 1600-1999：青色
レート 2000-2399：黄色
レート 2400-2799：橙色
レート 2800-3199：赤色
*/

ll pnt[] = {1, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200};

void solve()
{
  ll N; cin >> N;
  vector<ll> a(N); rep(i, N) cin >> a[i];

  ll ans1 = 0;
  ll ans2 = 0;
  vector<ll>cnt(8,0);
  ll ov3200 = 0;

  rep(i, N) {
    rep(j, 8) {
      if(pnt[j] <= a[i] && a[i] < pnt[j + 1]) cnt[j] = 1;
    }
    if(a[i] >= 3200) ov3200 ++;
  }
  rep(i, 8) ans1 += cnt[i];
  ans2 = ans1 + ov3200; 
  if(ans1 == 0 && ov3200 > 0) ans1 = 1;
  
  cout << ans1 << " " << ans2 << endl;
}


int main(void)
{
  // ll t; cin >> t; rep(i, t)
  solve();
}
