#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n,m,r;
  cin>>n>>m>>r;
  int vec[r];
  for(int i=0;i<r;i++){
    cin>>vec[i];
  }
  ll path[n][n];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==j){
        path[i][j]=0;
      }
      else{
        path[i][j]=1e10;
      }
    }
  }
  int a,b;
  ll c;
  for(int i=0;i<m;i++){
    cin>>a>>b>>c;
    a--;
    b--;
    path[a][b]=min(path[a][b],c);
    path[b][a]=min(path[a][b],path[b][a]);
  }
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        path[i][j]=min(path[i][j],path[i][k]+path[k][j]);
      }
    }
  }    
  vector<int> one_case;
  for(int i=0;i<r;i++){
    one_case.emplace_back(i);
  }
  ll ans=1e10,p=0;
  do{
    p=0;
    for(int i=0;i<r-1;i++){
      p+=path[vec[one_case.at(i)]-1][vec[one_case.at(i+1)]-1];
    }
    ans=min(ans,p);
  }while(next_permutation(one_case.begin(),one_case.end()));
  cout<<ans<<endl;
}