#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  string s;
  cin >> n >> s;

  int l = 0, r = 0;
  int al = 0;
  rep(i, n) {
    if (s[i] == '(') ++l;
    else ++r;
    al = max(al, r-l);
  }

  string ans = "";
  rep(i, al) ans += '(';
  l += al;
  ans += s;
  rep(i, l-r) ans += ')';
  cout << ans << endl;
  return 0;
}