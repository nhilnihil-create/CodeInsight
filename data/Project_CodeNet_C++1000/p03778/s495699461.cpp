#include <bits/stdc++.h>
using namespace std;

int main() {
  int W, a, b;
  cin >> W >> a >> b;
  if(b+W < a) {
    cout << a - b - W;
  }
  else if(a+W < b) {
    cout << b - a - W;
  }
  else {
    cout << "0";
  }
}
