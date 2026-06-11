
// Problem: E - TrBBnsformBBtion
// Contest: AtCoder - AtCoder Regular Contest 071
// URL: https://atcoder.jp/contests/arc071/tasks/arc071_c
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e6 + 5;

string s, t;
int ps[N], pt[N];

int32_t main() { cin.tie(0)->sync_with_stdio(0);
  cin >> s >> t;
  int n = s.size(), m = t.size();
  s = ' ' + s, t = ' ' + t;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'A') ps[i] = ps[i - 1] + 1;
    else ps[i] = ps[i - 1] + 2;
  }
  for (int i = 1; i <= m; i++) {
    if (t[i] == 'A') pt[i] = pt[i - 1] + 1;
    else pt[i] = pt[i - 1] + 2;
  }
  int q;
  cin >> q;
  while (q--) {
    int ls, rs, lt, rt;
    cin >> ls >> rs >> lt >> rt;
    int l = ps[rs] - ps[ls - 1];
    int r = pt[rt] - pt[lt - 1];
    if ((r - l) % 3 == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}