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
  set<int> d;
  for (auto &i : s) d.insert(i);
  if (d.size() == s.size()) {
    cout << "yes" << '\n';
  }
  else cout << "no" << '\n';
}
