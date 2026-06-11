#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  string s; cin >> s;

  int x = 0;
  int ans = 0;
  rep(i,s.size()){
    if(s[i] == 'I') x++;
    else if(s[i] == 'D') x--;
    ans = max(ans,x);
  }

  cout << ans << endl;
  
  return 0;
}
