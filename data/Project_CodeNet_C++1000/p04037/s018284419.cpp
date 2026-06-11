#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) ((x).size()))
typedef long long ll;
typedef long double ld;

int n, a[200000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);
  bool wf;
  for (int i = 0; i < n; i++) {
    if (i == 0 || a[i] != a[i - 1])
      wf = (n - i - 1 + a[i]) % 2 == 0;
    if (wf && a[i] >= n - i - 1) {
      cout << "First\n";
      return 0;
    } else if (!wf && a[i] - 1 >= n - i - 1) {
      cout << "Second\n";
      return 0;
    }
  }
}
