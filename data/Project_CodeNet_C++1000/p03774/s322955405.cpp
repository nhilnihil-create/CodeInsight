#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<ll,ll>> students(n);
  rep(i,n) {
    ll a,b; cin >> a >> b;
    students[i] = make_pair(a,b);
  }
  vector<pair<ll,ll>> point(m);
  rep(i,m) {
    ll a, b; cin >> a >> b;
    point[i] = make_pair(a,b);
  }
  int ans[100];
  rep(i,n) {
    ll dist = 1e10;
    rep(j,m) {
      ll now = abs(students[i].first-point[j].first) + abs(students[i].second-point[j].second);
      if (now < dist) {
        dist = now;
        ans[i] = j + 1;
      }
    }
  }
  rep(i,n) cout << ans[i] << endl;
  return 0;
}