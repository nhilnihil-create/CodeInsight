#include <iostream>
#include <string>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s; cin >> s;
  rep(i, s.size()) {
    cout << s[i];
    if(i == 3) cout << ' ';
  }
  cout << '\n';
  return 0;
}
