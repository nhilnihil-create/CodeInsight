#include<bits/stdc++.h>
using namespace std;
#define int long long int 
vector<vector<array<int,2>>> g;
vector<int> cost;
void dfs(int src,int parent,int travel_cost)
{
    cost[src]=travel_cost;
    for(auto i:g[src])
    {
        if(i[0]==parent)continue;
        dfs(i[0],src,travel_cost+i[1]);
    }
}
int32_t main()
{
     int n;
     cin>>n;
     g=vector<vector<array<int,2>>>(n);
     for(int i=1;i<n;i++)
     {
         int x,y,z;
         cin>>x>>y>>z;
         x--;
         y--;
         g[x].push_back({y,z});
         g[y].push_back({x,z});
     } 
   
     cost=vector<int>(n,0);

      int q,k;
      cin>>q>>k;
      k--;

      dfs(k,-1,0);
      
      for(int i=1;i<=q;i++)
      {
          int x,y;
          cin>>x>>y;
          x--;
          y--;
          cout<<cost[x]+cost[y]<<endl;
      }


  


    return 0;
}