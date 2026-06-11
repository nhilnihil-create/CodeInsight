#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, a, b; cin >> n >> a >> b;
  string s; cin >> s;
  int ap = 0, bp = 0;
  vector<bool> r(n);
  rep(i, n) {
    if (s[i] == 'a' && ap + bp < a + b) {
      r[i] = true;
      ap++;
    } else if (s[i] == 'b' && ap + bp < a + b && bp < b) {
      r[i] = true;
      bp++;
    } else {
      r[i] = false;
    }
  }
  rep(i, n) {
    if (r[i] == true) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}