#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  string s, t;
  cin >> s >> t;
  int ls = s.length(), lt = t.length();
  vector<vector<int>> cs(ls+1,vector<int>(2,0));
  vector<vector<int>> ct(lt+1,vector<int>(2,0));
  rep(i,ls) {
    if(s[i] == 'A') {
      cs[i+1][0] = cs[i][0] + 1;
      cs[i+1][1] = cs[i][1];
    } else {
      cs[i+1][0] = cs[i][0];
      cs[i+1][1] = cs[i][1] + 1;
    }
  }
  rep(i,lt) {
    if(t[i] == 'A') {
      ct[i+1][0] = ct[i][0] + 1;
      ct[i+1][1] = ct[i][1];
    } else {
      ct[i+1][0] = ct[i][0];
      ct[i+1][1] = ct[i][1] + 1;
    }
  }    
  int q;
  cin >> q;
  vector<bool> ans(q,true);
  rep(i,q) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x = cs[b][0] - cs[a-1][0] + (cs[b][1] - cs[a-1][1])*2;
    int y = ct[d][0] - ct[c-1][0] + (ct[d][1] - ct[c-1][1])*2;
    if((x-y) % 3) ans[i] = false;
  }
  for(auto x: ans) cout << (x ? "YES" : "NO") << endl;
  return 0;
}