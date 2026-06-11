#include <bits/stdc++.h>
using namespace std;

int main(){
  int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
  int delx = abs(tx - sx);
  int dely = abs(ty - sy);
  for(int cnt = 0; cnt <= 1; cnt++){
    if(cnt == 1) cout << "DR";
    for(int i = 0; i < delx; i++){
      cout << 'R';
    }
    for(int i = 0; i < dely; i++){
      cout << 'U';
    }
    if(cnt == 1) cout << "ULUL";
    for(int i = 0; i < delx; i++){
      cout << 'L';
    }
    for(int i = 0; i < dely; i++){
      cout << 'D';
    }
    if(cnt == 1) cout << "DR" <<endl;
  }
}