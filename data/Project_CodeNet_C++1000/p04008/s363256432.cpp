///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define                           int                         long long
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<int,int>
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




using namespace std;

const int inf=1e18;
const int mod=1e9+7;
const int M=100009;
inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}

vector<int>adj[M+3];
int ses=0;
int vis[M+5];
int n,k;
int dfs(int u)
{
     vis[u]=1;
     int mx=-1;
     for(auto v:adj[u])
     {
         if(vis[v])continue;
         int d=dfs(v);
         if(u!=1 && d==k-1)
         {
             ses++;
         }
         else
         {
             mx=max(mx,d);
         }
     }
     return (mx+1);
}
 main()

{
    fast
    cin>>n>>k;
    f(i,1,n)
     {
         int x;
         cin>>x;
         if(i==1)
         {
             if(x!=1)ses++;
             continue;
         }
         if(x==i)continue;
         adj[x].pb(i);
     }
     dfs(1);
     cout<<ses<<endl;
     return 0;
}
