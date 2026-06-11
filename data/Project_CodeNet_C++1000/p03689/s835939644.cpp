#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n=100000000;
  ll h,w,a,b;cin>>h>>w>>a>>b;
  ll ans[h][w];
  if(a==1&&b==1){
    cout<<"No"<<endl;
    return 0;
  }
  ll y=n/(a*b-1);
  for(ll i=0;i<h;i++)for(ll j=0;j<w;j++)ans[i][j]=y;
  for(ll i=a-1;i<h;i+=a)for(ll j=b-1;j<w;j+=b)ans[i][j]=-y*(a*b-1)-1;
  ll sum=0;
  for(ll i=0;i<h;i++)for(ll j=0;j<w;j++)sum+=ans[i][j];
  if(sum>0){
    cout<<"Yes"<<endl;
    for(ll i=0;i<h;i++){
      for(ll j=0;j<w;j++)cout<<ans[i][j]<<" ";
      cout<<endl;
    }
  }
  else{
    cout<<"No"<<endl;
  }
}