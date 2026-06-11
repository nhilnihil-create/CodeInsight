#include <bits/stdc++.h>
#include <vector>
#include<math.h>
#include<string.h>
using namespace std;
#define MAX 2003
#define MOD 1000000007
#define INF 1000000000000000000
#define EPS 0.0000000001
#define CHAINS 18
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
int k;
int dist[MAX];
vector<int> Graph[MAX];
vector<pair<int,int> > Edges;
int bfsNode(int root,int n,int d)
{
    int i,ans=n;
    for(i=1;i<=n;i++)
    {
        dist[i]=MAX*3;
    }
    queue<int> Nodes;
    int node=root;
    dist[node]=0;
    Nodes.push(node);
    while(!Nodes.empty())
    {
        node=Nodes.front();
        ans--;
        Nodes.pop();
        for(i=0;i<Graph[node].size();i++)
        {
            if(dist[node]+1>d) break;
            if(dist[Graph[node][i]]>dist[node]+1)
            {
                dist[Graph[node][i]]=dist[node]+1;
                Nodes.push(Graph[node][i]);
            }
        }
    }
    return ans;
}
int bfsEdge(pair<int,int> roots,int n,int d)
{
    int i,ans=n;
    for(i=1;i<=n;i++)
    {
        dist[i]=MAX*3;
    }
    queue<int> Nodes;
    int node=roots.first;
    dist[node]=0;
    Nodes.push(node);
    node=roots.second;
    dist[node]=0;
    Nodes.push(node);
    while(!Nodes.empty())
    {
        node=Nodes.front();
        ans--;
        Nodes.pop();
        for(i=0;i<Graph[node].size();i++)
        {
            if(dist[node]+1>d) break;
            if(dist[Graph[node][i]]>dist[node]+1)
            {
                dist[Graph[node][i]]=dist[node]+1;
                Nodes.push(Graph[node][i]);
            }
        }
    }
    return ans;
}
int main()
{
    int n;
    scanf("%d %d",&n,&k);
    int u,v,i;
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&u,&v);
        Graph[u].push_back(v);
        Graph[v].push_back(u);
        Edges.push_back(make_pair(u,v));
    }
    int ans=n;
    if(k%2)
    {
        for(i=0;i<n-1;i++)
        {
            ans=min(ans,bfsEdge(Edges[i],n,k/2));
        }
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            ans=min(ans,bfsNode(i,n,k/2));
        }
    }
    printf("%d",ans);
    return 0;
}
