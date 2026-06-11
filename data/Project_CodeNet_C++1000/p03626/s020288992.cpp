#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
int main(){
  ll n;
  string s, t;
  cin >> n >> s >> t;
  
  ll color, ans;
  for (ll i = 0; i < n; i++) {
    if (s[i] == t[i]) {
      if (i == 0) ans = 3;
      else if (color == 1) {
        ans *= 2;
        ans %= mod;
      }
      color = 1;
    }
    else {
      if (i == 0) ans = 6;
      else if (color == 1) {
        ans *= 2;
        ans %= mod;
      }
      else {
        ans *= 3;
        ans %= mod;
      }
      color = 2;
      i++;
    }
  }
  
  cout << ans << endl;
}