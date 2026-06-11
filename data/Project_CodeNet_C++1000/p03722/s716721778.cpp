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
ll u[2005],v[2005],c[2005],dist[2005];
void solve(int n,int m)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(dist[u[j]]==inf)
                continue;
            if(dist[v[j]]>dist[u[j]]+c[j])
                dist[v[j]] = dist[u[j]] + c[j];
        }
    }
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        dist[i]=inf;
    for(int i=0; i<m; i++)
    {
        cin>>u[i]>>v[i]>>c[i];
        c[i]*=-1;
    }
    dist[1]=0;
    solve(n,m);
    ll ans=dist[n];
    solve(n,m);
    if(ans!=dist[n])
        cout<<"inf"<<endl;
    else
        cout<<ans*-1<<endl;


    return 0;
}
