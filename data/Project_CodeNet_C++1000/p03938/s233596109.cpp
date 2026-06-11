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
  V x(n);
  rep(i, n) {
    int p; cin >> p;
    p--;
    x[p] = i+1;
  }

  V a = x;
  V b = x;
  rep(i, n-1) a[i+1] += a[i];
  rep(i, n-1) b[n-i-2] += b[n-i-1];
  
  rep(i, n) cout << a[i] << " ";
  cout << endl;
  rep(i, n) cout << b[i] << " ";
  cout << endl;
  return 0;
}
