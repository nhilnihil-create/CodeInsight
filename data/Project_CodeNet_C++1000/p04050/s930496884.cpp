#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

const int N = 300100;

void solve() {
  int n, m; cin >> n >> m;
  vector<int> nvt(m);
  int sum = 0;
  for (int i = 0; i < m; i++) {
    cin >> nvt[i];
    sum += nvt[i] / 2;
  }
  if (sum + n / 2 < n - 1) {
    cout << "Impossible"; return;
  }
  vector<int> odd, even;
  for (int i = 0; i < m; i++) {
    if (nvt[i] % 2 == 0) even.push_back(nvt[i]);
    else odd.push_back(nvt[i]);
  }
  if (n % 2 == 0) {
    // two odd or zero odd
    vector<int> vt;
    if (odd.size() == 2) {
      vt.push_back(odd[0]);
      for (auto x : even) vt.push_back(x);
      vt.push_back(odd[1]);
    }
    else {
      for (auto x : even) vt.push_back(x);
    }
    for (auto x : vt) cout << x << " "; cout << "\n";
    vt[0]--;
    if (m > 1) vt[m - 1]++;
    else vt.push_back(1);
    if (vt[0] == 0) vt.erase(vt.begin());
    cout << vt.size() << "\n";
    for (auto x : vt) cout << x << " "; cout << "\n";
  }
  else {
    // one odd only
    vector<int> vt;
    vt.push_back(odd[0]);
    for (auto x : even) vt.push_back(x);
    for (auto x : vt) cout << x << " "; cout << "\n";
    vt[0]--;
    if (vt[0] == 0) vt.erase(vt.begin());
    vt.push_back(1);
    cout << vt.size() << "\n";
    for (auto x : vt) cout << x << " "; cout << "\n";
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
