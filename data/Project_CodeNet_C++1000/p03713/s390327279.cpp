#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll diff(vector<ll> S) {
  sort(S.begin(), S.end());
  return S[2] - S[0];
}

int main() {
  ll H, W;
  cin >> H >> W;
  ll ans = H * W;
  vector<ll> S(3);

  for (int i = 1; i <= H - 1; i++) {
    S[0] = i * W;
    if (H - i >= 2) {
      S[1] = (H - i) / 2 * W;
      S[2] = (H - i - (H - i) / 2) * W;
      ans = min(ans, diff(S));
    }
    S[1] = (H - i) * (W / 2);
    S[2] = (H - i) * (W - W / 2);
    ans = min(ans, diff(S));
  }

  for (int i = 1; i <= W - 1; i++) {
    S[0] = H * i;
    if (W - i >= 2) {
      S[1] = H * ((W - i) / 2);
      S[2] = H * (W - i - (W - i) / 2);
      ans = min(ans, diff(S));
    }
    S[1] = (H / 2) * (W - i);
    S[2] = (H - H / 2) * (W - i);
    ans = min(ans, diff(S));
  }
  cout << ans << endl;
}