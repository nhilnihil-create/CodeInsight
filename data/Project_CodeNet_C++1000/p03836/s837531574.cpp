#include <iostream>
using namespace std;

int main(){
  int tx, ty, x, y;
  cin >> tx >> ty >> x >> y;
  int dx = x-tx;
  int dy = y-ty;
  for(int i =0; i < dy; ++i) cout << 'U';
  for(int i =0; i < dx; ++i) cout << 'R';
  for(int i =0; i < dy; ++i) cout << 'D';
  for(int i =0; i < dx; ++i) cout << 'L';
  cout << 'L';
  for(int i =0; i < dy+1; ++i) cout << 'U';
  for(int i =0; i < dx+1; ++i) cout << 'R';
  cout << 'D' << 'R';
  for(int i =0; i < dy+1; ++i) cout << 'D';
  for(int i =0; i < dx+1; ++i) cout << 'L';
  cout << 'U' << endl;
  return 0; 
}