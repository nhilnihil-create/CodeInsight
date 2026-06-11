#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

const int N = 210; 
const ll INF = 1e8;

using namespace std;

ll adj[N][N];

main()
{
    fast;
    int n,m,R,i,j,k;
    cin>>n>>m>>R;
    int r[R];
    for (i=0;i<R;i++)
        cin>>r[i];
    int a,b;
    ll c;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
            adj[i][j]=(i==j)?0:INF;
    }
    for (i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        adj[a][b]=min(adj[a][b],c);
        adj[b][a]=min(adj[b][a],c);
    }
    //Floyd-Warshall Algorithm: O(n^3) - All pairs shortest paths
    //Edges can be negative - DP approach (uses adjacency matrix)
    //dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j])
    for (k=1;k<=n;k++)
    {
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=n;j++)
                adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
        }
    }
    ll ans=INF,temp;
    sort(r,r+R);
    do{
        temp=0;
        for (i=0;i<R-1;i++)
            temp+=adj[r[i]][r[i+1]];
        ans=min(ans,temp);
    } while (next_permutation(r,r+R));
    cout<<ans<<endl;
}