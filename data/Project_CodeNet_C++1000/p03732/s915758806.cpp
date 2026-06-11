#include <cmath>
#include <iostream>
#include <vector>

long long dp[109][109][309];

int main(){
  long long N,W;
  std::cin >> N >> W;

  std::vector<long long> w_arr(N), v_arr(N);
  for(int i = 0; i < N; i++) std::cin >> w_arr[i] >> v_arr[i];

  for(int n = 0; n < N; n++){
    for(int i = 1; i <= n+1; i++){
      for(int w = 0; w < 3*N; w++){
        if(w-(w_arr[n]-w_arr[0]) < 0) dp[n+1][i][w] = dp[n][i][w];
        else{
          dp[n+1][i][w] = std::max(dp[n][i][w], dp[n][i-1][w-(w_arr[n]-w_arr[0])]+v_arr[n]);
        }
      }
    }
  }

  long long ans = 0;
  for(int n = 0; n <= N; n++){
    long long w = W-n*w_arr[0];
    if(w < 0) continue;
    if(w > 3*N) w = 3*N-1;
    ans = std::max(ans, dp[N][n][w]);
  }

  std::cout << ans << std::endl;

  return 0;
}

