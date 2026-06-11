#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main() {
  int a, b;
  cin >> a >> b;
  if ((a % 3 == 0) || (b % 3 == 0) || ((a+b) % 3 == 0)) {
    cout << "Possible\n";
  } else {
    cout << "Impossible\n";
  }
  return 0;
}
