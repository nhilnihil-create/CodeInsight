#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define vc vector<char>
#define ii pair<int,int>
#define fi first
#define sc second
#define all(x) (x).begin(),(x).end()
#define get_bit(x, k) ((x >> k) & 1)
// ---------------------------------

void MAIN() {
  int a, b;
  cin >> a >> b;
  if (a == 0) {
    if (b >= 0) cout << b - a << '\n';
    else cout << a - b + 1 << '\n';
  }
  else if (b == 0) {
    if (a <= 0) cout << abs(a) << '\n';
    else cout << a + 1 << '\n';
  }
  else {
    if (a * b > 0) {
      cout << abs(a - b) + (a > b) * 2 << '\n';
    }
    else {
      cout << abs(abs(a) - abs(b)) + 1 << '\n';
    }
  }
}

signed main() {
  // ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
