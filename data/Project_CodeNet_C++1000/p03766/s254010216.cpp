#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MAX=1000005;
const ll INF=0x3f3f3f3f3f3f3f;
const ll MOD=1000000007;
ll n,dp[MAX],dp_sum[MAX];
int main(){
    scanf("%lld",&n);
    dp[n+1]=1,dp[n]=1,dp[n-1]=n,dp_sum[n-1]=n-1;
    for(ll i=n-2;i>=0;i--){
        dp[i]=(n-1)*(n-1)+dp_sum[i+1]+dp[i+1],dp[i]%=MOD;
        dp_sum[i]=dp_sum[i+1]+dp[i+2]-1,dp_sum[i]%=MOD;
    }
    printf("%lld\n",dp[0]);
    //for(ll i=0;i<=n;i++) printf("%lld : %lld %lld\n",i+1,dp[i],dp_sum[i]);
}
