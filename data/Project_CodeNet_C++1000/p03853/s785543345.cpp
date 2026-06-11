#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int h, w; cin >> h >> w;
  vector<string> c(h+1);
  rep(i,h) {
    cin >> c[i+1];
  }
  rep(i,h*2+1) {
    if (i==0) continue;
    rep(j,w) {
      cout << c[(i+1)/2][j];
    }
    cout << endl;
  }
  return 0;
}