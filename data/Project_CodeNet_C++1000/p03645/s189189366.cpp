#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define            ll              long long
#define            pb              push_back
#define            mp              make_pair
#define            loop(i,a,n)     for(int i=a;i<=n;++i)
#define            clr(x)          memset(x,0,sizeof x)
#define            min3(a,b,c)     min(a,min(b,c))
#define            max3(a,b,c)     max(a,max(b,c))
#define            min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define            max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define            fast            ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define            pii             pair<int,int>
#define            pll             pair<ll,ll>
#define            pli             pair<ll,int>
#define            pil             pair<int,ll>
#define            FF              first
#define            SS              second
#define            PI              acos(-1.0)
#define            bug             cout<<"ok"<<endl;

using namespace std;
using namespace __gnu_pbds;

typedef tree<int , null_type,less<int>,
       rb_tree_tag, tree_order_statistics_node_update> anik;

const int MOD = 1e9 + 7;
const ll MX= 1e9;
const ll INF = 1e9;
vector<int>adj[200009];
bool visited[200009];
int n,m;
bool dfs(int s)
{    visited[s]=true;
    for(int i=0;i<adj[s].size();i++)
    {
        if(visited[adj[s][i]]==false)
        {
            int p=adj[s][i];
            for(int j=0;j<adj[p].size();++j)
                if(adj[p][j]==n)return 1;
        }
    }
    return 0;
}

main()
{
   cin>>n>>m;

   for(int i=0;i<m;++i)
   {
       int x,y;
       cin>>x>>y;
       adj[x].pb(y);
       adj[y].pb(x);
   }
   bool ok=dfs(1);
   if(ok==1)cout<<"POSSIBLE"<<endl;
   else
    cout<<"IMPOSSIBLE"<<endl;
}

