#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second
#define lwb lower_bound
#define upb upper_bound
#define all(x) (x).begin(),(x).end()

void chmin(int &a, int b) {
  if (a > b) a = b;
}

signed main() {
#ifdef _DEBUG
  // freopen("in", "r", stdin);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  int res = 2e18;
  if ((a % 2) * (b % 2) * (c % 2)) {
    chmin(res, a * b);
    chmin(res, b * c);
    chmin(res, c * a);
  }
  else res = 0;
  cout << res << '\n';
}
