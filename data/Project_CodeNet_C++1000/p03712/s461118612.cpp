#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int h,w;cin>>h>>w;
  vector<vector<char>> a(h,vector<char>(w));
  rep(i,h)rep(j,w)cin>>a[i][j];
  rep(i,w+2)cout<<'#';
  cout<<endl;
  rep(i,h){
    cout<<'#';
    rep(j,w){
      cout<<a[i][j];
    }
    cout<<'#'<<endl;
  }
  rep(i,w+2)cout<<'#';
  cout<<endl;
}