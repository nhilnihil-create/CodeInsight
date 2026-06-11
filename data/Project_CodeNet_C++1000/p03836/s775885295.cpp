#include <bits/stdc++.h>
using namespace std;

int main(){
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  
  string ans = "", up = "", down = "", left = "", right = "";
  for(int i = 0; i < ty - sy; i++){
    up += 'U';
    down += 'D';
  }
  for(int i = 0; i < tx - sx; i++){
    left += 'L';
    right += 'R';
  }
  
  ans += up + right + down + left + 'L' + 'U' + up + 'R' + right + 'D';
  ans += "RD" + down + left + "LU";
  
  cout << ans << endl;
}