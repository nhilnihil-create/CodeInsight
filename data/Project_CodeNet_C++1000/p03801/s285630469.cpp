#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;

int n;
ll res[N];
vector<pair<int, int>> V;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1, a; i <= n; ++i) {
    cin >> a;
    V.emplace_back(a, i);
  }
  V.emplace_back(0, n + 1);
  sort(V.begin(), V.end(), greater<pair<int, int>>());

  int cura = V[0].first, minind = V[0].second, curpos = 0, cnt = 1;
  while (cura > 0) {
    while (curpos + 1 < n && V[curpos + 1].first == cura) {
      ++curpos; ++cnt;
      minind = min(minind, V[curpos].second);
    }
    res[minind] += 1LL * (cura - V[curpos + 1].first) * cnt;
    cura = V[curpos + 1].first;
  }
  for (int i = 1; i <= n; ++i) cout << res[i] << "\n";
  return 0;
}