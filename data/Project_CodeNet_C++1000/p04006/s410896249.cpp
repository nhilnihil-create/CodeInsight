#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
typedef long long int ll;
using namespace std;

int main(int argc, char const *argv[]) {
  int N, X;
  ll ans = 1000000000000000000;
  std::cin >> N >> X;
  std::vector<int> A(N);
  vvi dp = vv(N, N, 0, int);
  for(int i=0;i<N;i++) std::cin >> A[i];
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      dp[i][j] = (j==0?A[i]:min(dp[i][j-1], A[(N+(i-j))%N]));
    }
  }
  for(int i=0;i<N;i++) {
    ll reg = 0;
    for(int j=0;j<N;j++) reg += dp[j][i];
    ans = min(ans, reg + i * X);
  }
  std::cout << ans << '\n';
  return 0;
}
