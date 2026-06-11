#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  ll x,y;
  cin>>x>>y;
  ll ans=1e10;
  if(y>=x){
    ans=min(ans,y-x);
  }
  ll a,b;
  if(-y>=x){
    ans=min(ans,1-y-x);
  }
  if(y>=-x){
    ans=min(ans,1+y+x);
  }
  if(x>=y){
    ans=min(ans,2+x-y);
  }
  cout<<ans<<endl;
}