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
  string s; int k;
  cin >> s >> k;
  for (auto &i : s) {
    if (i != 'a' && 'z' - i + 1 <= k) {
      k -= 'z' - i + 1;
      i = 'a';
    }
  }
  if (k) {
    k %= 26;
    s.back() += k;
    if (s.back() > 'z') s.back() -= 26;
  }
  cout << s << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  cerr << "- ---- -- ----- <3\n";
#endif
  cin.tie(0)->sync_with_stdio(0);
  int T = 1;
  // cin >> T;
  while (T--) Main();
}
