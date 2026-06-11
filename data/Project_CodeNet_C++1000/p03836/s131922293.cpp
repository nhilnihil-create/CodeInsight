#include <bits/stdc++.h>
using namespace std;

int main () {
  int x,y,X,Y;
  cin >> x >> y >> X >> Y;
  
  for (int i = 0; i < Y-y; i++) {
    cout << 'U';
  }
  for (int i = 0; i < X-x; i++) {
    cout << 'R';
  }
  for (int i = 0; i < Y-y; i++) {
    cout << 'D';
  }
  for (int i = 0; i < X-x; i++) {
    cout << 'L';
  }
  cout << 'L';
  for (int i = 0; i <= Y-y; i++) {
    cout << 'U';
  }
  for (int i = 0; i <= X-x; i++) {
    cout << 'R';
  }
  cout << 'D';
  cout << 'R';
  for (int i = 0; i <= Y-y; i++) {
    cout << 'D';
  }
  for (int i = 0; i <= X-x; i++) {
    cout << 'L';
  }
  cout << 'U';
  cout << endl;
}
   