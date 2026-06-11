#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
ll MOD=1000000007;

int main(){
  string s;
  cin >> s;
  ll ans = 0;
  rep(bit, 1<<(s.size()-1)){
    ll tmp = 0;
    rep(i,s.size()-1){
      tmp *= 10;
      tmp += s[i]-'0';
      if (bit & (1<<i)) ans += tmp, tmp=0;
    }
    tmp *= 10;
    tmp += s.back() - '0';
    ans += tmp;
  }
  cout << ans << endl;
}