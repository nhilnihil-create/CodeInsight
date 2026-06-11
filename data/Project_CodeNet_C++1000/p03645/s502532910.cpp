#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;
  vector<vector<int>> g(n+1);
  for(int i=0;i<m;i++)
  {
    int u,v;
    cin>>u>>v;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
   int size[n];
   size[0]=0;
   
   bool v[n]={0};
  auto bfs=[&](int src)
  {
    queue<int> q;
    q.push(0);

    while(!q.empty())
    {
      int x=q.front();
      q.pop();
      v[x]=1;

      for(auto i:g[x])
      {
        if(!v[i])
        {
          size[i]=size[x]+1;
          q.push(i);
        }
      }

    }


  };
  bfs(0);

  if(size[n-1]==2)
  cout<<"POSSIBLE"<<endl;
  else
  cout<<"IMPOSSIBLE"<<endl;

}