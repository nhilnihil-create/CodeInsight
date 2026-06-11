#include <bits/stdc++.h>
using namespace std;

int main(){
  int x,y;cin >> x >> y;
  int ans = -1;
  if(x<=y){
    if(ans==-1){
      ans = y - x;
    }else{
      ans = min(ans,y-x);
    }
  }
  if(-x<=y){
    if(ans==-1){
      ans = y + x+1;
    }else{
      ans = min(ans,y+x+1);
    }
  }
  if(x<=-y){
    if(ans==-1){
      ans = -y - x+1;
    }else{
      ans = min(ans,-y-x+1);
    }
  }
  if(-x<=-y){
    if(ans==-1){
      ans = -y + x+2;
    }else{
      ans = min(ans,-y+x+2);
    }
  }
  cout << ans << endl;
}