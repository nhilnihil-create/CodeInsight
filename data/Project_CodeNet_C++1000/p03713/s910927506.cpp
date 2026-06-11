#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

int type_one(int h, int w) {
  int a = h / 3;
  int mi = a * w;
  if (h % 3) a++;
  int ma = a * w;
  return ma - mi;
}

int type_two(int h, int w) {
  int a = w / 3 + (w % 3 == 2);
  vector<int> v(3);
  v[0] = a * h;
  v[1] = (w - a) * (h / 2);
  v[2] = (w - a) * (h / 2 + h % 2);
  sort(all(v));
  return v[2] - v[0]; 
}

void solve() {
  int h, w;
  cin >> h >> w;
  // cout << type_one(w, h) << '\n';
  // cout << type_one(h, w) << '\n';
  // cout << type_two(w, h) << '\n';
  // cout << type_two(h, w) << '\n';
  cout << min(min(type_one(w, h), type_one(h, w)), min(type_two(w, h), type_two(h, w))) << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) solve();
}
