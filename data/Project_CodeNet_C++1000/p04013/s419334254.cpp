#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N=55;
const int mod=1e9+7;
ll dp[N][N*N];
int main()
{
    int n,a;
    cin>>n>>a;
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        for(int j=i-1;j>=0;j--)
            for(int k=0;k<=N*j;k++)
                dp[j+1][k+x]+=dp[j][k];
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
        ans+=dp[i][i*a];
    cout<<ans<<endl;
    return 0;
}