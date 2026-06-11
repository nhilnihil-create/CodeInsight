#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


vector<vector<int> >adj;
int sz[100005];
int parent[100005];
int dis[100005];
void dfs(int ver,int pr,int x)
{
    dis[ver]=x;
    sz[ver]++;
    parent[ver]=pr;
    for(auto i:adj[ver])
    {
        if(i!=pr)
        {
            dfs(i,ver,x+1);
            sz[ver]+=sz[i];
        }
    }
}

signed main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   

#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
#endif  

    int n;
    cin>>n;
    adj.resize(n+1);
    int x,y;
    for(int i=0;i<n-1;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,0,0);
    int z=(dis[n]-1)/2;
    int ini=n;
    while (z--)
    {
        ini=parent[ini];
    }
    x=n-sz[ini];
    y=sz[ini];

    if(x>y)
    {
        cout<<"Fennec";
    }
    else
    {
        cout<<"Snuke";
    }
    
        
} 

