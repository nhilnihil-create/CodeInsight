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
  vector<ll> a(3*n);
  REP(i, 3*n) cin >> a[i];
  priority_queue<ll, vector<ll>, greater<ll>> f;
  priority_queue<ll> b;
  vector<ll>fsum(n+1, 0), bsum(n+1, 0);
  REP(i, n){
    fsum[0] += a[i];
    f.push(a[i]);
    bsum[n] += a[2*n+i];
    b.push(a[2*n+i]);
  }
  REP(i, n){
    f.push(a[n+i]);
    fsum[i+1] = fsum[i] + a[n+i] - f.top();
    f.pop();
    b.push(a[2*n-1-i]);
    bsum[n-1-i] = bsum[n-i] + a[2*n-1-i] - b.top();
    b.pop();
  }
  ll ans = -(1ll<<60);
  REP(i, n+1){
    chmax(ans, fsum[i]-bsum[i]);
  }
  cout << ans << endl;
  

  return 0;
}