#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1LL << 62;
const double PI = acos(-1);
const double eps = 1e-10;

int main() {
  ll h, w;
  cin >> h >> w;
  map<char, int> mp;
  char a;
  rep(i, h) rep(j, w) cin >> a, mp[a]++;
  ll cnt4 = 0, cnt2 = 0, cnt1 = 0;
  for (auto x : mp) {
    if (x.second % 4 == 0) {
      cnt4++;
    } else if (x.second % 2 == 0) {
      cnt2++;
    } else {
      cnt1++;
    }
  }
  // cerr << cnt4 << " " << cnt2 << " " << cnt1 << endl;

  if ((h % 2 == 1) && (w % 2 == 1)) {
    cout << (cnt1 <= 1 && cnt2 <= (h + w - 2) / 2 ? "Yes" : "No") << endl;
  } else if ((h % 2 == 1) && (w % 2 == 0)) {
    cout << (cnt1 == 0 && cnt2 <= w / 2 ? "Yes" : "No") << endl;
  } else if ((h % 2 == 0) && (w % 2 == 1)) {
    cout << (cnt1 == 0 && cnt2 <= h / 2 ? "Yes" : "No") << endl;
  } else {
    cout << (cnt1 == 0 && cnt2 == 0 ? "Yes" : "No") << endl;
  }
  return 0;
}
