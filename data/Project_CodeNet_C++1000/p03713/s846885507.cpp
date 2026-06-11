#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  ll h,w;
  cin>>h>>w;
  if(h%3==0 || w%3==0){
    cout<<0<<endl;
  }
  /*else if(h==2 && w==2){
    cout<<1<<endl;
  }
  else if(h==2 || w==2){
    cout<<2<<endl;
  }*/
  else{
    ll ans=min(h,w);
    ll x,y,z;
    x=(h/3)*w;
    y=(h-h/3)*(w/2);
    z=(h-h/3)*(w-w/2);
    ans=min(ans,max(x,max(y,z))-min(x,min(y,z)));
    
    x=(h/3+1)*w;
    y=(h-h/3-1)*(w/2);
    z=(h-h/3-1)*(w-w/2);
    ans=min(ans,max(x,max(y,z))-min(x,min(y,z)));
    
    x=(w/3)*h;
    y=(w-w/3)*(h/2);
    z=(w-w/3)*(h-h/2);
    ans=min(ans,max(x,max(y,z))-min(x,min(y,z)));
    
    x=(w/3+1)*h;
    y=(w-w/3-1)*(h/2);
    z=(w-w/3-1)*(h-h/2);
    ans=min(ans,max(x,max(y,z))-min(x,min(y,z)));
    
    cout<<ans<<endl;
  }
}