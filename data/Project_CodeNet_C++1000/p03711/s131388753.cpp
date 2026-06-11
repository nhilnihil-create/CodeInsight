#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)  

int main() {
  int x,y;
  cin >>x>>y;
  if (x == 2 || y == 2) cout << "No" <<endl;
  else if (y <= 7 || x >= 8) {
    if ((x + y) % 2 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  else {
    if (x + y % 2 == 0) cout << "No" << endl;
    else cout << "Yes" << endl;
  }
}