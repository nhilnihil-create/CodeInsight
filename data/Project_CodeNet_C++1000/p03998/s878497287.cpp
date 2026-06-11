#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
  string a, b, c; cin >> a >> b >> c;
  ll loc_a = 0, loc_b = 0, loc_c = 0;
  char ch = 'a';
  while (true) {
    if (ch == 'a') {
      if (loc_a == a.size()) {
        cout << 'A' << endl;
        break;
      } else {
        ch = a.at(loc_a);
        loc_a++;
      }
    } else if (ch == 'b') {
      if (loc_b == b.size()) {
        cout << 'B' << endl;
        break;
      } else {
        ch = b.at(loc_b);
        loc_b++;
      }
    } else {
      if (loc_c == c.size()) {
        cout << 'C' << endl;
        break;
      } else {
        ch = c.at(loc_c);
        loc_c++;
      }
    }
  }
}