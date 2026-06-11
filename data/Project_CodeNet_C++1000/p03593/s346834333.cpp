#include <algorithm>
#include <bitset>
#include <boost/rational.hpp>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (int64_t)(n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

int main() {
  int H, W;
  cin >> H >> W;

  vector<int> cnt(26, 0);
  rep(i, H) {
    string s;
    cin >> s;
    rep(i, W) { cnt[s[i] - 'a']++; }
  }

  int p1 = 0, p2 = 0, p4 = 0;
  rep(i, 26) {
    p4 += cnt[i] / 4;
    p2 += cnt[i] % 4 / 2;
    p1 += cnt[i] % 2;
  }

  int q1 = (H % 2) * (W % 2);
  int q2 = (H % 2) * W / 2 + (W % 2) * H / 2;
  int q4 = (H / 2) * (W / 2);

  cerr << p1 << " " << p2 << " " << p4 << "\n";
  cerr << q1 << " " << q2 << " " << q4 << "\n";

  if (p4 >= q4 && (p4 - q4) * 2 + p2 >= q2) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  return 0;
}