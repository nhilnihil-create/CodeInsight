#include <bits/stdc++.h>
using namespace std;

int abs(int x) {
  if(x >= 0) {
    return x;
  }
  else {
    return -1 * x;
  }
}

int main() {
  int x, a, b;
  cin >> x >> a >> b;
  int A = abs(a - x);
  int B = abs(b - x);
  if(A < B) {
    cout << "A" << endl;
  }
  else {
    cout << "B" << endl;
  }
}