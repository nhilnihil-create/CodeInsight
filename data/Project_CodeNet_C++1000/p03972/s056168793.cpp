#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int W, H;
ll p[100010], q[100010];
ll r[100010];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  cin >> W >> H;
  ll ans = 0;
  for (int i = 0; i < W; i++) {
    cin >> p[i];
    ans += p[i];
  }
  for (int i = 0; i < H; i++) {
    cin >> q[i];
    ans += q[i];
  }
  sort(p, p + W);
  sort(q, q + H);
  for (int i = 0; i < W; i++) {
    if (i == 0) r[i] = p[i];
    else r[i] = r[i - 1] + p[i];
  }
  for (int i = 0; i < H; i++) {
    int pos = lower_bound(p, p + W, q[i]) - p;
    ans += (W - pos) * q[i];
    if (pos - 1 >= 0) ans += r[pos - 1];
  }
  cout << ans << endl;

  return 0;
}