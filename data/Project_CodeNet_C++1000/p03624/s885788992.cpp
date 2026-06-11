#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
  string s; cin >> s;
  vector <ll> v(26, 0);
  rep(i, s.size()) {
    ll loc = s.at(i) - 'a';
    v.at(loc)++;
  }
  rep(i, 26) {
    if (!v.at(i)) {
      char c = 'a' + i;
      cout << c << endl;
      break;
    }
    if (i == 25) cout << "None" << endl;
  }
}