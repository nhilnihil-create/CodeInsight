#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  map<int,int> a;
  int ans = 0;
  rep(i,n) {
    int ai; cin >> ai;
    if (a[ai] == 1) {
      a[ai]--;
      ans--;
    }
    else {
      a[ai]++;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
