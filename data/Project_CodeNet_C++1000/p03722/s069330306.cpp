#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

long long power(long long a, long long b,long long m) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a %m;
        a = a * a %m;
        b >>= 1;
    }
    return res;
}

vector<vector<pair<int,int> > >adj,adj2;
int dis[1005];
int n;
int mm1[1005],mm2[1005];
void dfs(int ver)
{
    mm1[ver]=1;
    for(auto i:adj[ver])
    {
        if(!mm1[i.first])
        {
            dfs(i.first);
        }
    }
}

void dfs2(int ver)
{
    mm2[ver]=1;
    for(auto i:adj2[ver])
    {
        if(!mm2[i.first])
        {
            dfs2(i.first);
        }
    }
}

int cnt[1004];

void dik()
{
    priority_queue<pair<int,int> >qq;
    qq.push({0,1});
    dis[1]=0;
    while (!qq.empty())
    {
        pair<int,int>pp=qq.top();
        qq.pop();
        if(dis[pp.second]>pp.first)
            continue;
        for(auto i:adj[pp.second])
        {
            if(dis[i.first]<pp.first+i.second && mm1[i.first])
            {
                cnt[i.first]++;
                if(cnt[i.first]>2000)
                    return ;
                dis[i.first]=pp.first+i.second;
                qq.push({dis[i.first],i.first});
            }
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

    fill_n(dis,1005,-1e17);
    int m;
    cin>>n>>m;
    adj.resize(n+1);
    adj2.resize(n+1);
    int x,y,z;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
        adj2[y].push_back({x,z});
    }    
    dfs(1);
    dfs2(n);
    for(int i=1;i<=n;i++)
    {
        if(mm1[i]&&mm2[i])
        {
            mm1[i]=1;
        }
        else
        {
            mm1[i]=0;
        }        
    }
    dik();
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]>2000)
        {
            cout<<"inf";
            return 0;
        }
    }
    cout<<dis[n];
}       
