#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int sx, sy, gx, gy;
  cin >> sx >> sy >> gx >> gy;
  for(int i = 0; i < gy - sy; i++) cout << 'U';
  for(int i = 0; i < gx - sx; i++) cout << 'R';
  cout << 'U';
  for(int i = 0; i <= gx - sx; i++) cout << 'L';
  for(int i = 0; i <= gy - sy; i++) cout << 'D';
  cout << 'R';
  for(int i = 0; i < gx - sx; i++) cout << 'R';
  for(int i = 0; i < gy - sy; i++) cout << 'U';
  cout << 'R';
  for(int i = 0; i <= gy - sy; i++) cout << 'D';
  for(int i = 0; i <= gx - sx; i++) cout << 'L';
  cout << 'U';
}