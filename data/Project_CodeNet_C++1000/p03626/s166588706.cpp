#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main(){
  int n;
  cin >> n;
  char s[2][n];
  rep(i,n)cin >> s[0][i];
  rep(i,n)cin >> s[1][i];
  int i = 0;
  ll ans;
  bool to;
  if(s[0][0]==s[1][0]){
    ans = 3;
    i++;
    to = 0;
  }else{
    ans = 6;
    i+=2;
    to = 1;
  }
  while(i!=n){
    if(s[0][i]==s[1][i]){
      if(to == 0)ans *= 2;
      ans %= MOD;
      i++;
      to = 0;
    }else{
      if(to==0)ans *= 2;
      else ans *= 3;
      ans %= MOD;
      to = 1;
      i += 2;
    }
  }
  cout << ans << endl;
  return 0;
}
