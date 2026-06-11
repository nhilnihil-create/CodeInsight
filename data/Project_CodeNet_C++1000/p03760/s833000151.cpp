#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  string o, e;
  cin >> o >> e;
  string ans;
  rep(i, o.length()) {
    ans.push_back(o[i]);
    if (e.length() > i) {
      ans.push_back(e[i]);
    }
  }

  cout << ans << endl;
  
  return 0;
}