#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e13;
const int mod = 1e9+7;
#define ll long long

int n,m,R;
int a[MX],b[MX],c[MX];
int d[202][202];

signed main() {
  cin >> n >> m >> R;
  vector<int> r(R);
  rep(i,R) {
      cin >> r[i];
      r[i]--;
  }
  rep(i,n) {
      rep(j,n) {
          d[i][j]=inf;
      }
  }
  rep(i,n) {
    d[i][i] = 0;
  }
  rep(i,m) {
      int a,b,c;
      cin >> a >> b >> c;
      a--;
      b--;
      d[a][b]=min(d[a][b],c);
      d[b][a]=min(d[b][a],c);
  }

  rep(k,n) {
      rep(i,n) {
          rep(j,n) {
              d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
          }
      }
  }
 sort(r.begin(),r.end());
 int ans = inf;
  do {
      int tmp = 0;
      rep(i,R-1) {
          tmp += d[r[i]][r[i+1]];
        //cout << r[v[i]] << flush;
      }
      ans = min(tmp,ans);
      //cout << "" << endl;
      
  }while(next_permutation(r.begin(),r.end()));

    cout << ans << endl;

  return 0;
}
