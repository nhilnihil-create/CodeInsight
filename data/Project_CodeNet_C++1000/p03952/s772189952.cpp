#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep2(i, m, n) for(int i=int(m); i<int(n); i++)
#define rep(i, n) rep2(i, 0, n)
#define all(a) a.begin(), a.end()
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


int main() {
  ll n, x; cin >> n >> x;
  if (x == 1 || x == 2*n-1) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;

  if (n == 2) {
    cout << 3 << endl;
    cout << 2 << endl;
    cout << 1 << endl;
    return 0;
  }

  if (x == 2) {
    rep(i, n-3) cout << (i+5) << endl;
    cout << 3 << endl;
    cout << 2 << endl;
    cout << 1 << endl;
    cout << 4 << endl;
    rep(i, n-2) cout << (n+2+i) << endl;
    return 0;
  }

  V ans;
  rep2(i, 1, 2*n) if (i < x-2 || i > x+1) ans.push_back(i);
  rep(i, n-3) cout << ans[i] << endl;
  cout << (x-2) << endl;
  cout << (x) << endl;
  cout << (x+1) << endl;
  cout << (x-1) << endl;
  rep(i, n-2) cout << ans[n-3+i] << endl;
  return 0;
}
