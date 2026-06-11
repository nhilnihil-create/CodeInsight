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

int a[M+5];
vector<int>adj[M+7];
bool dfs(int u,int par)
{
    int sum=0;
    int big=0;
    for(auto v:adj[u])
    {
        if(v==par)continue;
        if(!dfs(v,u))return false;
        sum+=a[v];
        big=max(big,a[v]);
    }
    if(adj[u].size()==1)return true;
    int gap=2*a[u]-sum;
    big=max(big,gap);
    if(gap>=0 && big<=a[u])
    {
        a[u]=gap;
        return true;
    }
    else return false;
}
 main()

{
    fast
    int n;
    cin>>n;
    f(i,1,n)
    {
        cin>>a[i];
    }
    if(n==2)
    {
        if(a[1]==a[2])
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        return 0;
    }
    f(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i=1;i<=n;i++)
    {
        if(adj[i].size()<=1)continue;
        if(dfs(i,-1) && a[i]==0)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        return 0;
    }

}











