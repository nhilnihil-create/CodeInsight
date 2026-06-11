#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<map>
using namespace std;

typedef long long ll;
typedef short int sh;

const ll inf=0x3f3f3f3f;
const int MAX=1<<6;
const int mod=1e9+7;

ll dp[51][51][2501];
int num[50],n,a;

ll Dp(int st,int cnt,int sum)
{
    if(dp[st][cnt][sum]!=-1)
        return dp[st][cnt][sum];
    dp[st][cnt][sum]=0;
    if(cnt&&(double)sum/cnt==a)
    {
        dp[st][cnt][sum]++;
    }
    for(int i=st;i<n&&(double)(sum+num[i])/(cnt+1)<=a;i++)
    {
        dp[st][cnt][sum]+=Dp(i+1,cnt+1,sum+num[i]);
    }
    return dp[st][cnt][sum];
}

int main()
{
    while(scanf("%d%d",&n,&a)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
        }
        sort(num,num+n);
        memset(dp,-1,sizeof(dp));
        printf("%lld\n",Dp(0,0,0));
    }
    return 0;
}
