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
  vector<ll> a(n), b(n+1, 0), c(n+1, 0);
  REP(i, n) cin >> a[i];
  ll p = 0, q = 0;
  REP(i, n){
    if(i%2 == 0){
      if(b[i]+a[i] > 0){
        b[i+1] = b[i]+a[i];
      }else{
        p += 1ll - (b[i]+a[i]);
        b[i+1] = 1;
      }

      if(c[i]+a[i] < 0){
        c[i+1] = c[i] + a[i];
      }else{
        q += c[i]+a[i]+1ll;
        c[i+1] = -1;
      }
    }else{
      if(b[i]+a[i] < 0){
        b[i+1] = b[i] + a[i];
      }else{
        p += b[i]+a[i]+1ll;
        b[i+1] = -1;
      }

      if(c[i]+a[i] > 0){
        c[i+1] = c[i] + a[i];
      }else{
        q += 1ll - (c[i]+a[i]);
        c[i+1] = 1;
      }
    }
  }
  cout << min(p, q) << endl;
  return 0;
}