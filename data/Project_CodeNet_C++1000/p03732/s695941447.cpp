#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(){
  int N, W;
  cin >> N >> W;
  vector<int> w(N), v(N);
  rep(i, N)
    cin >> w[i] >> v[i];
  vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(N+1, vector<int>(500)));
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=i; j++) {
      rep(k, 500) {
        chmax(dp[i][j][k], dp[i-1][j][k]);
        if(k-(w[i-1]-w[0]) >= 0)
          chmax(dp[i][j][k], dp[i-1][j-1][k-(w[i-1]-w[0])]+v[i-1]);
      }
    }
  }
  int ans = 0;
  rep(i, N+1) rep(j, 500) {
    if((ll)j+w[0]*i <= W)
      chmax(ans, dp[N][i][j]);
  }
  cout << ans << endl;
  return 0;
}