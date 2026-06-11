#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
const ll INF = 10e9;

int main(){
  string s; cin>>s;
  int len = s.size();
  ll ans = 0;
  rep(bit, 1<<len-1){
    ll tmp = 0;
    rep(i,len-1){
      tmp *= 10;
      tmp += s[i]-'0';
      if  (bit & (1<<i)){
        ans += tmp;
        tmp = 0;
      }
    }
    tmp *= 10;
    tmp += s[len-1]-'0';
    ans += tmp;
  }
  cout << ans << endl;
}