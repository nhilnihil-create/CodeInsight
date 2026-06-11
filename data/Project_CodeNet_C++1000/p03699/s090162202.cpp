#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  vector<int> s(n);
  int ans = 0;
  rep(i,n) {
    cin >> s[i];
    ans += s[i];
  }
  sort(s.begin(), s.end());
  rep(i,n) {
    if (ans%10!=0) {
      cout << ans << endl;
      return 0;
    } else {
      if (ans%10==0 && s[i]%10!=0) {
        ans -= s[i];
      } 
    }
  }
  if (ans%10==0) cout << 0 << endl;
  return 0;
}