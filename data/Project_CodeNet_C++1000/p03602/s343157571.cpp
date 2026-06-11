#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
int main(){
  int n;
  cin>>n;
  ll graph[305][305]={0};
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++) cin>>graph[i][j];
  }
  ll ans=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      bool f=false;
      for(int k=0;k<n;k++){
        if(graph[i][j]>graph[i][k]+graph[k][j]){
          cout<<-1<<endl;
          return 0;
        }
        else if(graph[i][j]==graph[i][k]+graph[k][j]&&i!=k&&j!=k) f=true;
      }
      if(!f) ans+=graph[i][j];
    }
  }
  cout<<ans/2<<endl;
}
