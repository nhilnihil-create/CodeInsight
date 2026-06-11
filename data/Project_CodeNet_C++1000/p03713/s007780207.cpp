#include <bits/stdc++.h>
using namespace std;

pair<long, long> divide(long h, long w) {
  long s = h * w;
  if (s % 2 == 0) return make_pair(s / 2, s / 2);
  if (h > w) swap(h, w);
  long s1 = h * (w / 2);
  return make_pair(s1, s - s1);
}

int main() {
  long h, w, ans = 1l << 62;
  cin >> h >> w;
  if (h % 3 == 0 || w % 3 == 0) {
    cout << 0 << endl;
    return 0;
  }
  for (long i = h / 3 - 1; i <= h / 3 + 2; i++) {
    long s = i * w, s1 = divide(h - i, w).first, s2 = divide(h - i, w).second;
    ans = min(ans, max(abs(s - s1), max(abs(s1 - s2), abs(s - s2))));
  }
  for (long i = w / 3 - 1; i <= w / 3 + 2; i++) {
    long s = i * h, s1 = divide(w - i, h).first, s2 = divide(w - i, h).second;
    ans = min(ans, max(abs(s - s1), max(abs(s1 - s2), abs(s - s2))));
  }
  cout << ans << endl;
}
