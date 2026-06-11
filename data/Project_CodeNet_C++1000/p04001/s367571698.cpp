#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for (int i = a; i < b; i++)
#define each(i, mp) for(auto& i:mp)

int main() {
  string s;
  cin >> s;

  ll ans = 0;
  // reverse(s.begin(), s.end());
  rep(i, 1 << (s.size() - 1)){
    ll tmp = (s[0]-'0');
    // cout << tmp << endl;
    // cout << " " << endl;
    rep(j, s.size() - 1){
      // tmp += (s[j]-'0');
      // ten *= 10;
      if (i>>j&1) {
        ans += tmp;
        tmp = s[j+1] - '0';
        // ten = 1;
        // tmp = 0;
      }
      else{
        tmp *= 10;
        tmp += (s[j+1]-'0');
      }
      // cout << tmp << endl;
    }
    ans += tmp;
    // cout << " " << endl;
  }
  // rep(i, s.size()) cout << s[i]-'0' << endl;
  cout << ans << endl;
  return 0;
}
