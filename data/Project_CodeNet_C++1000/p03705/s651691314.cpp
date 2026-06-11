#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;

  if (a > b) {
    cout << 0 << endl;
    return 0;
  }

  if (n == 1) {
    if (a != b) {
      cout << 0 << endl;
      return 0;
    } else {
      cout << 1 << endl;
      return 0;
    }
  }

  cout << (n-2) * (b-a) + 1 << endl;
  return 0;
}