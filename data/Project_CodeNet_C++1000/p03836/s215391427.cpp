#include<bits/stdc++.h>
using namespace std;

int sx, sy, tx, ty;

int main(void){
  cin >> sx >> sy >> tx >> ty;
  int p, q;
  p = tx-sx;
  q = ty-sy;
  for(int i = 0; i < q; i++) cout << 'U';
  for(int i = 0; i < p; i++) cout << 'R';
  for(int i = 0; i < q; i++) cout << 'D';
  for(int i = 0; i < p; i++) cout << 'L';
  cout << 'L';
  for(int i = 0; i < q+1; i++) cout << 'U';
  for(int i = 0; i < p+1; i++) cout << 'R';
  cout << 'D';
  cout << 'R';
  for(int i = 0; i < q+1; i++) cout << 'D';
  for(int i = 0; i < p+1; i++) cout << 'L';
  cout << 'U';
  cout << endl;
  return 0;
}
