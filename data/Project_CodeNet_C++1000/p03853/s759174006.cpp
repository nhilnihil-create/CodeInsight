#include <bits/stdc++.h>
using namespace std;

#define ll long long

template<typename T> void drop(const T &x){cout<<x<<'\n';exit(0);}

void solve() {
  int h, w; cin >> h >> w;
  vector<string> c(h);
  for(int i=0; i<h; ++i) {
    cin >> c.at(i);
  }

  h*=2;
  for(int i=0; i<h; ++i) {
    cout << c.at(i/2) << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T=1;
  //cin >> T;
  while(T--) solve();

  return 0;
}
