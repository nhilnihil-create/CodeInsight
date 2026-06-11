#include <iostream>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  if (x == 1 || x == 2*n-1) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
    if (n == 2) {
      cout << 1 << endl;
      cout << 2 << endl;
      cout << 3 << endl;
    } else {
      if (x == 2) {
        int cur = 5;
        for (int i=1; i<=2*n-1; i++) {
          if (i == n-1) cout << x+1 << endl;
          else if (i == n) cout << x << endl;
          else if (i == n+1) cout << x-1 << endl;
          else if (i == n+2) cout << x+2 << endl;
          else cout << cur++ << endl;
        }
      } else {
        int cur = 1;
        if (cur == x-2) cur = x+2;
        for (int i=1; i<=2*n-1; i++) {
          if (i == n-1) cout << x-1 << endl;
          else if (i == n) cout << x << endl;
          else if (i == n+1) cout << x+1 << endl;
          else if (i == n+2) cout << x-2 << endl;
          else { cout << cur++ << endl; if (cur == x-2) cur = x+2;}
        }
      }
    }
  }
  return 0;
}
