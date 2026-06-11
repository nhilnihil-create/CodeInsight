#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

const int N = 110;
vector<int> vrt[N];

void solve() {
  int n; cin >> n;
  int diam = 0, mn = 1e9;
  for (int v = 1; v <= n; v++) {
    int a; cin >> a; vrt[a].push_back(v);
    diam = max(diam, a); mn = min(mn, a);
  }
  if (diam % 2 == 0 && (vrt[diam / 2].size() != 1 || mn < diam / 2)) {
    cout << "Impossible"; return;
  }
  if (diam % 2 == 1 && (vrt[(diam + 1) / 2].size() != 2 || mn < (diam + 1) / 2)) {
    cout << "Impossible"; return;
  }
  for (int dst = diam, l = 0, r = diam; l <= r; dst--, l++, r--) {
    if (l == r && vrt[dst].size() < 1 || l != r && vrt[dst].size() < 2) {
      cout << "Impossible"; return;
    }
  }
  cout << "Possible";
}

// CHECK LIMITS (n <= 10^5)
// CHECK CORNER CASES (n == 1)

int main() {
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  cout.setf(ios::fixed), cout.precision(20);
  //cout << 1.0 * clock() / CLOCKS_PER_SEC << endl;
  solve();
}
