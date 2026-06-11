#include<bits/stdc++.h>
using namespace std;
int main(){
  int w,h,n,x,y,z,j,x1=0,x2,y1=0,y2;
  cin>>w>>h>>n;
  x2=w;
  y2=h;
  for(j=0;j<n;j++){
    cin>>x>>y>>z;
    if(z==1) x1=max(x1,x);
    else if(z==2) x2=min(x2,x);
    else if(z==3) y1=max(y1,y);
    else if(z==4) y2=min(y2,y);
  }
  if(x1<x2&&y1<y2) cout<<(x2-x1)*(y2-y1)<<endl;
  else cout<<0<<endl;
}