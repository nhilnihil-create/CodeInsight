#include <bits/stdc++.h>
#define rep(i, ns, ne) for (int i = ns; i < ne; ++i)
using namespace std;
using ULL = unsigned long long;

int main() {
  ULL N, a, b, ans = 0;
  cin >> N >> a >> b;
  vector<ULL> v(N);
  rep(i, 0, N) { cin >> v.at(i); }
  rep(i, 0, N - 1) { ans += min(a * (v[i + 1] - v[i]), b); }
  cout << ans << endl;
  getchar();
}