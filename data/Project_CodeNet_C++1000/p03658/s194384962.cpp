#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int n, k;
  cin >> n >> k;
  vector<int> l(n);
  rep(i, n) {
    cin >> l[i];
  }

  sort(l.rbegin(), l.rend());

  int ans = 0;

  rep(i, k) {
    ans += l[i];
  }

  cout << ans << endl;
  
  return 0;
}