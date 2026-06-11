#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

vector<int> g[2020];
bool used[2020];
int lim;

void dfs(int now,int d){
  if(d>lim) return;
  used[now]=true;
  for(int i=0;i<g[now].size();i++){
    int u=g[now][i];
    if(used[u]) continue;
    dfs(u,d+1);
  }
  return;
}

int main(){
  int n,k;
  cin>>n>>k;
  vector<pair<int,int>> edge;
  for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
    edge.push_back(make_pair(a,b));
  }

  int ans=n;
  lim=k/2;
  if(k%2==0){
    for(int i=1;i<=n;i++){
      for(int j=0;j<=n;j++) used[j]=false;
      dfs(i,0);

      int cnt=0;
      for(int j=1;j<=n;j++){
        if(!used[j]) cnt++;
      }
      ans=min(ans,cnt);
    }
  }else{
    for(int i=0;i<n-1;i++){
      bool used1[n+1];
      for(int j=0;j<=n;j++){
        used[j]=false;
        used1[j]=false;
      }
      dfs(edge[i].first,0);
      for(int j=1;j<=n;j++){
        used1[j]=used[j];
        used[j]=false;
      }
      dfs(edge[i].second,0);

      int cnt=0;
      for(int j=1;j<=n;j++){
        if(!used[j]&&!used1[j]) cnt++;
      }
      ans=min(ans,cnt);
    }
  }

  cout<<ans<<endl;

  return 0;
}
