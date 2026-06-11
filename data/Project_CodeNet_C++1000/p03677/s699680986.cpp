#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<long long> s1(m + m), s2(m + m);
  int from;
  cin >> from;
  from--;
  long long tot = 0;
  for (int i = 1; i < n; i++) {
    int to;
    cin >> to;
    to--;
    from %= m;
    if (to < from) to += m;
    tot += to - from;
    if (from + 1 == to) {
      from = to;
      continue;
    }
    s1[from + 2]++;
    s1[to + 1]--;
    s2[to + 1] -= to - from - 1;
    from = to;
  }
  long long ans = tot;
  for (int i = 1; i < m + m; i++) s1[i] += s1[i - 1];
  for (int i = 0; i < m + m; i++) s2[i] += s1[i];
  for (int i = 1; i < m + m; i++) s2[i] += s2[i - 1];
  for (int i = 0; i < m; i++) ans = min(ans, tot - s2[i] - s2[i + m]);
  cout << ans << endl;
  return 0;
}