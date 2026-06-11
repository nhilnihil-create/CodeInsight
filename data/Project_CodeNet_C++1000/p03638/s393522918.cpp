#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll h, w;
  cin >> h >> w;
  ll n;
  cin >> n;
  vector <vector <ll>> v(h, vector <ll> (w));
  ll x = 0, y = 0, flag = 0;
  rep(i, n) {
    ll a;
    cin >> a;
    rep(j, a) {
      v.at(y).at(x) = i+1;
      if (flag%2 == 0) {
        if (x == w-1) {
          flag++;
          y++;
        } else {
          x++;
        }
      } else {
        if (x == 0) {
          flag++;
          y++;
        } else {
          x--;
        }
      }
    }
  }
  rep(i, h) {
    rep(j, w) {
      if (j) cout << ' ' << v.at(i).at(j);
      else cout << v.at(i).at(j);
    }
    cout << endl;
  }
}