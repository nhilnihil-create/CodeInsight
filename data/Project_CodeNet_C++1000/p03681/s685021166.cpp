#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;


ll fact(int x){
  ll ans=1;
  for(ll i=1; i<=x; i++) ans = ans*i%MOD;
  return ans;
}
int main(){
  int a, b; cin >> a >> b;
  ll ans=0;
if(abs(a-b)<=1){
    ans = fact(a)*fact(b)%MOD;
    if(a==b) ans = ans*2%MOD;
  }
  cout << ans << endl;
}
