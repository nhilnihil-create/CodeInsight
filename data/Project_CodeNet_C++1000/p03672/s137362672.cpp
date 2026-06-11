#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s; cin >> s;
  int sn = s.size();
  int ans = 1;
  rep(i,sn-1) {
    int end = sn-1-i;
    if (end % 2 == 0) {
      string ss = s.substr(0,end);
      if (ss.substr(0, end/2) == ss.substr(end/2, end)) {
        ans = end;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}