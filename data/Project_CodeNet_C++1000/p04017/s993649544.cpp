#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

const int N = 1e5, LOG = 18;
int jmp[N][LOG];
int x[N];

void solve() {
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  int L, q; cin >> L >> q;
  int id = n - 1;
  for (int i = n - 1; i >= 0; i--) {
    while (x[id] - x[i] > L)
      id--;
    jmp[i][0] = id;
  }
  for (int lvl = 1; lvl < LOG; lvl++) {
    for (int i = 0; i < n; i++) {
      int j = jmp[i][lvl - 1];
      jmp[i][lvl] = jmp[j][lvl - 1];
    }
  }
  for (int i = 0; i < q; i++) {
    int l, r; cin >> l >> r; l--, r--;
    if (l > r) swap(l, r);
    int v = l, res = 0;
    for (int lvl = LOG - 1; lvl >= 0; lvl--) {
      int nv = jmp[v][lvl];
      if (nv < r) v = nv, res += (1 << lvl);
    }
    cout << res + 1 << "\n";
  }
}

// CHECK LIMITS (n <= 10^5)
// CHECK CORNER CASES (n == 1)

int main() {
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  cout.setf(ios::fixed), cout.precision(20);
  //cout << 1.0 * clock() / CLOCKS_PER_SEC << endl;
  solve();
}
