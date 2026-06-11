#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  ll n,k;
  cin>>n>>k;
  ll a[n+1]={};
  ll b[n+1]={};
  ll ans=0;
  for(int i=0;i<n;i++){
    cin>>a[i]>>b[i];
    if((a[i]|k)==k) ans+=b[i];
  }

  for(int i=30;i>=0;i--){
    if(((1<<i)&k)==0) continue;
    ll x=(k/(1<<i)-1)*(pow(2,i))+pow(2,i)-1;
    //cout<<x<<endl;
    ll tmp=0;
    for(int i=0;i<n;i++){
      if((a[i]|x)==x) tmp+=b[i];
    }
    ans=max(ans,tmp);
  }

  cout<<ans<<endl;
  return 0;
}
