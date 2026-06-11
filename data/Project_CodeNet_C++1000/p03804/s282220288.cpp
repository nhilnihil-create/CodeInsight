#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

char grid_a[55][55];
char grid_b[55][55];

int main(){
  int n,m;
  cin>>n>>m;
  rep(i,n)rep(j,n){
    cin>>grid_a[i][j];
  }
  rep(i,m)rep(j,m){
    cin>>grid_b[i][j];
  }
  bool ans=0;
  for(int i = 0; i < n-m+1; i++){
    for(int j = 0; j < n-m+1; j++){
      bool ok=1;
      rep(mi,m)rep(mj,m){
        if(grid_a[i+mi][j+mj]!=grid_b[mi][mj]) ok=0;
      }
      if(ok) ans=1;
    }
  }
  if(ans) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}

