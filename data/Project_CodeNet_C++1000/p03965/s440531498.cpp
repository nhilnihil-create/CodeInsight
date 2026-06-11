#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s; cin >> s;

  int w = 0;
  int l = 0;
  int g = 0;
  int p = 0;
  rep(i, s.size()) {
    if(s[i] == 'g') {
      if(g == p) {
        g++;
      } else {
        p++;
        w++;
      }
    } else {
      if(g == p) {
        g++;
        l++;
      } else {
        p++;
      }
    }
  }

  cout << w - l << endl;
}
