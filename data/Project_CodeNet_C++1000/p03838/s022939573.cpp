#include <bits/stdc++.h>
using namespace std;

int main(){
  int x, y;  cin >> x >> y;
  int d[] = {1, 0, 0, 1, 1}, ans = 1e9+1e5; // d[]は前で・後ろで反転をする・しないの2*2の組み合わせを作るための
  for(int i=0; i<4; i++){
    int xc = x;
    if(d[i])  xc = -xc;  // 前の反転

    if(xc > y && d[i+1] == 0)  continue; // 後ろで反転しないのにxcの方が大きい場合:xc=5 y=2
    xc += abs(abs(y) - abs(x));

    if(d[i+1])  xc = -xc; // 後ろの反転

    if(xc == y)  ans = min(ans, d[i]+d[i+1]+abs(abs(y) - abs(x)));
  }


  cout << ans << endl;
  return 0;
}
