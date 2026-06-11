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
  ll a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  vector<ll> w, s;
  for(ll i = 0; 100*a*i <= f; i++){
    for(ll j = 0; 100*a*i+100*b*j <= f; j++){
      w.emplace_back(100*a*i + 100*b*j);
    }
  }

  for(ll i = 0; c*i <= f; i++){
    for(ll j = 0; c*i+d*j <= f; j++){
      s.emplace_back(c*i+d*j);
    }
  }

  ll n = w.size();
  ll m = s.size();

  ll sw = 0, sg = 0;
  double mx = -1;
  REP(i, n) REP(j, m){
    if(w[i]+s[j] > f) continue;
    if(w[i]/100*e < s[j]) continue;
    double p = 100.0 * s[j] / (w[i]+s[j]);
    if(mx < p){
      mx = p;
      sw = w[i]+s[j];
      sg = s[j];
    }
  }
  if(mx == -1) sw = 100*a;
  printf("%lld %lld\n", sw, sg);
  return 0;
}