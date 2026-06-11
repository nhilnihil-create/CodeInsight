#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

pair<int,int> dis[100005][11];

vector<pair<int,pair<int,int> > >fi[12];
int n;

void bfs()
{
    queue<int>qq;
    for(int i=10;i>=1;i--)
    {
        for(auto j:fi[i])
        {
            if(dis[j.first][i].first<j.second.first)
                dis[j.first][i]=j.second;
        }
        for(int j=1;j<=n;j++)
        {
            if(dis[j][i].first)
            {
               qq.push(j);
            }
        }
        while (!qq.empty())
        {
            int z=qq.front();
            qq.pop();
            for(auto j:adj[z])
            {
                if(dis[j][i-1].first<dis[z][i].first)
                    dis[j][i-1]=dis[z][i];
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

    int m;
    cin>>n>>m;
    int x,y;
    adj.resize(n+1);
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int q;
    cin>>q;

    int cnt=0;
    
    while (q--)
    {
        ++cnt;
        int v,d,c;
        cin>>v>>d>>c;        
        dis[v][d]={cnt,c};
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=10;j++)
        {
            if(dis[i][j].first)
            {
                fi[j].push_back({i,dis[i][j]});
            }
        }
    }    
    bfs();
    for(int i=1;i<=n;i++)
    {
        int mx=0;
        int ind=0;
        for(int j=0;j<=10;j++)
        {
            if(dis[i][j].first>mx)
            {
                mx=dis[i][j].first;
                ind=dis[i][j].second;
            }
        }
        cout<<ind<<'\n';
    }

} 
    
 