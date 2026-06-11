#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)j; i<(int)n; i++) 
int main() {
  const int max=50;
  int n,m; cin>>n>>m;
  string a[max],b[max];
  rep(i,0,n) cin>>a[i];
  rep(i,0,m) cin>>b[i];
  bool exist=false;
  rep(ax,0,n-m+1){
    rep(ay,0,n-m+1){
      bool match=true;
      rep(by,0,m){
        if(a[by+ay].substr(ax,m)!=b[by]){
          match=false;
          break;
        }
      }
      if(match){
        cout<<"Yes";
        return 0;
      }
    }
  }
  cout<<"No";
  return 0;
}