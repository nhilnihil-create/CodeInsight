#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,a,b,c,d;
  cin>>n>>a>>b>>c>>d;
  ll ans=b-a;
  for(ll i=0;i<n;i++){
    ll l1=c*i,r1=d*i;
    ll l2=c*(n-i-1)+ans,r2=d*(n-i-1)+ans;
    if(l1<=r2&&l2<=r1){
      cout<<"YES"<<endl;
      return 0;
    }
  }
  cout<<"NO"<<endl;
  return 0;
}
