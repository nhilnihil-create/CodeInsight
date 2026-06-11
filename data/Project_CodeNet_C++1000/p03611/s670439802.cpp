#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n+2);
  map<int,int> cnt;
  rep(i,n) {
    int ni; cin >> ni;
    cnt[ni]++;
    cnt[ni+1]++;
    cnt[ni-1]++;
  }

  int ans = 0;
  for (auto p : cnt) {
    ans = max(ans, p.second);
  }
  cout << ans << endl;
  return 0;
}