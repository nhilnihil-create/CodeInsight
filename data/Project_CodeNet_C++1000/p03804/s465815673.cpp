#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;



int main(){
  int n,m;
  cin >>n >>m;
  char g[n][n],h[m][m];
  rep(i,n)rep(ii,n)cin >>g[i][ii];
  rep(i,m)rep(ii,m)cin >>h[i][ii];

  rep(i,n-m+1)rep(r,n-m+1){
    int ans=0;
    for(int ii=i;ii<m+i;ii++){
      for(int iii=r;iii<m+r;iii++){
        if(g[ii][iii]==h[ii-i][iii-r])ans++;
      }
    }
    if(ans==m*m){cout << "Yes" << endl; return 0;}
  }
  cout << "No" << endl;
}