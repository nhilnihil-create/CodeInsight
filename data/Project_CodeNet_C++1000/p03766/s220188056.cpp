#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#define eps 0.0000000001
#define maxn 1000009
#define inf 0x3f3f3f3f
#define mod 1000000007
#define ll long long
using namespace std;
//int T,cas=1;
ll dp[maxn*3];
ll n;
int main()
{
    //freopen("d:\\in.txt","r",stdin);
    //scanf("%d",&T);
    //while(cas<=T)
    //{
    //    cas++;
    //}
    scanf("%lld",&n);
    for(int i=n+1;i<=2*n+1;i++)
        dp[i]=1;
    dp[n]=n;
    ll sum=n+n;
    for(int i=n-1;i>=1;i--)
    {
        dp[i]=(sum-dp[i+2]+(n-1)*(n-1)%mod+mod)%mod;
        sum=(sum+dp[i])%mod;
        sum=(sum-dp[i+n+1])%mod;
    }
    printf("%lld\n",dp[1]);
    return 0;
}
