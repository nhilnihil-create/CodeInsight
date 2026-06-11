#include <bits/stdc++.h>
using namespace std;
vector<int> g[100005];
int a,b,n,ans=0;
int Fennec[100005];
int Sunuke[100005];
void dfs(int r,int d,int f,int dist[])
{
  dist[r]=d;
  for(int i=0;i<g[r].size();i++){
    if(g[r][i] != f) dfs(g[r][i],d+1,r,dist); 
  }
}
int main()
{
  cin>>n;
  for(int i=0;i<n-1;i++){
    cin>>a>>b;
    a--,b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0,0,-1,Fennec);
  dfs(n-1,0,-1,Sunuke);
  for(int i=0;i<n;i++) if(Fennec[i]<=Sunuke[i]) ans++;
    else ans--;
  printf("%s\n",(ans>0)?"Fennec":"Snuke");
  return 0;
}
