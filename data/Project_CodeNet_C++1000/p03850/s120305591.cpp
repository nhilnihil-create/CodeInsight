// includes {{{
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<tuple>
#include<cmath>
#include<random>
#include<cassert>
// #include<deque>
// #include<multiset>
// #include<bitset>
// #include<cstring>
// #include<bits/stdc++.h>
// }}}
using namespace std;
using ll = long long;

const int N = 1e5 + 1;
int n;
const ll inf = 1e18;

ll dp[N][3];

int a[N];
int op[N];

// smin, smax {{{
// clang-format off
template < class T, class U > inline void smin(T &a, const U &b) { a = a < (T) b ? a : b; }
template < class T, class U > inline void smax(T &a, const U &b) { a = a < (T) b ? b : a; }
// clang-format on
// }}}

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n;
  op[0] = 1;
  for(int i = 0; i < n; i++) {
    char t_op;
    if(i) {
      cin >> t_op;
      op[i] = t_op == '-' ? -1 : 1;
    }
    cin >> a[i];
  }

  for(int i = 0; i < n; i++) for(int j = 0; j < 3; j++) dp[i][j] = -inf;

  dp[0][0] = a[0];

  for(int i = 1; i < n; i++) for(int j = 0; j < 3; j++) {
    for(int k = 0; k <= j; k++) {
      smax(dp[i][k], dp[i-1][j] + (j & 1 ? -1 : 1) * op[i] * a[i]);
    }
    if(op[i] == -1 && j <= 1) {
      smax(dp[i][j + 1], dp[i-1][j] + (j & 1 ? -1 : 1) * op[i] * a[i]);
    }
  }
  
  // -(...-(...-(x)) - y - z

  cout << dp[n-1][0] << endl;
  return 0;
}

