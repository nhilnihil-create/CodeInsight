#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  string s, t, u;
  cin >> s >> t >> u;
  string ans = "";
  ans += toupper(s[0]);
  ans += toupper(t[0]);
  ans += toupper(u[0]);
  cout << ans << endl;
  return 0;
}
