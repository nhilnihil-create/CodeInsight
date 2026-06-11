#include <bits/stdc++.h>
using namespace std;

int main() {
  int w,h,n;
  cin>>w>>h>>n;
  int x1=0,y1=0,x2=w,y2=h;
  for(int i=0;i<n;i++){
    int x,y,a;
    cin>>x>>y>>a;
    if(a==1)x1=max(x1,x);
    else if(a==2)x2=min(x2,x);
    else if(a==3)y1=max(y1,y);
    else y2=min(y2,y);
  }
  if(x2-x1<=0||y2-y1<=0)cout<<0<<endl;
  else cout<<(x2-x1)*(y2-y1)<<endl;
  return 0;
}
  