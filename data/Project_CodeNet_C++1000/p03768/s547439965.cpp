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

vector<int>adj[M+4];
int n,m,q;
int qv[M+4],qd[M+3],qc[M+4];
int dp[M+4][12];
void magic(int pos,int d,int c)
{
    if(dp[pos][d])return ;
    dp[pos][d]=c;
    if(d>0)
    {
        magic(pos,d-1,c);
        for(auto v:adj[pos])
        {
            magic(v,d-1,c);
        }
    }
}
 main()

{
    fast
    cin>>n>>m;
    f(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cin>>q;
    f(i,1,q)
    {
        int v,d,c;
        cin>>qv[i]>>qd[i]>>qc[i];
    }
    rf(i,q,1)
    {
        magic(qv[i],qd[i],qc[i]);
    }
    f(i,1,n)
    {
        cout<<dp[i][0]<<endl;
    }
















    return 0;

}











