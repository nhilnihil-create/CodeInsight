#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll H, W; cin >> H >> W;
  ll N; cin >> N;
  vector<ll> color;
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    for (ll j = 0; j < a; j++) {
      color.push_back(i+1);
    }
  }
  for (ll i = 0; i < H; i++) {
    for (ll j = 0; j < W; j++) {
      if (i%2 == 0) {
        cout << color[i*W+j] << " ";
      } else {
        cout << color[i*W+W-1-j] << " ";
      }
    }
    cout << endl;
  }
}