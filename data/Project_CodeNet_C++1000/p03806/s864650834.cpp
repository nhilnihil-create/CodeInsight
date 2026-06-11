#include<bits/stdc++.h>
using namespace std;

const int MAX = 500, INF = 1e8;

int dp[MAX][MAX];

int main(){
  int N, Ma, Mb; cin >> N >> Ma >> Mb;
  for(int i = 0; i < MAX; i++){
    for(int j = 0; j < MAX; j++){
      dp[i][j] = INF;
    }
  }
  dp[0][0] = 0;
  
  int am = 0, bm = 0;
  for(int i = 0; i < N; i++){
    int a, b, c; cin >> a >> b >> c;
    for(int j = am; j >= 0; j--){
      for(int k = bm; k >= 0; k--){
        if(dp[j][k] < INF)
          dp[j + a][k + b] = min(dp[j + a][k + b], dp[j][k] + c);
      }
    }
    am += a; bm += b;
  }
  
  int mul = 1, ans = INF;
  while(Ma * mul <= am && Mb * mul <= bm){
    ans = min(ans, dp[Ma*mul][Mb*mul]);
    mul++;
  }
  cout << (ans < INF?ans:-1) << endl;
}