/**
 *   author: r1933
**/
#include "bits/stdc++.h"

using namespace std;

#define all(x) x.begin(), x.end()
using i64 = long long;

constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  cout << (s.substr(0, 4) == "YAKI" ? "Yes" : "No") << "\n";
  return 0;
}
