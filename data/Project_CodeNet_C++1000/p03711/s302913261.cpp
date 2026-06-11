#include <bits/stdc++.h>
using namespace std;

int g(int n) {
  if (n == 2) return 3;
  else if (n == 4 || n == 6 || n == 9 || n == 11 ) return 2;
  else return 1;
}

int main() {
  int x, y;
  cin >> x >> y;
  cout << (g(x) == g(y) ? "Yes" : "No") << endl;
}