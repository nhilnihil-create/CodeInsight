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

ll com[51][51];

int main(void){
  ll n, a, b;
  cin >> n >> a >> b;
  vector<ll> v(n);
  map<ll, ll> mp;
  REP(i, n) cin >> v[i], mp[v[i]]++;;
  sort(ALLr(v));
  double ave = 0;
  REP(i, a) ave += v[i];
  ave /= a;

  com[0][0] = 1;
  FORe(i, 1, n){
    REP(j, i+1){
      com[i][j] += com[i-1][j];
      if(j > 0) com[i][j] += com[i-1][j-1];
    }
  }

  ll ans = 0;
  if(v[0] != v[a-1]){
    ll m = 0;
    ll x = mp[v[a-1]];
    REP(i, a) if(v[i] == v[a-1]) m++;
    ans = com[x][m];
  }else{
    ll x = mp[v[0]];
    FORe(i, a, b) ans += com[x][i];
  }
  printf("%.10f\n", ave);
  cout << ans << endl;
  return 0;
}