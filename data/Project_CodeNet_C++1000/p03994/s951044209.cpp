#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  int k;
  cin >> s >> k;
  rep(i, s.size()) {
    if (i == s.size()-1) {
      if (s[i] + k%26 > 'z') s[i] += k%26 - 26;
      else s[i] += k%26;
      break;
    }
    if (s[i] == 'a') continue;
    if (k < 'z' - s[i] + 1) continue;
    k -= 'z' - s[i] + 1;
    s[i] = 'a';
  }
  cout << s << endl;
  return 0;
}