#include <iostream>
#include <vector>
using namespace std;
#define in(v) v; cin >> v;
#define rep(i,n) for(int i=0;i<(n);++i)
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}

int dp[41][401][401];
int main() {
  int in(N); int in(M_a); int in(M_b);

  rep(i, 41) rep(j, 401) rep(k, 401) {
    dp[i][j][k] = 1e9;
  }
  dp[0][0][0] = 0;
  rep(i, N) {
    int in(A); int in(B); int in(C);
    rep(a, 401) rep(b, 401) {
      chmin(dp[i+1][a][b], dp[i][a][b]);
      if (a - A >= 0 && b - B >= 0)
        chmin(dp[i+1][a][b], dp[i][a-A][b-B] + C);
    }
  }
  int ans = 1e9;
  rep(i, 100) {
    if (M_a*(i+1) > 400 || M_b*(i+1) > 400)
      break;
    chmin(ans, dp[N][M_a*(i+1)][M_b*(i+1)]);
  }
  if (ans == 1000000000)
    cout << -1 << endl;
  else
    cout << ans << endl;

  return 0;
}
