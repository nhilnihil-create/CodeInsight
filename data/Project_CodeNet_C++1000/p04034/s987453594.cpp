#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i, n)for(int i=0; i<n; i++)

int main(){
  int N, M;
  cin >> N >> M;
  int x[M], y[M];
  rep(i, M){
    cin >> x[i] >> y[i];
    x[i]--; y[i]--;
  }
  // 入力終了

  // 箱iに赤ボールが入っている可能性があるかどうか
  bool red[N];
  // 箱iにあるボールの総数
  int ball_num[N];

  // 赤ボールは初め箱1のみに入っている
  // また，箱iの中のボールは初め1つだけ
  rep(i, N){
    red[i] = false;
    ball_num[i] = 1;
  }
  red[0] = true;

  rep(i, M){
    // 箱x[i]に赤ボールがあれば，箱y[i]にボールを移せる
    if(red[x[i] ] )
      red[y[i] ] = true;

    // ボールを箱x[i]からy[i]に移す
    ball_num[x[i] ]--;
    ball_num[y[i] ]++;

    // 箱の中身が空なら，そこに赤ボールは存在しない
    if(ball_num[x[i] ] == 0)
      red[x[i] ] = false;
  }

  // 赤ボールが入っている可能性のある箱の数を数える
  int ans = 0;
  rep(i, N)
    if(red[i] )
      ans++;

  // 解答
  cout << ans << endl;

  return 0;
}
