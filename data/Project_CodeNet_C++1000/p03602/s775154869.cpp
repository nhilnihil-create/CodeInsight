#include <bits/stdc++.h>
typedef long long LL;
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

using namespace std;

int main(void)
{
  LL n;
  cin >> n;
  LL inf = 1000000007ll;
  vector<vector<LL>> a(n,vector<LL>(n));
  for(auto &&b: a) for(auto &&c: b) cin >> c;
  REP(k,n) REP(i,n) REP(j,n) {
    if(a[i][j]>a[i][k]+a[k][j]) {
      cout << -1 << endl;
      return 0;
    }
  }
  REP(k,n) REP(i,n) REP(j,n) {
    if(a[i][j]==a[i][k]+a[k][j] && a[i][k] != 0 && a[k][j] != 0) {
      a[i][j]=inf;
    }
  }
  LL answer = 0ll;
  for(auto b: a) for(auto c: b) if(c!=inf) answer+=c;
  cout << answer/2 << endl;
}
