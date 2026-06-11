#include<bits/stdc++.h>
using namespace std;
int main(){
  int w,h,n;cin>>w>>h>>n;
  int x,y,a;
  int tmpx1=0,tmpx2=w,tmpy1=0,tmpy2=h;
  for(int i=0;i<n;i++){
    cin>>x>>y>>a;
    if(a==1){
      if(tmpx1<x)tmpx1=x;
    }
    else if(a==2){
      if(tmpx2>x)tmpx2=x;
    }
    else if(a==3){
      if(tmpy1<y)tmpy1=y;
    }
    else{
      if(tmpy2>y)tmpy2=y;
    }
  }
  if(tmpx2-tmpx1<=0||tmpy2-tmpy1<=0){
    cout <<0<<endl;
    return 0;
  }
  else{
    cout <<(tmpx2-tmpx1)*(tmpy2-tmpy1)<<endl;
  }
}