#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
#include <algorithm>
typedef long long ll;
using namespace std;
const int maxn=5100;
const ll mod=1000000000+7;
char sz[maxn];
ll f[maxn];
int n,len;
ll dp[maxn][maxn];

ll fast_pow(ll a,ll b){
    ll res=1;
    while(b){
        if(b%2==1) res=(res*a)%mod;
        a=(a*a)%mod;
        b=b/2;
    }
    return res;
}

int main(){
    scanf("%d",&n);
    scanf("%s",sz+1);
    len=strlen(sz+1);
    f[0]=1;
    for(int i=1;i<=len;i++) f[i]=(f[i-1]*2)%mod;
    dp[0][0]=1;
    dp[1][0]=1;dp[1][1]=2;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            dp[i+1][j+1]=(dp[i+1][j+1]+2*dp[i][j])%mod;
            dp[i+1][max(j-1,0)]=(dp[i+1][max(j-1,0)]+dp[i][j])%mod;
        }
    }
    printf("%lld\n",(dp[n][len]*fast_pow(f[len],mod-2))%mod);
    return 0;
}
