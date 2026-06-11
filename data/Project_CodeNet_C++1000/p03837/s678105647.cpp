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
ll mat[105][105],mark[105][105];
int n,m;
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            mat[i][j]=1e9;
    for(int i=0; i<m; i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        mat[u][v]=c;
        mat[v][u]=c;
        mark[u][v]=c;
        mark[v][u]=c;

    }
    int ans=0;
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                if(mat[i][j]>mat[i][k]+mat[k][j])
                {
                    mat[i][j]=mat[i][k]+mat[k][j];
                    if(mark[i][j])
                    {
                        ans++;
                        mark[i][j]=0;
                        mark[j][i]=0;
                    }
                }
            }


    cout<<ans<<endl;

    return 0;
}
