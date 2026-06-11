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
  string o, e;
  cin >> o >> e;
  for (int i = 0; i < min(o.size(), e.size()); i++) {
    cout << o[i] << e[i];
  }
  if (o.size() > e.size()) cout << o.back();
  if (e.size() > o.size()) cout << e.back();
  cout << '\n';
}
