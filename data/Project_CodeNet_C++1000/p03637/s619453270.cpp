#include <iostream>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;

int main(){
  int N;
  cin >> N;
  int a[N];
  rep(i, N)
    cin >> a[i];
  //ここまで入力

  //2で0,1,2(以上)回割り切れる整数の数を格納する
  int c0 = 0, c1 = 0, c2 = 0;
  rep(i, N){
    int count = 0;
    //2で何回割り切れるか
    while(a[i] != 0){
      if(a[i]%2 == 0){
	a[i] /= 2;
	count++;
      }
      //奇数になったら抜ける
      else
	break;
    }
    //カウント
    if(count == 0)
      c0++;
    else if(count == 1)
      c1++;
    else
      c2++;
  }

  //2で1回割り切れるものは左から並べる
  if(c1 > 0)
    //あとは，0回割り切れるものと2回割り切れるものを交互に並べる
    //0回割り切れるものの方が多ければ題意を満たさない
    if(c0 > c2)
      cout << "No" << endl;
    else 
      cout << "Yes" << endl;
  //2で1回割り切れるものがなければ
  else
    //2で2回以上割り切れるものの両端に0回割り切れるものを配置していけばよい
    if(c0 <= c2+1)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;

  return 0;
}
