#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s; cin>>s;
  map<char,int> m;
  string ans = "Yes";
  rep(i,s.size()) m[s[i]]++;
  if (m.count('E') == true && m.count('W') == false ||
       m.count('E') == false && m.count('W') == true) ans = "No";
  
  if (m.count('N') == true && m.count('S') == false ||
       m.count('N') == false && m.count('S') == true) ans = "No";
  cout << ans << endl;
  
  return 0;
}
 