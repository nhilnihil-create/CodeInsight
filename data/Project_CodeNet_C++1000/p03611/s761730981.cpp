#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int max_ai = 100000;


int main(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) {
    cin >> a[i];
  }

  vector<int> v(max_ai, 0);
  rep(i, n) {
    v[a[i]]++;
    if (a[i] + 1 < max_ai) {
      v[a[i] + 1]++;
    }
    if (a[i] - 1 >= 0) {
      v[a[i] - 1]++;
    }
  }

  int ans = 0;
  rep(i, max_ai) {
    ans = max(ans, v[i]);
  }

  cout << ans << endl;
  
  return 0;
}