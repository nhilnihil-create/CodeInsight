#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  string s; cin >> s;
  int a = 0, ans = 0;
  rep(i,s.size()) {
    if (s[i] == 'I') a++;
    else a--;
    ans = max(ans, a);
  }
  cout << ans << endl;
  return 0;
}
