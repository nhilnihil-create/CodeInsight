#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// mt19937 gen_rand_int(chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 gen_rand_ll(chrono::steady_clock::now().time_since_epoch().count());
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

vector<vector<int> >adj;
int vis[100005];
int ind=1;
int parent[100005];

void dfs(int ver,int pr)
{
    parent[ver]=pr;
    vis[ver]=1;
    int cnt=0;
    for(auto i:adj[ver])
    {
        if(!vis[i])
        {
            ++cnt;
            dfs(i,ver);
        }
        else if(vis[i]==2)
        {
            cnt++;
        }
    }
    vis[ver]=2;
    if(cnt==0)
    {
        ind=ver;
        return ;
    }
}

vector<int>path;
int fi=0;
void dfs2(int ver,int pr)
{
    if(fi)
        return ;
    vis[ver]=1;
    parent[ver]=pr;
    int x=0;
    if(!path.empty())
    {
        x=path.back();
        path.pop_back();
        dfs2(x,ver);
    }

    int cnt=0;
    for(auto i:adj[ver])
    {
        if(x!=0 && i==x)
            continue;
        if(!vis[i])
        {
            ++cnt;
            dfs2(i,ver);
        }
        else if(vis[i]==2)
        {
            cnt++;
        }
    }

    if(cnt==0 && fi==0)
    {
        fi=ver;
        return ;
    }
    vis[ver]=2;
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

    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    int x,y;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    dfs(1,0);
    int ini=ind;
    while (ini!=1)
    {
        path.push_back(ini);
        ini=parent[ini];
    }
    path.push_back(1);
    fill_n(vis,n+1,0);
    reverse(path.begin(),path.end());
    x=path.back();
    path.pop_back();
    dfs2(x,0);
    path.clear();
    while (fi!=ind)
    {
        path.push_back(fi);
        fi=parent[fi];
    }
    path.push_back(fi);
    cout<<path.size()<<'\n';
    for(auto i:path)
        cout<<i<<" ";

} 
    