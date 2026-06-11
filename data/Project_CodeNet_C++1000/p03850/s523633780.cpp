#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
char C;
ll dp[100010][5] = {0};
ll A;

int main()
{
    scanf("%d%lld",&N,&A);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            dp[i][j] = -1 * 1000000000000000;
        }
    }
    dp[0][0] = A;
    for(int i = 1; i < N; i++)
    {
        scanf(" %c%d",&C,&A);
        if(C == '+')
        {
            dp[i][2] = dp[i - 1][2] + A;
            dp[i][1] = max(dp[i - 1][1] - A,dp[i - 1][2] + A);
            dp[i][0] = max(dp[i - 1][0] + A,max(dp[i - 1][1] - A,dp[i - 1][2] + A));
        }
        else
        {
            dp[i][2] = dp[i - 1][1] + A;
            dp[i][0] = dp[i][1] = max(dp[i - 1][1] + A,max(dp[i - 1][0] - A,dp[i - 1][2] - A));
        }
    }
    printf("%lld\n",max(dp[N - 1][0],max(dp[N - 1][1],dp[N - 1][2])));
}

