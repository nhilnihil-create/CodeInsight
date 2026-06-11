#include <iostream>
using namespace std;
using ll = long long;
ll n, a, c[2], s[2];
int main() {
  cin >> n;
  for (int i = 0; i != n; ++i) {
    cin >> a;
    for (int j : {0, 1}) {
      s[j] += a;
      auto p = 1 - (i + j) % 2 * 2;
      if (s[j] * p <= 0) {
        c[j] += abs(p - s[j]);
        s[j] = p;
      }
    }
  }
  cout << min(c[0], c[1]) << endl;
}
