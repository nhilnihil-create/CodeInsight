#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

#define pow abcdef

int pow(int a, int b) {
  if (b < 0) return 1;
  if (b == 0) return 1;
  int t = pow(a, b / 2);
  t *= t;
  if (b % 2) return a * t;
  return t;
}

void MAIN() {
  string s;
  cin >> s;
  int n = s.size();
  int ans = 0;
  for (int i = 0; i < (1 << (n - 1)); i++) {
    int t = s[0] - '0';
    for (int j = 1; j < n; j++) {
      if ((i >> (j - 1)) & 1) {
        ans += t;
        t = s[j] - '0';
      } else {
        t = t * 10 + (s[j] - '0');
      }
    }
    ans += t;
  }
  cout << ans << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
