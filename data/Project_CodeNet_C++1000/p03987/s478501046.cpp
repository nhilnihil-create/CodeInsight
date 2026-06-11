#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

const int N = 2e5, LOG = 18;
int a[N];
int sp[N][LOG];
int plen[N + 1];

int getmin(int l, int r) {
  int len = plen[r - l + 1];
  return min(sp[l][len], sp[r - (1 << len) + 1][len]);
}

void solve() {
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sp[i][0] = a[i];
  }
  for (int i = 2; i <= n; i++) {
    plen[i] = plen[i / 2] + 1;
  }
  for (int lvl = 1; lvl < LOG; lvl++) {
    for (int i = 0; i + (1 << lvl) - 1 < n; i++) {
      sp[i][lvl] = min(sp[i][lvl - 1], sp[i + (1 << (lvl - 1))][lvl - 1]);
    }
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int l = 0, r = i - 1, ansl = i, ansr = i;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (getmin(mid, i - 1) > a[i])
        r = mid - 1, ansl = mid;
      else
        l = mid + 1;
    }
    l = i + 1, r = n - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (getmin(i + 1, mid) > a[i])
        l = mid + 1, ansr = mid;
      else
        r = mid - 1;
    }
    ll cntl = i - ansl + 1, cntr = ansr - i + 1;
    ans += cntl * cntr * a[i];
  }
  cout << ans;
}

// CHECK LIMITS (n <= 10^5)
// CHECK CORNER CASES (n == 1)

int main() {
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  cout.setf(ios::fixed), cout.precision(20);
  //cout << 1.0 * clock() / CLOCKS_PER_SEC << endl;
  solve();
}
