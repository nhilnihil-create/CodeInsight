#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  string s;
  cin >> s;
  string ans = "yes";
  bool b[26];
  rep(i, 26) b[i] = false;
  rep(i, s.size()){
    if(b[s[i] - 'a']) ans = "no";
    b[s[i] - 'a'] = true;
  }
  cout << ans << endl;
  return 0;
}
