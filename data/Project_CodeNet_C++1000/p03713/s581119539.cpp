#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t h,w,x,y,z,v,d,ans;
  cin>>h>>w;
  if(h%3==0||w%3==0) cout<<0<<endl;
  else{
    x=h/3*w;
    v=h-h/3;
    if(v%2==0||w%2==0){
      y=v*w/2;
      z=y;
    }
    else{
      y=max(v,w)/2*min(v,w);
      z=v*w-y;
    }
    ans=max(x,max(y,z))-min(x,min(y,z));
    
    x=(h/3+1)*w;
    v=h-h/3-1;
    if(v%2==0||w%2==0){
      y=v*w/2;
      z=y;
    }
    else{
      y=max(v,w)/2*min(v,w);
      z=v*w-y;
    }
    d=max(x,max(y,z))-min(x,min(y,z));
    ans=min(ans,d);
    
    x=h*(w/3);
    v=w-w/3;
    if(h%2==0||v%2==0){
      y=h*v/2;
      z=y;
    }
    else{
      y=max(h,v)/2*min(h,v);
      z=h*v-y;
    }
    d=max(x,max(y,z))-min(x,min(y,z));
    ans=min(ans,d);
    
    x=h*(w/3+1);
    v=w-w/3-1;
    if(h%2==0||v%2==0){
      y=h*v/2;
      z=y;
    }
    else{
      y=max(h,v)/2*min(h,v);
      z=h*v-y;
    }
    d=max(x,max(y,z))-min(x,min(y,z));
    ans=min(ans,d);
    
    cout<<ans<<endl;
  }
}