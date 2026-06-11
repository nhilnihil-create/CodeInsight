#include <iostream>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;

int main(){
  long long x;
  cin >> x;
  //ここまで入力

  long long ans = 0;
  //6点，5点を繰り返し行えばよい
  //1周期が11点なので，何周行えるかを計算する
  //1周で2回の操作を要することも考慮する
  ans += x/11*2;

  //11点の周期を限界まで行った後，何点残っているか
  x %= 11;

  //残りが0点ならそれが答え
  if(x == 0)
    cout << ans << endl;
  //残りが6点以下ならあと1回の操作で終了
  else if(x <= 6)
    cout << ans + 1 << endl;
  //7点以上あるなら，2回の操作を要する
  else
    cout << ans + 2 << endl;

  return 0;
}
