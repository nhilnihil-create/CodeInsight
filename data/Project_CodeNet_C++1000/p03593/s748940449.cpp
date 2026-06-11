#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int h, w;
  cin >> h >> w;
  map<char, int> cnts;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      char c;
      cin >> c;
      cnts[c]++;
    }
  }

  int cnt4 = (h / 2) * (w / 2), cnt2 = 0, cnt1 = 0;
  if (h % 2 == 1 && w % 2 == 1) {
    cnt1 = 1;
  }

  if (h % 2 == 1) {
    cnt2 += w / 2;
  }

  if (w % 2 == 1) {
    cnt2 += h / 2;
  }

  // cout << cnt1 << ' ' << cnt2 << ' ' << cnt4 << '\n';

  bool ok = true;
  for (auto &p : cnts) {
    int cnt = p.second, c1, c2, c4;
    c4 = min(cnt / 4, cnt4);
    cnt -= 4 * c4;
    c2 = min(cnt2, cnt / 2);
    cnt -= 2 * c2;
    c1 = min(cnt, cnt1);
    cnt -= c1;

    cnt4 -= c4;
    cnt2 -= c2;
    cnt1 -= c1;

    // cout << p.first << ' ' << c1 << ' ' << c2 << ' ' << c4 << '\n';
    if (cnt4 < 0 || cnt2 < 0 || cnt1 < 0 || cnt != 0) {
      ok = false;
      break;
    }
  }

  if (ok) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
}