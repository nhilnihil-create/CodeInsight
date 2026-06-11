#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll x, a, b;
  cin >> x >> a >> b;
  int exp = a - b;
  if (exp < 0) {
    cout << (-exp > x ? "dangerous" : "safe") << '\n';
  } else {
    cout << "delicious" << '\n';
  }
}
