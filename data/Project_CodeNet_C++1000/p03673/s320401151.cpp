#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> p;
typedef long long ll;
const int inf = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<int> b(n);

  for (int i = 0; i < n; i++) {
    if (n - i * 2 - 1 >= 0) b[i] = a[n - i * 2 - 1];
  }
  for (int i = 0; i < n; i++) {
    if (i * 2 - n % 2 < n && i * 2 - n % 2 >= 0)
      b[i + n / 2] = a[i * 2 - n % 2];
  }
  rep(i, n) cout << b[i] << endl;

  return 0;
}