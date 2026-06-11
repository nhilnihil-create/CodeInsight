#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

int main() {
  int n,a;
  cin>>n>>a;
  vector<int>x(n);
  
  rep(i,n){
    cin>>x.at(i);
  }
  vector<vector<vector<long>>> ans(n+1, vector<vector<long>>(n+1, vector<long>(2501)));
  rep(i,n+1){
    rep(j,n+1){
      rep(k,2501){
        if(i==0&&j==0&&k==0){
          ans[i][j][k]=1;
        }
        else if(i>=1&&k<x[i-1]){
          ans[i][j][k]=ans[i-1][j][k];
        }
        else if(i>=1&&j>=1&&k>=x[i-1]){
          ans[i][j][k]=ans[i-1][j][k]+ans[i-1][j-1][k-x[i-1]];
        }
        else{
          ans[i][j][k]=0;
        }
      }
    }
  }
  long to=0;
  rep2(j,1,n+1){
    to+=ans[n][j][j*a];
  }
   
  cout<<to<<endl;
}


