#include <bits/stdc++.h>
using namespace std;

int main(){
  int sx, sy, tx, ty;
  int ver, hol;
  cin >> sx >> sy >> tx >> ty;
  ver = ty - sy;
  hol = tx - sx;
  for(int i = 0; i < ty - sy; i++){
    cout << "U";
  }
  for(int i = 0; i < tx - sx; i++){
    cout << "R";
  }
  for(int i = 0; i < ty - sy; i++){
    cout << "D";
  }
  for(int i = 0; i < tx - sx; i++){
    cout << "L";
  }
  //１周おわり
  cout << "L";
  for(int i = 0; i < ver + 1; i++){
    cout << "U";
  }
  for(int i = 0; i < hol+1; i++){
    cout << "R";
  }
  cout << "D";
  cout << "R";
  for(int i = 0; i < ver+1; i++){
    cout << "D";
  }
  for(int i = 0; i < hol+1; i++){
    cout << "L";
  }
  cout << "U";
}
  