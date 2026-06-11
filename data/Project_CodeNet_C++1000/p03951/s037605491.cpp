#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  string s, t; cin >> s >> t;
  int sn = s.size(), tn = t.size();
  int ans = sn + tn, d = 0;
  rep(i,sn) {
    int j = 0;
    if (s[i] == t[j]) {
      int ni = i;
      int cnt = 0;
      while(ni < sn && s[ni] == t[j]) {
        cnt++;
        ni++; j++;
      }
      if (ni == sn) d = max(d, cnt);
    }
  }
  cout << ans - d << endl;
  return 0;
}