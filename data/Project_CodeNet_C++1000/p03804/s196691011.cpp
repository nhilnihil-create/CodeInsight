#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  int n,m;
  cin >> n >> m;
  char s[n][n],t[m][m];
  rep(i,n){
    rep(j,n){
      cin >> s[i][j];
    }
  }
  rep(i,m){
    rep(j,m){
      cin >> t[i][j];
    }
  }
  int i,j,k,l;
  string ans="No";
  for(i=0;i<n-m+1;i++){
    for(j=0;j<n-m+1;j++){
      bool is=true;
      for(k=0;k<m;k++){
        for(l=0;l<m;l++){
          if(s[i+k][j+l]!=t[k][l]){
            is=false;
          }
        }
      }
      if(is){
        ans="Yes";
      }
    }
  }
  cout << ans;
}