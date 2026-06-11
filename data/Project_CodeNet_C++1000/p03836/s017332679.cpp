#include <bits/stdc++.h>
using namespace std;

string solve(char c, int n){
  string a = "";
  for(int i=0; i<n; i++)
    a += c;
  return a;
}

int main(){
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;

  int tate = ty - sy, yoko = tx - sx;
  
  string ans = "";
  ans += solve('U', tate);
  ans += solve('R', yoko);
  ans += solve('D', tate);
  ans += solve('L', yoko);

  ans += 'L';
  ans += solve('U', tate+1);
  ans += solve('R', yoko+1);
  ans += "DR";
  ans += solve('D', tate+1);
  ans += solve('L', yoko+1);
  ans += 'U';

  cout << ans << endl;

  return 0;
}
