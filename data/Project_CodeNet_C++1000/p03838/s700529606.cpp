#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int x,y;
  cin>>x>>y;
  int ans;
  if(x<y){
    if(x<0 && y>0){
      if(abs(x) < abs(y)) ans=y-x*-1+1;
      else ans=y*-1-x+1;
    }else{
      ans=y-x;
    }
  }else{
    if(y>0 || x<0) ans=y*-1 - x*-1 + 2;
    else if(abs(y) < abs(x)) ans=y-x*-1+1;
    else ans=y*-1-x+1;
  }
  cout<<ans<<endl;
}
