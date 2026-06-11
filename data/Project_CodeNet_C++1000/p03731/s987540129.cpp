#include <iostream>
using namespace std;

int main() {
  int n, w, t, p = 0, s = 0;
  cin >> n >> w;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    if (p + w <= t) {
      s += w;
      p = t;
    } else {
      s += t - p;
      p = t;
    }
  }
  s += w;
  cout << s << '\n';
  return 0;
}