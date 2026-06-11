#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)j; i<(int)n; i++)
int main() {
  int h,w; cin>>h>>w;
  char c[h][w];
  rep(i,0,h){
    rep(j,0,w) cin>>c[i][j];
  }
  rep(i,0,h){
    rep(j,0,w) cout<<c[i][j];
    cout<<endl;
    rep(j,0,w) cout<<c[i][j];
    cout<<endl;
  }
}