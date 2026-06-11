#include <cmath>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <set>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;

int k;
int n;

vector<pair<int, int>> a;

void input() {
  cin >> k >> n;

  a.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;

    a[i].second = i;
  }
}

int ans(vi& b) {
  int ans = 0;

  for (int i = 1, cur = 0; i < k; ++i) {
    if (b[i] == b[i - 1]) {
      ++cur;
    } else {
      cur = 0;
    }

    ans = max(ans, cur);
  }

  return ans;
}

void solve() {
  set<pair<int, int>, greater<pair<int, int>>> cur(a.cbegin(), a.cend());

  vi b;

  while (!cur.empty()) {
    auto it1 = cur.cbegin();

    b.push_back(it1->second);

    int val1 = it1->first;

    cur.erase(it1);

    if (cur.empty()) {
      if (val1 > 1)
        cur.emplace(val1 - 1, b.back());

      continue;
    }

    auto it2 = cur.cbegin();

    b.push_back(it2->second);

    int val2 = it2->first;

    cur.erase(it2);

    if (val1 > 1)
      cur.emplace(val1 - 1, b[b.size() - 2]);

    if (val2 > 1)
      cur.emplace(val2 - 1, b.back());
  }

  cout << ans(b) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cout.precision(16);
  cout << fixed;

  int _times = 1;

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);

  cin >> _times;
#endif

  while (_times--) {
    input();
    solve();
  }
}
