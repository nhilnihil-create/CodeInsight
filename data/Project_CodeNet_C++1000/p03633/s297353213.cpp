#include<bits/stdc++.h>
using namespace std;
int64_t lcd(int64_t x,int64_t y){
  int64_t u,v,z;
  u=min(x,y);
  v=max(x,y);
  z=v%u;
  while(z>0){
    v=u;
    u=z;
    z=v%u;
  }
  return x/u*y;
}
int main(){
  int n,i;
  int64_t t,ans=1;
  cin>>n;
  for(i=0;i<n;i++){
    cin>>t;
    ans=lcd(ans,t);
  }
  cout<<ans<<endl;
}