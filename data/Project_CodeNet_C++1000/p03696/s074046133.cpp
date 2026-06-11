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

void MAIN() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt = 0;
  string res;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') cnt++;
    else if (cnt == 0) res = '(' + res;
    else cnt--;
    res += s[i];
  }
  for (int i = 0; i < cnt; i++) res += ')';
  cout << res << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
