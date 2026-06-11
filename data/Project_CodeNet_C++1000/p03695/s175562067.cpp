#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

int color(int n) {
  if (n < 400) return 1;
  else if (n < 800) return 2;
  else if (n < 1200) return 3;
  else if (n < 1600) return 4;
  else if (n < 2000) return 5;
  else if (n < 2400) return 6;
  else if (n < 2800) return 7;
  else if (n < 3200) return 8;
  else return 0;
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  set<int> s;
  int c = 0;
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    t = color(t);
    if (t) s.insert(t);
    else c++;
  }
  cout << max((int) s.size(), 1LL) << ' ' << s.size() + c << '\n';
}
