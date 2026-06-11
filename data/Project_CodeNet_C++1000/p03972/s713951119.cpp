#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll W, H;
  cin >> W >> H;
  vector<pair<ll, int>> pq(W + H);
  for (int i = 0; i < W; i++) {
    int p;
    cin >> p;
    pq[i] = make_pair(p, 0);
  }
  for (int i = 0; i < H; i++) {
    int q;
    cin >> q;
    pq[W + i] = make_pair(q, 1);
  }
  sort(pq.begin(), pq.end());

  ll cnt0 = 0, cnt1 = 0;
  ll ans = 0;
  for (int i = 0; i < H + W; i++) {
    if (pq[i].second == 0) {
      cnt0++;
      ans += (H + 1 - cnt1) * pq[i].first;
    } else {
      cnt1++;
      ans += (W + 1 - cnt0) * pq[i].first;
    }
  }
  cout << ans << endl;
}