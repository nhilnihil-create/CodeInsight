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
int dp[1000][1000],a[100],b[100],c[100];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    for(int i=0; i<=500; i++)
        for(int j=0; j<=500; j++)
            dp[i][j]=1000;
    int n,p,q;
    cin>>n>>p>>q;
    for(int i=0; i<n; i++)
        cin>>a[i]>>b[i]>>c[i];
    dp[0][0]=0;
    for(int k=0; k<n; k++)
    {
        for(int i=400; i>=a[k]; i--)
        {
            for(int j=400; j>=b[k]; j--)
            {
                dp[i][j]=min(dp[i][j],dp[i-a[k]][j-b[k]]+c[k]);
            }
        }
    }
    int ans=1000;
    for(int i=1; i<=400; i++)
    {
        for(int j=1; j<=400; j++)
        {
            int x=i,y=j,z=__gcd(i,j);
            x/=z;
            y/=z;
            if(x==p && y==q)
                ans=min(ans,dp[i][j]);
        }
    }
    if(ans==1000)
        cout<<"-1"<<endl;
    else
        cout<<ans<<endl;

    return 0;
}
