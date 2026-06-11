#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,l,r) for(int i=(int)(l);i<(int)(r);i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)x.size())
template<class T>bool chmax(T &a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,T b){if(a>b){a=b;return 1;}return 0;}

/*{
  }*/

using vi = vector<int>;
using vvi = vector<vi>;
using P = pair<int,int>;

//constexpr int mod = 1e9+7;
constexpr int inf = 1LL<<60;

signed main() {
  int n, m;
  cin >> n >> m;

  vi a(m), b(m), c(m);
  rep(i, 0, m){
    cin >> a[i] >> b[i] >> c[i];
    a[i]--; b[i]--;
  }

  vi d(n, inf);
  d[0] = 0;

  rep(i, 0, n) rep(j, 0, m){
    if(d[a[j]] == inf) continue;
    if(d[b[j]] > d[a[j]] - c[j]){
      d[b[j]] = d[a[j]] - c[j];
    }
  }

  int ans = -d[n-1];
  vector<bool> vis(n, false);

  rep(i, 0, n) rep(j, 0, m){
    if(d[a[j]] == inf) continue;
    if(d[b[j]] > d[a[j]] - c[j]){
      d[b[j]] = d[a[j]] - c[j];
      vis[b[j]] = true;
    }
    if(vis[a[j]]) vis[b[j]] = true;
  }

  if(vis[n-1]) cout << "inf" << endl;
  else cout << ans << endl;

  return 0;
}

