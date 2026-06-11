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
  string a, b;
  cin >> a >> b;
  if (a.size() > b.size()) {
    cout << "GREATER" << '\n';
    return 0;
  }
  if (a.size() < b.size()) {
    cout << "LESS" << '\n';
    return 0;
  }
  for (int i = 0; i < a.size(); i++) {
    if (a[i] > b[i]) {
      cout << "GREATER" << '\n';
      return 0;
    }
    if (a[i] < b[i]) {
      cout << "LESS" << '\n';
      return 0;
    }
  }
  cout << "EQUAL" << '\n';
}
