#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


void solve(ll test_num) {
  (void) test_num;
  ll N;
  cin >> N;
  ll hig = 1;
  while (hig * (hig + 1) / 2 < N) {
    ++hig;
  }
  vector<ll> res;
  ll rem = N;
  for (ll x = hig; x > 0; --x) {
    if (x <= rem) {
      rem -= x;
      res.push_back(x);
    }
  }
  for (ll x : res)cout << x << ' ';
  cout << endl;
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