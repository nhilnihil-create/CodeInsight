#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  rep2(i, 1, n + 1) cin >> a[i];
  if (n % 2 != 0) {
    for (int i = n; i > 0; i -= 2) {
      cout << a[i];
      if (n != 1) cout << " ";
    }
    for (int i = 2; i <= n - 1; i += 2) {
      cout << a[i];
      if (i != n - 1) cout << " ";
    }
    cout << endl;
  } else {
    for (int i = n; i >= 2; i -= 2) {
      cout << a[i] << " ";
    }
    for (int i = 1; i <= n - 1; i += 2) {
      cout << a[i];
      if (i != n - 1) cout << " ";
    }
    cout << endl;
  }
  return 0;
}