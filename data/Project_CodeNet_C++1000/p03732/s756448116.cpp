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
//constexpr int inf = 1LL<<60;

int dp[101][101][301];

signed main() {
  int n, maxw;
  cin >> n >> maxw;

  vi w(n), v(n);
  rep(i, 0, n) cin >> w[i] >> v[i];

  int w0 = w[0];
  rep(i, 0, n) w[i] -= w0;

  rep(i, 0, n) rep(j, 0, i+1) rep(k, 0, 301) {
    chmax(dp[i+1][j][k], dp[i][j][k]);

    int ww = w0*j + k;
    if(ww <= maxw) {
      chmax(dp[i+1][j+1][k+w[i]], dp[i][j][k]+v[i]);
    }
  }

  int ans = 0;
  rep(j, 0, 101) rep(k, 0, 301) {
    int ww = w0*j + k;
    if(ww <= maxw) {
      chmax(ans, dp[n][j][k]);
    }
  }

  cout << ans << endl;

  return 0;
}

