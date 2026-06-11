#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repr(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(x, c) for (auto&& x : (c))
#define updatemax(t, v) ((t) = std::max((t), (v)))
#define updatemin(t, v) ((t) = std::min((t), (v)))
#define endl _endl
const char _endl = (cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout.precision(16), '\n');

void solve(long long H, long long W, long long N, std::vector<long long> a) {
  vector<vector<ll>> ans(H, vector<ll>(W));
  ll h = 0, w = 0, c = 0;
  while (w < W) {
    while (a[c] <= 0) ++c;
    ans[h][w] = c;
    --a[c];
    ll dh = w % 2 ? -1 : 1;
    if (h + dh < 0 || h + dh >= H) {
      ++w;
    } else {
      h += dh;
    }
  }
  rep(h, H) {
    rep(w, W) cout << ans[h][w] + 1 << ' ';
    cout << endl;
  }
}

int main() {
  long long H;
  scanf("%lld", &H);
  long long W;
  scanf("%lld", &W);
  long long N;
  scanf("%lld", &N);
  std::vector<long long> a(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &a[i]);
  }
  solve(H, W, N, std::move(a));
}
