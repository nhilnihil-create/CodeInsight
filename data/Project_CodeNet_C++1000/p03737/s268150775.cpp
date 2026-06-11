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
  string ans;
  rep(i, 3) {
    cin >> s;
    ans.push_back(toupper(s[0]));
  }
  
  cout << ans << endl;
  
  return 0;
}