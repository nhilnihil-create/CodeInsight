#include<bits/stdc++.h>
using namespace std;

#define ll      long long
#define MAX     1000007
#define inf     99999999999999
#define MOD     1000000007
#define pii     pair<int,int>
#define FIN     freopen("input.txt","r",stdin);
#define FOUT    freopen("output.txt","w",stdout);

ll adj[305][305];
ll dis[305][305];
bool mark[305][305];
ll i,j,k;

int main ()
{
    ll n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%lld",&adj[i][j]);
            dis[i][j] = adj[i][j];
        }
    }
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(dis[i][j] > dis[i][k] + dis[k][j])
                {

                    dis[i][j] = dis[i][k] + dis[k][j];
                }
                else if(i!=k && k!=j &&  dis[i][j] == dis[i][k] + dis[k][j])
                {
                    mark[i][j] = 1;
                }
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(dis[i][j]!=adj[i][j])
            {
                printf("-1\n");
                return 0;
            }
        }
    }
    ll res = 0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(!mark[i][j])
            {
                res += dis[i][j];
                mark[j][i] = 1;
            }
        }
    }
    printf("%lld\n",res);
    return 0;
}
