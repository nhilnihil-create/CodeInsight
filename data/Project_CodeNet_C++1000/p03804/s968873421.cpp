#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,m;cin>>n>>m;
  vector<vector<char>>a(100,vector<char>(100));
  vector<vector<char>>b(100,vector<char>(100));
  rep(i,n)rep(j,n)cin>>a[i][j];
  rep(i,m)rep(j,m)cin>>b[i][j];
  bool ans=false;
  rep(i,n)rep(j,n){
    if(a[i][j]==b[0][0]){
      int cnt=0;
      rep(k,m)rep(l,m){
        if(a[i+k][j+l]==b[k][l])cnt++;
        }
        if(cnt==m*m)ans=true;
    }
  }
  if(ans)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}