#include <bits/stdc++.h>
using ll = long long;
#define FOR(i, k, n) for(ll i = (k); i < (n); i++)
#define FORe(i, k, n) for(ll i = (k); i <= (n); i++)
#define FORr(i, k, n) for(ll i = (k)-1; i > (n); i--)
#define FORre(i, k, n) for(ll i = (k)-1; i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;

const int INF = 1001001001;

int main(void){
  ll n;
  cin >> n;
  vector<ll> t(n), a(n);
  REP(i, n) cin >> t[i] >> a[i];
  ll x = t[0], y = a[0];
  REP(i, n-1){
    ll m = max((x+t[i+1]-1)/t[i+1], (y+a[i+1]-1)/a[i+1]);
    x = m*t[i+1];
    y = m*a[i+1];
  }
  cout << x+y << endl;
  return 0;
}