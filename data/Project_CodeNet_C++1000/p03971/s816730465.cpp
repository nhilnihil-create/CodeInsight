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
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  string s; cin >> s;
  int cnt = 0, flg = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'c') {
      cout << "No" << '\n';
    }
    if (s[i] == 'b') {
      flg++;
      if (cnt < a + b && flg <= b) {
        cout << "Yes" << '\n';
        cnt++;
      } else {
        cout << "No" << '\n';
      }
    }
    if (s[i] == 'a') {
      if (cnt < a + b) {
        cout << "Yes" << '\n';
        cnt++;
      } else {
        cout << "No" << '\n';
      }
    }
  }
}
