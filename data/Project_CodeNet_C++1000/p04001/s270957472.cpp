#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  string s; cin >> s;
  ll ans = 0;
  int n = s.size();
  for(int bit = 0; bit < (1 << n - 1); bit++){
    string t = "";
    t += s[0];
    for(int i = 0; i < n - 1; i++){
      if(bit & (1 << i)){
        ans += stoll(t);
        t = s[i + 1];
      }
      else{
        t += s[i + 1];
      }
    }
    ans += stoll(t);
  }
  printf("%lld\n", ans);
}