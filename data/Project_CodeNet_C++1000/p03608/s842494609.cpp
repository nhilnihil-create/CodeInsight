#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int adj[205][205],sum;
int n,r,m;
vector<int>place;
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    cin>>n>>m>>r;
    for(int i=0; i<r; i++)
    {
        int a;
        cin>>a;
        place.push_back(a);
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            adj[i][j]=1e8;
    while(m--)
    {
        int u,v,c;
        cin>>u>>v>>c;
        adj[u][v]=min(c,adj[u][v]);
        adj[v][u]=min(c,adj[v][u]);
    }
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
    }
    int ans=INT_MAX;
    sort(place.begin(),place.end());
    do
    {
        int res=0;
        for(int i=0;i<r-1;i++)
        {
            res+=adj[place[i]][place[i+1]];
        }
        ans=min(ans,res);
    }
    while(next_permutation(place.begin(),place.end()));
    cout<<ans<<endl;



    return 0;
}
