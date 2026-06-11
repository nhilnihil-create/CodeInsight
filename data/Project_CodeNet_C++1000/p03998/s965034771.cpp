#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string sa, sb, sc; cin >> sa >> sb >> sc;
  int an = sa.size(), bn = sb.size(), cn = sc.size();
  sa += " "; sb += " "; sc += " ";
  int ai = 0, bi = 0, ci = 0;
  char turn = 'a';
  char ans = 'Z';
  while (true) {
    if (turn == 'a') {turn = sa[ai]; ai++;}
    else if (turn == 'b') {turn = sb[bi]; bi++;}
    else if (turn == 'c') {turn = sc[ci]; ci++;}
    if (ai > an) {ans = 'A'; break;}
    else if (bi > bn) {ans = 'B'; break;}
    else if (ci > cn) {ans = 'C'; break;}
  }
  cout << ans << endl;
  return 0;
}