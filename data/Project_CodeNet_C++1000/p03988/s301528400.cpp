#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a, cnt;

bool solve();

int main() {
  cin >> n;
  a.resize(n);
  for (auto &p : a) cin >> p;
  cout << (solve() ? "Possible" : "Impossible") << endl;
  return 0;
}

bool solve() {
  if (n == 2) return 1;
  sort(a.begin(), a.end(), greater<int>());
  if (a[0] != a[1]) return 0;
  if (a[n - 1] != (a[0] + 1) / 2) return 0;
  cnt.assign(n + 1, 0);
  for (auto p : a) ++cnt[p];
  if ((a[0] % 2 == 0) && cnt[a[n - 1]] != 1) return 0;
  if (a[0] & 1 && cnt[a[n - 1]] != 2) return 0;
  for (int i = a[n - 1] + (a[0] % 2 == 0); i <= a[0]; ++i)
    if (cnt[i] < 2) return 0;
  return 1;
}
