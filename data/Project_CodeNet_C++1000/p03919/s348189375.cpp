#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


void solve(ll test_num) {
  (void) test_num;
  ll H, W;
  cin >> H >> W;
  for (ll r = 1; r <= H; ++r) {
    for (ll c = 0; c < W; ++c) {
      string str;
      cin >> str;
      if (str == string("snuke")) {
        cout << char(c + 'A') << r << endl;
        return;
      }
    }
  }
}

void init() {

}

int main() {
#ifdef AZN
  freopen("/home/azneye/Documents/Stuff/input.txt", "r", stdin);
#endif
  init();
  ll tests = 1;
  //cin >> tests;
  for (ll test = 1; test <= tests; ++test) {
    solve(test);
  }
  return 0;
}