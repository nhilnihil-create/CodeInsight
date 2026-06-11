#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
map<pair<int,int>,int> mp;
int dy[9] = {0,1,1,0,-1,-1,-1,0,1};
int dx[9] = {0,0,1,1,1,0,-1,-1,-1};
vector<ll> ans(10);

int main(){
  ll h, w, n;
  cin >> h >> w >> n;
  for (int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    for (int j = 0; j < 9; j++) {
      mp[make_pair(a + dx[j], b + dy[j])]++;
    }
  }
  ans[0] = (h - 2) * (w - 2);
  for (auto p : mp) {
    if (p.first.first >= 2 && p.first.first <= h - 1
        && p.first.second >= 2 && p.first.second <= w - 1) {
          ans[p.second]++;
          ans[0]--;
        }
  }
  for (int i = 0; i <= 9; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
