#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,max_v=0,ans=0;
  cin>>n;
  for(int i=0;i<n;i++){
    ll a;
    cin>>a;
    ans+=(a-1)/(max_v+1);
    if(a==max_v+1||max_v==0) max_v++;
  }
  cout<<ans<<endl;
}
