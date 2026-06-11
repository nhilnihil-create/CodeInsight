#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define vc vector<char>
#define ii pair<int,int>
#define fi first
#define sc second
#define stoi stoll
#define all(x) (x).begin(),(x).end()
#define get_bit(x, k) ((x >> k) & 1)
// ---------------------------------

int check(string t) {
  for (auto &i : t) {
    if (i != t[0]) return 1;
  }
  return 0;
}

void MAIN() {
  string s;
  cin >> s;
  int ans = 2e9;
  for (char c = 'a'; c <= 'z'; c++) {
    string t = s;
    int cnt = 0;
    while (check(t)) {
      cnt++;
      for (int i = 0; i < t.size() - 1; i++) {
        if (t[i + 1] == c) t[i] = c;
      }
      t.pop_back();
    }
    ans = min(ans, cnt);
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
