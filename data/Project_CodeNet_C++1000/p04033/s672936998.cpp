#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll a, b;
  cin >> a >> b;
  if (a * b <= 0) {
    cout << "Zero" << endl;
  } else {
    if (a < 0 && (b - a) % 2 == 0) {
      cout << "Negative" << endl;
    } else {
      cout << "Positive" << endl;
    }
  }
  return 0;
}
