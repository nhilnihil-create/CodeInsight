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
  int h, w, n;
  cin >> h >> w >> n;
  vector<int> a(n);
  REP(i, n) cin >> a[i];
  vector<int> b;
  REP(i, n) REP(j, a[i]) b.emplace_back(i+1);
  vector<vector<int>> ans(h, vector<int>(w));
  REP(i, h){
    REP(j, w) ans[i][j] = b[i*w+j];
    if(i%2) reverse(ALL(ans[i]));
  }
  REP(i, h){
    REP(j, w) printf("%d ", ans[i][j]);
    printf("\n");
  }
  return 0;
}