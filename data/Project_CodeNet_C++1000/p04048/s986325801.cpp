#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,k,ans = 0,z;cin >> n >> k;
  ans += n;
  ll x = max(k,n-k),y = min(k,n-k);
  while(y){
    ans += (x/y)*2*y-(x%y==0 ? y:0);
    z = x%y;
    x = y;y = z;
  }
  cout << ans << "\n";
}