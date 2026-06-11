#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int w,h,n;
  cin>>w>>h>>n;
  bool grid[h][w];
  rep(hi,h)rep(wi,w){
    grid[hi][wi]=0;
  }
  rep(i,n){
    int x, y, a;
    cin>>x>>y>>a;
    if(a==1){
      x--;
      for(int wi=x; wi>=0; wi--){
        rep(hi,h){
          grid[hi][wi]=1;
        }
      }
    }
    if(a==2){
      for(int wi=x; wi<w; wi++){
        rep(hi,h){
          grid[hi][wi]=1;
        }
      }
    }
    if(a==3){
      y--;
      for(int hi=y; hi>=0; hi--){
        rep(wi,w){
          grid[hi][wi]=1;
        }
      }
    }
    if(a==4){
      for(int hi=y; hi<h; hi++){
        rep(wi,w){
          grid[hi][wi]=1;
        }
      }
    }
  }
  int ans=0;
  rep(hi,h)rep(wi,w){
    if(!grid[hi][wi]) ans++;
  }
  cout<<ans<<endl;
}
