#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  string s;
  cin >> s;
  reverse(s.begin(),s.end());
  int ans = 1e9;
  rep(i,0,26){
    bool df = true;
    int dc = 0,cc = 0,tmp = 0;
    rep(j,0,s.size()){
      if(s[j] == 'a'+i){
        if(df) df = false;
        else{
          cc = max(cc,tmp);
          tmp = 0;
        }
        continue;
      }
      if(df) dc++;
      else tmp++;
    }
    if(df) continue;
    cc = max(cc,tmp);
    int ta = max(cc,dc);
    //cout << cc << " " << dc << " " << ta << endl;
    ans = min(ans,ta);
  }
  cout << ans << endl;
}