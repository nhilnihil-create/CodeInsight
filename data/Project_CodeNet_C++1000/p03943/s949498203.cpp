#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if ((a + b == c) % 2 || (b + c == a) % 2 || (c + a == b) % 2) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
