#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s; cin >> s;
  int sn = s.size();
  set<int> S;
  rep(i,sn) S.insert(s[i]);
  int ans = sn;
  for (auto Si : S) {
    int i = 0, mcnt = 0;
    while (i < sn) {
      int cnt = 0;
      if (s[i] != Si) {
        while (s[i] != Si && i < sn) {
          cnt++;
          i++;
        }
      } else {
        i++;
      }
      mcnt = max(mcnt, cnt);
    }
    ans = min(ans, mcnt);
  }
  cout << ans << endl;
  return 0;
}