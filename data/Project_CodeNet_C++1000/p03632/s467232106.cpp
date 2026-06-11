#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int ans = 0;
  int l = max(a, c);
  int r = min(b, d);

  ans = max(r - l, 0);

  cout << ans << endl;
  
  return 0;
}