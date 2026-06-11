#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1000000007;
const int INF = 1e15;
using Graph = vector<vector<int>>;

signed main(){
  int N, A;
  cin >> N >> A;
  vector<int> X(N);
  for( int i = 0; i < N; i++ ){
    cin >> X.at(i);
    X.at(i) -= A;
  }

  //Xの合計が0になるような組み合わせを求める
  int mid = 3000;
  vector<vector<int>> dp(N+10, vector<int>(7000));
  dp[0][mid] = 1;

  for( int i = 0; i < N; i++ ){ //i番目までの数字を使って
    for( int j = -2500; j <= 2500; j++ ){
      //i番目の数字を使わない場合
      dp[i+1][mid+j] += dp[i][mid+j];
      //i番目の数字を使う場合
      dp[i+1][j+mid+X.at(i)] += dp[i][mid+j];
    }
  }
  
  cout << dp[N][mid] -1 << endl;
 }
