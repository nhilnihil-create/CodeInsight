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
  int n; cin >> n;
  V a(n);
  rep(i, n) cin >> a[i];
  
  int m = *max_element(all(a));
  int mi = *min_element(all(a));
  if (m - mi > 1) {
    cout << "No" << endl;
    return 0;
  }
  if (m == mi) if (m == n-1 || (1 <= m && m <= n/2)) {
    cout << "Yes" << endl;
    return 0;
  }

  int k = 0;
  rep(i, n) if (a[i] == m) k++;

  int l = n-k+1;
  int r = n-k+k/2;

  if (l <= m && m <= r) {
    cout << "Yes" << endl;
  }
  else cout << "No" << endl;
  return 0;
}
