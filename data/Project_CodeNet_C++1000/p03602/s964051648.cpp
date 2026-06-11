#include <bits/stdc++.h>
#define int long long
int g[300][300];
int c[300][300];
using namespace std;

signed main(){
  int N;
  cin>>N;
  int ans=0;
  int out=0;
  for(int i=0;i<N;i++)for(int j=0;j<N;j++)cin>>g[i][j];
  for(int i=0;i<N;i++)for(int j=0;j<N;j++)c[i][j]=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<i;j++){
      ans+=g[i][j];
    }
  }
  for(int k=0;k<N;k++){
    for(int i=0;i<N;i++){
      for(int j=0;j<i;j++){
        if(g[i][j]>g[i][k]+g[k][j])out++;
        if(k!=i&&k!=j&&i!=j&&c[i][j]==0)if(g[i][j]==g[i][k]+g[k][j]){c[i][j]++;ans-=g[i][j];}
      }
    }
  }
  if(out)cout<<-1<<endl;
  else cout<<ans<<endl;
}
