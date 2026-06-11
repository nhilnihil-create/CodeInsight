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
  int a, b, c;
  cin >> a >> b >> c;
  for (int i = 0; i < b; i++) {
    if ((a * i) % b == c) {
      cout << "YES" << '\n';
      return 0;
    }
  }
  cout << "NO" << '\n';
}
