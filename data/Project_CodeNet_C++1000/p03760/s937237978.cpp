#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  string s, t;
  cin >> s >> t;
  string ans = "";
  rep(i, t.size()) {
    ans += s[i];
    ans += t[i];
  }
  if(s.size() > t.size()) ans+= s[s.size() - 1];
  cout << ans << endl;
  

  return 0;
}
