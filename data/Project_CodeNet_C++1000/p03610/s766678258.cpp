#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  string s;
  cin >> s;

  string ans((s.length() + 1) / 2, 'a');
  for (int i = 0; i < s.length(); i += 2) {
    ans[i / 2] = s[i];
  }

  cout << ans << endl;
  
  return 0;
}