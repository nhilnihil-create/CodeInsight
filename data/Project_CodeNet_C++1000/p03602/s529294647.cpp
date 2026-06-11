#include<bits/stdc++.h>
using namespace std;
#define loop(i,L,R) for(int i=(L);i<=(R);i++)
#define rept(i,L,R) for(int i=(L);i<(R);i++)
#define isc(n) scanf("%d",&n)
#define llsc(n) scanf("%lld",&n)
#define dsc(n) scanf("%lf",&n)
#define enl cout<<endl
#define PB(x) push_back(x)
#define xx first
#define yy second
typedef long long ll;
typedef pair<int,int>PI;
typedef pair<pair<int,int>,int>PII;

int grid[333][333];
int vis[333][333];
int main()
{
    int n;
    cin>>n;
    loop(i,1,n)loop(j,1,n)cin>>grid[i][j];
    loop(i,1,n)if(grid[i][i]!=0)
    {
        cout<<-1<<endl;
        return 0;
    }
    loop(i,1,n)
    {
        loop(j,1,n)
        {
            if(grid[i][j]!=grid[j][i])
            {
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    loop(i,1,n)
    {
        loop(j,1,n)
        {
            loop(k,1,n)
            {
                if(k==i || k==j)continue;
                if(grid[i][k]+grid[k][j]<grid[i][j])
                {
                    cout<<-1<<endl;
                    return 0;
                }
                else if(grid[i][k]+grid[k][j]==grid[i][j])
                {
                    //cout<<i<<" "<<k<<" "<<j<<endl;
                    vis[i][j]=1;
                }
            }
        }
    }
    ll ans=0;
    loop(i,1,n)
    {
        loop(j,1,n)
        {
            if(!vis[i][j])ans+=grid[i][j];
        }
    }
    cout<<ans/2<<endl;
    return 0;
}
