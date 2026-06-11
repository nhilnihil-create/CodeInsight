#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vll vector<ll>
#define rep(c, a, b) for(ll c=a;c<b;c++)
#define re(c, b) for(ll c=0;c<b;c++)
typedef long long int ll;
typedef long double ld;
#define vvv vector<vector<vector<long long int>>>
#define vvvl(a, b, c, d) vector<vector<vector<long long int>>>(a, vector<vector<long long int>>(b, vector<long long int> (c, d)));
using namespace std;

int main(int argc, char const *argv[]) {
  ll INF=10000000000,n, ma, mb;std::cin >> n >> ma >> mb;
  vvl d = vv(n, 3, 0, ll);
  re(i, n) std::cin >> d[i][0] >> d[i][1] >> d[i][2];
  vvv dp = vvvl(n+1, n*10+1, n*10+1, INF);
  dp[0][0][0] = 0;
  for(int i=1;i<=n;i++){
    for(int j=0;j<=n*10;j++){
      for(int k=0;k<=n*10;k++){
        dp[i][j][k] = dp[i-1][j][k];
        if(j<d[i-1][0]||k<d[i-1][1]) continue;
        dp[i][j][k] = min(dp[i][j][k], dp[i-1][j-d[i-1][0]][k-d[i-1][1]] + d[i-1][2]);
      }
    }
  }
  ll ans = INF;
  for(int i=1;i<=n*10;i++){
    for(int j=1;j<=n*10;j++){
      if(i%ma==0&&j%mb==0&&i/ma==j/mb){
        ans = min(ans, dp[n][i][j]);
      }
    }
  }
  std::cout << (ans>10000?-1:ans) << '\n';
  return 0;
}
