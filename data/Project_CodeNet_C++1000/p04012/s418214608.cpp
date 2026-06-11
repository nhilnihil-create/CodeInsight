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
  for (auto &i : s) m[i]++;
  for (auto &i : m) {
    if (i.sc % 2) {
      cout << "No" << '\n';
      return 0;
    }
  }
  cout << "Yes" << '\n';
}
