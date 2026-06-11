/*
********************
Author : Sahil Kundu
********************
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mod 1000000007
#define pb(i) push_back(i)
#define f first
#define s second
#define mk(l,r) make_pair(l,r)
#define all(vc) vc.begin(),vc.end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ms(i,j) memset(i,j,sizeof i)
#define w(t) while(t--)
#define len(s) s.length()
const ll MAX=1e5+5;
const ll INF=2e18+10;
const int inf=1e9+10;
void solve()
{
    int n,m;
    cin>>n>>m;
    int a[m],b[m],w[m];
    for(int i=0;i<m;i++)
    {
        cin>>a[i]>>b[i]>>w[i];
        a[i]--;b[i]--;
    }
    int dist[n+1][n+1];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                dist[i][j]=0;
            else dist[i][j]=inf;
        }
    }
    for(int i=0;i<m;i++)
    {
        dist[b[i]][a[i]]=min(dist[b[i]][a[i]],w[i]);
        dist[a[i]][b[i]]=min(dist[a[i]][b[i]],w[i]);
    }
    
    // shortest distance using floyd
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
            {
                dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
            }
    // find ans
    int ans=m;
    for(int i=0;i<m;i++)
    {
        bool shortest=false;
        for(int j=0;j<n;j++)
        {
            if(dist[j][a[i]]+w[i]==dist[j][b[i]])
                shortest=true;
        }
        if(shortest)ans--;
    }
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t=1;
    //cin>>t;
    w(t) solve();
    return 0;
}