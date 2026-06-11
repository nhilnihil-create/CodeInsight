#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007LL

bool dbgflag = false;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  ll ans = 0;
  ll tmp = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      ans += tmp/2;
      tmp = 0;
    }
    else {
      tmp += a[i];
    }
  }
  ans += tmp/2;

  cout << ans << endl;
}
