#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int main() {
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  string ans = "";
  REP(i, ty - sy) { ans += "U"; }
  REP(i, tx - sx) { ans += "R"; }
  REP(i, ty - sy) { ans += "D"; }
  REP(i, tx - sx) { ans += "L"; }
  ans += "L";
  REP(i, ty - sy + 1) { ans += "U"; }
  REP(i, tx - sx + 1) { ans += "R"; }
  ans += "D";
  ans += "R";
  REP(i, ty - sy + 1) { ans += "D"; }
  REP(i, tx - sx + 1) { ans += "L"; }
  ans += "U";
  cout << ans << endl;
}