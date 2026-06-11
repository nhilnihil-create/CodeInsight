#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <functional>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll k;
  cin >> k;
  k++;
  function<vector<int>(ll)> solve = [&] (ll k) {
    if (k == 1) {
      return vector<int>{};
    } else if (k % 2 == 0) {
      auto a = solve(k / 2);
      int ids = a.size();
      a.push_back(ids);
      return a;
    } else {
      auto a = solve(k - 1);
      int ids = a.size();
      a.insert(a.begin(), ids);
      return a;
    }
  };
  auto ok = solve(k);
  cout << 2 * ok.size() << '\n';
  for (int i = 0; i < (int) ok.size(); i++) cout << i + 1 << ' ';
  for (int x : ok) cout << x + 1 << ' ';
  cout << '\n';
}
