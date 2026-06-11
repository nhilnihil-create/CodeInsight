#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,m;cin>>n>>m;
  vector<vector<char>> a(n,vector<char>(n)),b(m,vector<char>(m));
  rep(i,n)rep(j,n)cin>>a[i][j];
  rep(i,m)rep(j,m)cin>>b[i][j];
  rep(i,n-m+1)rep(j,n-m+1){
    bool ans=true;
    rep(k,m)rep(l,m){
      if(a[i+k][j+l]!=b[k][l])ans=false;
    }
    if(ans){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
}