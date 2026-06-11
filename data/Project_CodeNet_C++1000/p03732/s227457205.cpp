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
  ll N, W;
  cin >> N >> W;
  vector<ll> w(N), v(N);
  REP(i, N) cin >> w[i] >> v[i];
  vector<vector<ll>> a(4), b(4);
  REP(i, N) a[w[i]-w[0]].emplace_back(v[i]);
  REP(i, 4){
    b[i].emplace_back(0);
    sort(ALLr(a[i]));
    REP(j, a[i].size()){
      b[i].emplace_back(b[i].back() + a[i][j]);
    }
  }

  ll ans = 0;
  REP(i, b[0].size()) REP(j, b[1].size()){
    REP(k, b[2].size()) REP(l, b[3].size()){
      if(w[0]*i + (w[0]+1)*j + (w[0]+2)*k + (w[0]+3)*l <= W){
        chmax(ans, b[0][i]+b[1][j]+b[2][k]+b[3][l]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}