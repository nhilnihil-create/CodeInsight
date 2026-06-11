#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
int main() {
  ll N; cin >> N;
  string s, t; cin >> s >> t;
  ll p[53];
  p[0] = 1;
  if (s[0] == t[0]) {p[1] = 3;}
  else {p[2] = 6;}
  
  for (ll i = 2; i <= 52; i++) {
    if (s[i-1] == t[i-1]) {
      if (s[i-2] == t[i-2]) {
        p[i] = p[i-1]*2%mod;
      } else {
        p[i] = p[i-1];
      }
    } else {
      if (i >= 3 && s[i-2] == s[i-1] && s[i-3] == t[i-3]) {
        p[i] = p[i-2]*2%mod;
      }
      if (i >= 3 && s[i-2] == s[i-1] && s[i-3] != t[i-3]) {
        p[i] = p[i-2]*3%mod;
      }
      if (i == 2 && s[i-2] == s[i-1]) {
        p[i] = 6;
      }
    }
  }
  cout << p[N] << endl;
}