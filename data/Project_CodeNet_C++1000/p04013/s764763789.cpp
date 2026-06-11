#include<bits/stdc++.h>
using namespace std;
long long n,k,arr[100];
long long dp[100][100][5000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    dp[0][0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k <5000; k++)
            {
                if(dp[i][j][k]==0)continue;
                dp[i+1][j+1][k+ arr[i] ] += dp[i][j][k];
                dp[i+1][j][k] += dp[i][j][k];

            }
        }
    }
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        sum += dp[n][i][k*i];
    }
    cout<<sum<<endl;
    return 0;
}
