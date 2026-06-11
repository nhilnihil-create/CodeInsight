#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const ll INF = 1e18;
const long double EPS = 1e-10;
const int MAX = 1e5;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  int ans = n;
  vector<int> c(MAX, 0);
  rep(i, n) c[a[i] - 1]++;
  
  bool flag = false;
  rep(i, MAX) {
    if (c[i] < 2) continue;
    if (c[i] & 1) ans -= c[i] - 1;
    else {
      ans -= c[i] - 2;
      if (!flag) ans -= 2;
      flag ^= 1;
    }
  }
  cout << ans << endl;


  
  return 0;
}