#include<bits/stdc++.h>
using namespace std;
int main(){
  int w,h,n;
  cin>>w>>h>>n;
  int xl=0,xg=w,yl=0,yg=h;
  for(int i=0;i<n;i++){
    int x,y,a;
    cin>>x>>y>>a;
    if(a==1)
      xl=max(xl,x);
    if(a==2)
      xg=min(xg,x);
    if(a==3)
      yl=max(yl,y);
    if(a==4)
      yg=min(yg,y);
  }
  cout<<max(xg-xl,0)*max(yg-yl,0)<<endl;
}