#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <numeric>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;
int dp[40][401][401];
int a[40];
int b[40];
int c[40];
int main(){
  int N;
  int M_a;
  int M_b;
  cin >> N >> M_a >> M_b;
  for(int i = 0; i < N; i++){
    cin >> a[i] >> b[i] >> c[i];
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j <= 400; j++){
      for(int k = 0; k <= 400; k++){
        dp[i][j][k] = INT_MAX;
      }
    }
  }

  dp[0][0][0] = 0;
  dp[0][a[0]][b[0]] = c[0];
  
  for(int i = 1; i < N; i++){
    for(int j = 0; j <= 400; j++){
      for(int k = 0; k <= 400; k++){
        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
        if(j >= a[i] && k >= b[i] && dp[i - 1][j - a[i]][k - b[i]] != INT_MAX){
          dp[i][j][k] = min(dp[i][j][k], c[i] + dp[i - 1][j - a[i]][k - b[i]]);
        }
      }
    }
  }

  int ans = INT_MAX;
  for(int i = 1; i <= 400; i++){
    for(int j = 1; j <= 400; j++){
      if(i % M_a == 0 && j % M_b == 0 && i / M_a == j / M_b){
        ans = min(ans, dp[N - 1][i][j]);
      }
    }
  }
  if(ans == INT_MAX){
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
