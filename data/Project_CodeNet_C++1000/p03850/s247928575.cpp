#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<string>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;
const ll mod=1e9+7;
ll dp[100010][3];
ll a;char c;int n;
int main()
{
    cin>>n>>a;
    memset(dp,-0x3f3f3f3f3f3f3f3f,sizeof(dp));
    dp[0][0]=a;
    for(int i=1;i<n;i++)
    {
        scanf(" %c%d",&c,&a);
        if(c=='+')
        {
            dp[i][2]=dp[i-1][2]+a;
            dp[i][1]=max(dp[i-1][1]-a,dp[i-1][2]+a);
            dp[i][0]=max(dp[i-1][0]+a,max(dp[i-1][1]-a,dp[i-1][2]+a));
        }
        else
        {
            dp[i][2]=dp[i-1][1]+a;
            dp[i][0]=dp[i][1]=max(dp[i-1][1]+a,max(dp[i-1][2]-a,dp[i-1][0]-a));
        }
    }
    printf("%lld\n",max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2])));
    return 0;
}