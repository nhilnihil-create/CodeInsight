#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main(void) {
  string s;
  cin >> s;
  int p = 0, g = 0;
  int ans = 0;

  rep(i,s.size()) {
    if(p+1 <= g) {
      p++;
      if(s[i] == 'g') ans++;
    } else {
      g++;
      if(s[i] == 'p') ans--;
    }
  }
  cout << ans << endl;
}