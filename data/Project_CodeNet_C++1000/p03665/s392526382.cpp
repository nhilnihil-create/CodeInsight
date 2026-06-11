#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int ,int>;
const int INF = 1001001001;
const int MOD = 1000000007;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

#ifdef _DEBUG
#include "debug.h"
#else
#define debug(...)
#define print(...)
#endif

ll nCr(int n, int r) {
  if (r * 2 > n) r = n - r;
  ll dividend = 1;
  ll divisor  = 1;
  FOR(i, 1, r+1) {
    dividend *= (n-i+1);
    divisor  *= i;
  }
  return dividend / divisor;
}

int main() {
    int n, p; cin >> n >> p;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int k = 0;
    rep(i, n) {
        if (a[i]%2) k++;
    }

    ll cnt = 0;
    rep(i, n+1) {
        if (p==1 && k>=i && i%2!=0) cnt += nCr(k, i);
        if (p==0 && k>=i && i%2==0) cnt += nCr(k, i);
    }
    
    cout << cnt * (1ll<<(n-k)) << endl;
}