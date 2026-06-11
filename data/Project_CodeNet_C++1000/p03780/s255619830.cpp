#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep2(i, m, n) for(int i=int(m); i<int(n); ++i)
#define drep2(i, m, n) for(int i=int(m-1); i>=int(n); --i)
#define rep(i, n) rep2(i, 0, n)
#define drep(i, n) drep2(i, n, 0)
#define all(a) a.begin(), a.end()
#define fst first
#define snd second
using ll = long long;
using ld = long double;
using V = vector<int>;
using Vll = vector<ll>;
using Vld = vector<ld>;
using VV = vector<V>;
using VVll = vector<Vll>;
using VVld = vector<Vld>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using Pld = pair<ld, ld>;
const int INF = 1<<30;
const ll INFll = 1ll<<62;
const ld EPS = 1e-10;
const int MOD = int(1e9)+7;
template<typename T> inline bool chmin(T& a, T b) {if(a>b) {a=b; return true;} return false;}
template<typename T> inline bool chmax(T& a, T b) {if(a<b) {a=b; return true;} return false;}
inline int Log2(ll x) {int k; for(k=0; x>0; ++k) x>>=1; return k;} // number of binary digits
template<typename T> inline int count_between(vector<T>& a, T l, T r) {
  return lower_bound(all(a), r) - lower_bound(all(a), l); // [l, r)
}


int main() {
  int n, k; cin >> n >> k; 
  Vll a(n), d(n);
  rep(i, n) cin >> a[i];
  sort(all(a));
  reverse(all(a));
 
  rep(i, n) {
    V v;
    ll gou = 0;
    rep2(j, i, n) {
      if (gou + a[j] >= k) {
        v.push_back(j);
        rep(k, v.size()) d[v[k]] = 1;
        v.resize(0);
      }
      else {
        v.push_back(j);
        gou += a[j];
      }
    }
  }
 
  int ans = 0;
  rep(i, n) if (!d[i]) ans++;
  cout << ans << endl;
  return 0;
}