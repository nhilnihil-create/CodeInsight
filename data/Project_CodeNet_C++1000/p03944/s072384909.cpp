#include<bits/stdc++.h>
using namespace std;

int main(){

  int W,H,N,i;
  cin>>W>>H>>N;
  int xl=0, xr=W, yd=0, yu=H;
  
  for(i=0; i<N; i++){
    int x,y,a;
    cin>>x>>y>>a;
    switch(a){
      case 1:
        xl=max(xl,x);
        break;
      case 2:
        xr=min(xr,x);
        break;
      case 3:
        yd=max(yd,y);
        break;
      case 4:
        yu=min(yu,y);
        break;
      default:
        break;
    }
  }
  if(xr-xl<=0 || yu-yd<=0){
    cout<<0<<endl;
    return 0;
  }
  cout<<(xr-xl)*(yu-yd)<<endl;
  return 0;
}