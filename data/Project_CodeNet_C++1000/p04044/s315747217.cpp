#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n,l; cin >> n >> l;
  vector<string> s(n); rep(i,n) cin >> s[i];

  sort(s.begin(),s.end());

  string ans = "";
  rep(i,n){
    rep(j,l) ans+=s[i][j];
  }

  cout << ans << endl;
  
  return 0;
}
