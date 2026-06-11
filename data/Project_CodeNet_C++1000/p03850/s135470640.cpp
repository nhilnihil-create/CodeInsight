#include<bits/stdc++.h>
using namespace std;
#define llong long long
const llong inf=0x3f3f3f3f3f3f3f3f;
int n;
char op[22];
int a;
llong dp[100100][3];
int main()
{
    scanf("%d",&n);
    scanf("%d",&a);
    dp[1][0]=a;
    dp[1][1]=dp[1][2]=-inf;
    for(int i=2;i<=n;++i)
    {
        scanf("%s%d",op,&a);
        if(op[0]=='-')a=-a;
//        cout<<"i: "<<i<<" op: "<<op[0]<<" a: "<<a<<endl;
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
        dp[i][1]=max(dp[i-1][1],dp[i-1][2]);
        dp[i][2]=dp[i-1][2]+a;
//        cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;cout<<endl;
        dp[i][0]+=a;
        dp[i][1]-=a;
        if(op[0]=='-')
        {
            dp[i][2]=max(dp[i][2],dp[i][1]);
            dp[i][1]=max(dp[i][1],dp[i][0]);
        }
//        cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;cout<<endl;
    }
    printf("%lld\n",max(dp[n][0],max(dp[n][1],dp[n][2])));
    return 0;
}
