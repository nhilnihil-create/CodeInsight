#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
  string s, t, ans;
  cin >> s >> t;
  for(int i=0; i<s.size(); i++) {
    ans += s[i];
    if(i==s.size()-1 && s.size()!=t.size()) break;
    for(int j=0; j<1; j++) {
      ans += t[i];
    }
  }
  cout << ans << endl;
  return 0;
}