#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  string s; cin >> s;
  string ans = "";
  
  rep(i,s.size()){
    if(s[i] == 'B' && ans.size()>0) ans.erase(ans.end()-1,ans.end());
    else if(s[i] != 'B') ans += s[i];
  }

  cout << ans << endl;
  
  return 0;
}
