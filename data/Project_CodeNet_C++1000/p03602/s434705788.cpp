#include "bits/stdc++.h"
using namespace std;
long long mod=1e9+7;
#define int long long

signed main(){
  int n;
  cin>>n;
  vector<vector<int> > a(n,vector<int>(n));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)cin>>a[i][j];
  }
  vector<vector<int> > wf(n,vector<int>(n,1));
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(k!=i&&k!=j){
          if(a[i][j]>a[i][k]+a[k][j]){
            cout<<-1<<endl;
            return 0;
          }else if(a[i][j]==a[i][k]+a[k][j]){
            wf[i][j]=0;
          }
        }
        //wf[i][j]=min(wf[i][j],wf[i][k]+wf[k][j]);
      }
    }
  }
/*
  //vector<vector<int> > ans()
  vector<tuple<int,int,int> > cvu;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cvu.push_back(make_tuple(a[i][j],i,j));
    }
  }
  sort(cvu.begin(),cvu.end());
*/
  int ans=0;
  /*
  for(int i=0;i<cvu.size();i++){
    int x=get<0>(cvu[i]);
    int y=get<1>(cvu[i]);
    int z=get<2>(cvu[i]);
    if(wf[y][z]<x){
      cout<<-1<<endl;
      return 0;
    }
    if(wf[y][z]>x){
      ans+=x;
    }
  }
  */
  for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
      if(wf[i][j])ans+=a[i][j];
    }
  }
  cout<<ans<<endl;
}
