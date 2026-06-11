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
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int a, b;
  cin >> a >> b;
  if (a > 0) cout << "Positive" << '\n';
  else if (b < 0) {
    if (abs(b - a + 1) % 2 == 0) cout << "Positive" << '\n';
    else cout << "Negative" << '\n';
  }
  else cout << "Zero" << '\n';
}
