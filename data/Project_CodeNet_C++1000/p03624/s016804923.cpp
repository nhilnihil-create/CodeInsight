#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  vector<bool> app(26);
  rep(i, 26) app[i] = false;
  rep(i, s.size()) app[s[i] - 'a'] = true;
  string ans = "";
  rep(i, 26) if(!app[i]) {
    ans = i + 'a';
    cout << ans << endl;
    return 0;
  }
  
  cout << "None" << endl;
  return 0;
}