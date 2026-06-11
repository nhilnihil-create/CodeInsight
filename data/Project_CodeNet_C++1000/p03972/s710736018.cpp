#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int W, H;
int p[100010], q[100010];
ll cumq[100010];

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
  for (int i = 0; i < H; i++) {
    cumq[i + 1] = cumq[i] + q[i];
  }
  for (int i = 0; i < W; i++) {
    int pos = upper_bound(q, q + H, p[i]) - q;
    ans += cumq[pos] + (ll)p[i] * (H - pos);
  }
  cout << ans << endl;

  return 0;
}