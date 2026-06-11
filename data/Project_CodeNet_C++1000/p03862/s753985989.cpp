#include <bits/stdc++.h>
#define rep(i, ns, ne) for (int i = ns; i < ne; ++i)
using namespace std;

int main() {
  long long n, x, tmp, ans = 0;
  cin >> n >> x;

  vector<long long> v(n + 1, 0);
  rep(i, 0, n) { cin >> v[i]; }

  rep(i, 0, n) {
    tmp = 0;
    if (v[i] + v[i + 1] >= x) {
      tmp = v[i] + v[i + 1] - x;
      v[i + 1] = v[i + 1] - tmp;
      ans += tmp;
    }
  }

  cout << ans << endl;
  getchar();
}
