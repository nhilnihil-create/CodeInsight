#include <bits/stdc++.h>
using namespace std;

int main() {
  int sx,sy,tx,ty; cin >> sx >> sy >> tx >> ty;
  int x = tx - sx, y = ty - sy;
  
  for (int i =0; i<y; i++) cout << 'U';
  for (int i =0; i<x; i++) cout << 'R';
  for (int i =0; i<y; i++) cout << 'D';
  for (int i =0; i<x; i++) cout << 'L';
  cout << 'L';
  for (int i =0; i<y+1; i++) cout << 'U';
  for (int i =0; i<x+1; i++) cout << 'R';
  cout << 'D'; cout << 'R';
  for (int i =0; i<y+1; i++) cout << 'D';
  for (int i =0; i<x+1; i++) cout << 'L';
  cout << 'U';
}