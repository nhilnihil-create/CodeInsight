#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  a = a == 1 ? 14 : a;
  b = b == 1 ? 14 : b;
  cout << (a == b ? "Draw" : (a > b ? "Alice" : "Bob")) << endl;
}