#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  ll sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;

  ll dx = tx - sx;
  ll dy = ty - sy;
  for (long long i = 0; i < dy; i++) {
    cout << 'U';
  }
  for (long long i = 0; i < dx; i++) {
    cout << 'R';
  }
  for (long long i = 0; i < dy; i++) {
    cout << 'D';
  }
  for (long long i = 0; i < dx; i++) {
    cout << 'L';
  }
  cout << 'L';
  dy++;
  dx++;
  for (long long i = 0; i < dy; i++) {
    cout << 'U';
  }
  for (long long i = 0; i < dx; i++) {
    cout << 'R';
  }
  cout << 'D';
  cout << 'R';
  for (long long i = 0; i < dy; i++) {
    cout << 'D';
  }
  for (long long i = 0; i < dx; i++) {
    cout << 'L';
  }
  cout << 'U';
}
