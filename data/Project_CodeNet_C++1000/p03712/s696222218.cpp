#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int h,w;cin>>h>>w;
  vector<vector<char>> a(h,vector<char>(w));
  rep(i,h)rep(j,w)cin>>a[i][j];
  rep(i,w+2){
    cout<<'#';
    if(i==w+1)cout<<endl;
  }
  rep(i,h)rep(j,w){
    if(j==0)cout<<'#';
    cout<<a[i][j];
    if(j==w-1)cout<<'#'<<endl;
  }
  rep(i,w+2){
    cout<<'#';
    if(i==w+1)cout<<endl;
  }
}