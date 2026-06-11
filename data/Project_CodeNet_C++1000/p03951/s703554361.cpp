#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n;
  string s, t;
  cin >> n >> s >> t;
  ll oh = n;
  rep(i, n) {
    // cerr << s.substr(i, n - i) << " " << t.substr(0, n - i) << endl;
    if (s.substr(i, n - i) == t.substr(0, n - i)) break;
    oh--;
  }
  cout << 2 * n - oh << endl;

  return 0;
}
