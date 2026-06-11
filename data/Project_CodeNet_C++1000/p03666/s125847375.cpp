#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,a,b,c,d;cin>>n>>a>>b>>c>>d;
  for(ll i=0;i<=n-1;i++){
    ll j=a-c*i;
    ll k=a-d*i;
    j+=d*(n-1-i);
    k+=c*(n-1-i);
    if(j>=b&&k<=b){
      cout<<"YES"<<endl;
      return 0;
    }
  }
  cout<<"NO"<<endl;
}