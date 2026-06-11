#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector < int > cnt(maxn, 0);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++cnt[x];
  }
  int bad = 0;
  for (int i = 0; i < maxn; ++i) {
    if (cnt[i])
      bad += cnt[i] - 1;
  }
  cout << n - 2 * ((bad + (bad % 2)) / 2) << '\n';
}