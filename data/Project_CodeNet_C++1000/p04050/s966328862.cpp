#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) ((x).size()))
typedef long long ll;
typedef long double ld;

int n, m, a[1000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> n >> m;
  for (int i = 0; i < m; i++)
    cin >> a[i];
  if (m == 1) {
    cout << a[0] << "\n";
    if (a[0] == 1)
      cout << "1\n1\n";
    else
      cout << "2\n" << 1 << " " << a[0] - 1 << "\n";
    return 0;
  }
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    if (a[i] % 2 == 1) {
      swap(a[i], a[cnt]);
      cnt++;
    }
  }
  if (cnt > 2) {
    cout << "Impossible\n";
    return 0;
  }
  swap(a[1], a[m - 1]);
  for (int i = 0; i < m; i++)
    cout << a[i] << (i < m - 1 ? " " : "\n");
  cout << (a[m - 1] == 1 ? m - 1 : m) << "\n";
  cout << a[0] + 1;
  for (int i = 1; i < m - 1; i++)
    cout << " " << a[i];
  if (a[m - 1] != 1)
    cout << " " << a[m - 1] - 1;
  cout << "\n";
}
