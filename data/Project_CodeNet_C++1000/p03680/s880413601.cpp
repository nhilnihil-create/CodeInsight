#include <iostream>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;

int main(void){
  int N;
  cin >> N;
  int a[N];
  rep(i, N)
    cin >> a[i];
  //入力終わり

  int ans = 0;

  //既に押したボタンかどうか
  bool pushed[N];
  rep(i, N)
    pushed[i] = false;

  int now = 0;
  while(now != 1){
    //押したボタンに戻ったら無限ループする
    if(pushed[now] == true){
      cout << -1 << endl;
      return 0;
    }
    //押したよマーク
    pushed[now] = true;
    ans++;
    //次のボタンへ
    now = a[now]-1;
  }

  //解答
  cout << ans << endl;
    
  return 0;
}
