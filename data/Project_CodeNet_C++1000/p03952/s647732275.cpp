#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  if (x == 1 || x == 2*n-1) {
    cout << "No" << endl;
    return 0;
  }
  if (x == 2) {
    cout << "Yes" << endl;
    int d = 3;
    for (int i = 1; i <= 2*n-1; ++i) {
      if (i == n-1) cout << x;
      else if (i == n) {
        cout << 1;
      }
      else {
        cout << d;
        ++d;
      }
      cout << endl;
    }
    return 0;
  }
  if (x == 2*n-2) {
    cout << "Yes" << endl;
    int d = 1;
    for (int i = 1; i <= 2*n-1; ++i) {
      if (i == n-1) cout << x;
      else if (i == n) {
        cout << 2*n-1;
      }
      else {
        cout << d;
        ++d;
      }
      cout << endl;
    }
    return 0;
  }
  cout << "Yes" << endl;
  int d = 3;
  for (int i = 1; i <= 2*n-1; ++i) {
    if (i == n-2) cout << 2*n-1;
    else if (i == n-1) cout << 1;
    else if (i == n) cout << x;
    else if (i == n+1) cout << 2*n-2;
    else if (i == n+2) cout << 2;
    else {
      if (d == x) ++d;
      cout << d;
      ++d;
    }
    cout << endl;
  }
}