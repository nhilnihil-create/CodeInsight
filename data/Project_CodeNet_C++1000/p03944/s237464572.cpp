#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){ 
  int w,h,n;
  cin >>w>>h >> n;
  vector<int> x(n),y(n),a(n);
  rep(i,n){
    cin >>x.at(i)>>y.at(i)>>a.at(i);
  }
  int rx=w,lx=0,uy=h,sy=0;
  rep(i,n){
    if(a.at(i)==1){
      lx=max(lx,x.at(i));
    }else if(a.at(i)==2){
      rx=min(rx,x.at(i));
    }else if(a.at(i)==4){
      uy=min(uy,y.at(i));
    }else{
      sy=max(sy,y.at(i));
    }
  }
  if(rx-lx<=0 || uy-sy<=0){
    cout << 0;
    return 0;
  }
  cout << (rx-lx)*(uy-sy);
}