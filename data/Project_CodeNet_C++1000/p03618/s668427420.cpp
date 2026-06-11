#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  string s;
  cin >> s;
  int n = s.size();
  vector <int> cnt(26);
  for (int i = 0; i < n; ++i) ++cnt[s[i] - 'a'];
  ll ans = 0;
  for (int i = 0; i < 26; ++i) {
    ans += (ll)cnt[i] * (n - cnt[i]);
  }
  ans /= 2;
  cout << ans + 1 << '\n';
}

