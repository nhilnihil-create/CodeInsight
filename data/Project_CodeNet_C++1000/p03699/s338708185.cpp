#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i, n)for(int i=0; i<n; i++)

int main(){
  int N;
  cin >> N;
  int s[N];
  rep(i, N)
    cin >> s[i];
  //入力終了

  //大きい順に
  sort(s, s+N);

  //s[]の総和
  int sum = 0;
  rep(i, N)
    sum += s[i];

  //既に10の倍数でなければ終了
  if(sum%10 != 0){
    cout << sum << endl;
    return 0;
  }

  //小さい数字から順に引いていく
  rep(i, N){
    sum -= s[i];
    //10の倍数でなければ終了
    if(sum%10 != 0){
      cout << sum <<endl;
      return 0;
    }
    //元に戻す
    sum += s[i];
  }

  //上で終わらなければ元々が10の倍数だった
  cout << 0 << endl;

  return 0;
}
