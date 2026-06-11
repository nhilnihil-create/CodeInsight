#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int,int> mi,me,md;
  set<int> s;
  rep(i,n) {
    cin >> a[i];
    mi[a[i]+1]++;
    me[a[i]]++;
    md[a[i]-1]++;
    s.insert(a[i]+1);
    s.insert(a[i]);
    s.insert(a[i]-1);
  }
  int ans = 0;
  for (auto si:s) {
    int cnt = 0;
    if (mi.count(si)) cnt += mi[si];
    if (me.count(si)) cnt += me[si];
    if (md.count(si)) cnt += md[si];
    ans = max(cnt, ans);
  }
  cout << ans << endl;
  return 0;
}