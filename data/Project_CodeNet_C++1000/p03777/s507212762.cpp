#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main() {
  string a, b;
  cin >> a >> b;
  int x = a == "H" ? 1 : 0, y = b == "H" ? 1 : 0;
  if (x == 0) y ^= 1;
  
  cout << (y ? "H" : "D") << endl;
  return 0;
}
