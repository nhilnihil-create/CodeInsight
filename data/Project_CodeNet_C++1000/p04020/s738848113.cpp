#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

const int N = 2e5;

void solve() {
  int n; cin >> n;
  vector<int> vt(n);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> vt[i];
  }
  for (int i = 0; i < n; i++) {
    if (vt[i] % 2 == 1 && i + 1 < n && vt[i + 1]) {
      vt[i]--, vt[i + 1]--; ans++;
    }
    ans += vt[i] / 2;
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
