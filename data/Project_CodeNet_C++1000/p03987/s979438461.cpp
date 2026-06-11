#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;

typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector<pair<int,int> > a(N);
  REP(i,N) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());

  ll ans = 0;

  set<int> s;
  s.emplace(-1);
  s.emplace(N);

//  for ( auto x: a)
//    cout << x.first << " " << x.second << endl;

  REP(i,N) {
    int idx = a[i].second;
    auto it = s.lower_bound(idx);
    ll r = *it;
    it--;
    ll l = *it;
    ans += (ll)((idx-l) * (r-idx)) * (ll)a[i].first;
//    cout << idx << ":" << l << " - " << r << " * " << a[i].first << " => " << (ll)((idx-l) * (r-idx)) * (ll)a[i].first << endl;
    s.emplace(idx);
  }
  cout << ans << endl;

}


