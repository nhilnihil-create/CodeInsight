#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
const int N  = 3e5 + 5;

int n, m, fen[N];
ii seg[N];

void add(int p, int val) {
  for (; p <= m; p += p & -p) fen[p] += val;
}

int sum(int p) {
  int res = 0;
  for (; p; p -= p & -p) res += fen[p];
  return res;
}

#define L first
#define R second
int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> seg[i].L >> seg[i].R;
  sort(seg + 1, seg + 1 + n, [](const ii &x, const ii &y){ return x.R - x.L < y.R - y.L; });

  int x = n, j = 1;
  for (int d = 1; d <= m; ++d) {
    while (j <= n && seg[j].R - seg[j].L + 1 < d) {
      add(seg[j].L, +1);
      add(seg[j].R + 1, -1);
      --x; ++j;
    }
    int ans = x;
    for (int i = d; i <= m; i += d)
      ans += sum(i);
    cout << ans << "\n";
  }
  return 0;
}