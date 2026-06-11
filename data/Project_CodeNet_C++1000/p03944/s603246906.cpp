#include <bits/stdc++.h>
using namespace std;

int main(){
  int w,h,n;
  cin >> w >> h >> n;
  int zx=0,nx=w,zy=0,ny=h;
  
  for(int i=0;i<n;i++){
    int x,y,a;
    cin >> x >> y >> a;
    if(a==1) zx=max(zx,x);
    else if(a==2) nx=min(nx,x);
    else if(a==3) zy=max(zy,y);
    else ny=min(ny,y);
  }
  
  cout << max(nx-zx,0)* max(ny-zy,0) << endl;
}