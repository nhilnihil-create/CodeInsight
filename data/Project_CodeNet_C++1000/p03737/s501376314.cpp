#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  vector<string> s(3); rep(i,3) cin >> s[i];
  string ans = "";

  rep(i,3)
    ans+=s[i][0];

  transform(ans.begin(),ans.end(),ans.begin(),::toupper);
  cout << ans << endl;
  
  return 0;
}
