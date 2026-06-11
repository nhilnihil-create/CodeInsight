#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  deque<int> ans;
  int p = n % 2;

  rep(i,n) {
    if (i%2 != p) ans.push_front(a[i]);
    else ans.push_back(a[i]);
  }

  while(ans.size()!=1) {
    cout << ans.front() << " ";
    ans.pop_front();
  }
  cout << ans.front() << endl;

  return 0;
}