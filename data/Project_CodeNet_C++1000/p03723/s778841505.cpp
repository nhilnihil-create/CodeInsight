#include <iostream>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  
  int count=0;
  int aa=a, bb=b, cc=c;
  int aa0, bb0, cc0;
  do {
    //奇数になったら終了
    if (aa%2 || bb%2 || cc%2)	{
      cout << count << endl;
      return 0;
    }
    //交換
    aa0=aa, bb0=bb, cc0=cc;
    aa = bb0/2 + cc0/2;
    bb = aa0/2 + cc0/2;
    cc = aa0/2 + bb0/2;
    //元に戻ったら無限
    if (aa==a && bb==b && cc==c) {
      cout << -1 << endl;
      return 0;
    }
    count++;
  } while(1);
  
  cout << count << endl;
  return 0;
}