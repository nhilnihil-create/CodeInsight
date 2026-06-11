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
  string s;
  cin >> s;
  map<char, int> m;
  for (auto &i : s) m[i] = 1;
  if (m['N'] == m['S'] && m['W'] == m['E']) {
    cout << "Yes" << '\n';
  }
  else cout << "No" << '\n';
}
