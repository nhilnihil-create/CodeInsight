#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

const int N = 55;

using namespace std;

ll x[N];
ll dp[N][N*N];

main()
{
    fast;
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    int n,a,i,j,k;
    cin>>n>>a;
    for (i=1;i<=n;i++)
        cin>>x[i];
    for (i=1;i<=n;i++)
    {
        for (j=i-1;j>=0;j--)
        {
            for (k=0;k<N*N;k++)
                dp[j+1][k+x[i]]+=dp[j][k];
        }
    }
    ll ans=0;
    for (i=1;i<=n;i++)
        ans+=dp[i][i*a];
    cout<<ans<<endl;
}