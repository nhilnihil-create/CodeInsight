#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int q, h, s, d, n;
  cin >> q >> h >> s >> d >> n;
  if (q * 2 < h) h = q * 2;
  if (h * 2 < s) s = h * 2;
  if (s * 2 < d) d = s * 2;
  cout << (n / 2) * d + (n % 2) * s << '\n';
}
