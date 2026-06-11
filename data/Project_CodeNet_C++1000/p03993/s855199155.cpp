#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  int ans = 0;
  vector<int> a(n);
  rep(i,n) {
    cin >> a[i];
    a[i]--;
  }
  vector<bool> ed(n,false);
  rep(i,n) {
    if (ed[i]) continue;
    if (a[a[i]] == i) {
      ans++;
      ed[i] = true; ed[a[i]] = true;
    }
  }
  cout << ans << endl;
  return 0;
}