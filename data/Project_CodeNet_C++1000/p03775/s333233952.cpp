#include <iostream>
#include <math.h>
#include <algorithm>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using namespace std;

ll chmin(ll a,ll b){
  if(a>b){a = b;}
  return a;
}

int main(){
  ll n,ans=100;
  cin >> n;
  
  for(ll i=1; (i*i)<=n; i++){
    ll count=1;
    if(n%i == 0){
      ll m = n/i;
      while(m>=10){
        m /= 10;
        count++;
      }
      ans = chmin(ans,count);
    }
  }
  
  cout << ans << endl;
  
  return 0;
}
