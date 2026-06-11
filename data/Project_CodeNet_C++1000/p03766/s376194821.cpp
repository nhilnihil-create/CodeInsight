#include<bits/stdc++.h>

using namespace std;
#define X first
#define Y second
#define pb push_back
typedef double db;
typedef long long ll;
typedef pair<int,int> P;
const int MAXN=1e6+10,MOD=1e9+7;
int n,dp[MAXN],pre[MAXN];

int main()
{
    scanf("%d",&n);
    dp[0]=pre[0]=1;ll res=0;
    for(int i=1;i<=n;i++)
    {
        (dp[i]+=dp[i-1])%=MOD;
        if(i>=3) (dp[i]+=pre[i-3])%=MOD;
        pre[i]=(pre[i-1]+dp[i])%MOD;
    }
    for(int i=0;i<n-1;i++)
        (res+=1ll*dp[i]*(n-1)%MOD*(n-1)%MOD)%=MOD;
    for(int i=0;i<n;i++)
        (res+=1ll*dp[i]*min(i+1,n-1)%MOD)%=MOD;
    (res+=dp[n])%=MOD;
    printf("%lld",res);
    return 0;
}