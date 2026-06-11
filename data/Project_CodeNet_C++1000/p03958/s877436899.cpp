#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define ii pair<int,int>
#define fi first
#define sc second
#define stoi stoll
#define popcnt __builtin_popcount
#define getBit(x, k) ((x >> k) & 1)
#define all(x) (x).begin(),(x).end()
// ---------------------------------

void Main() {
  int s, n;
  cin >> s >> n;
  int m = 0;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    m = max(m, t);
  }
  cout << max(m - (s - m + 1), 0ll) << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  cerr << "i love ------- <3 \n";
#endif
  cin.tie(0)->sync_with_stdio(0);
  int T = 1;
  // cin >> T;
  while (T--) Main();
}
