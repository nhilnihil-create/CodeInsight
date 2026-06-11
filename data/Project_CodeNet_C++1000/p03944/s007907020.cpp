#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int W,H,N;
  cin >> W >> H >> N;
  
  int x,y,a;
  int lx=0,ly=0,rx=W,ry=H;
  for(int i=0; i<N; i++){
    cin >> x >> y >> a;
    
    if(a==1){
      lx = max(lx,x);
    }
    
    else if(a==2){
      rx = min(rx,x);
    }
    
    else if(a==3){
      ly = max(ly,y);
    }
    
    else if(a==4){
      ry = min(ry,y);
    }
  
  }

  int ans=0;
  if(lx > rx || ly > ry){
    ans = 0;
  }
  else{ 
    ans = (rx-lx) * (ry-ly);
  }
  
  cout << ans << endl;

}