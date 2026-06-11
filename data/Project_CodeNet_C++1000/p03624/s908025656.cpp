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

  vector<int> v(26, 0);

  rep(i, s.length()) {
    v[s[i] - 'a']++;
  }

  rep(i, v.size()) {
    if (v[i] == 0) {
      cout << (char)('a' + i) << endl;
      return 0;
    }
  }

  cout << "None" << endl;
  
  return 0;
}