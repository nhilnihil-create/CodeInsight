#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
//#define MXN 300000
#define N 100005
int dp[2005][2005];
int mod=1e9+7;
LL fra[10000005];
LL inv[10000005];
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
void build(){
    fra[0]=1;
    for(int i = 1;i<10000005;i++)
        fra[i]=fra[i-1]*i%mod;
    inv[10000000]=f_pow(fra[10000000],mod-2);
    for(int i = 9999999;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%mod;
}
LL C(int a,int b){
    return fra[a]*inv[b]%mod*inv[a-b]%mod;
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    if(k==1){
        printf("1\n");
        return 0;
    }
    build();
    dp[0][0]=1;
    for(int i = 1;i<=n;i++){
        dp[0][i]=dp[0][i-1]*C(i*(k-1)-1,k-2)%mod*(n-i+1)%mod;
        //printf("%d ",dp[0][i]);
        for(int j=1;j<=i;j++){
            dp[j][i]=(dp[j-1][i]+dp[j][i-1]*C(i*(k-1)+j-1,k-2)%mod*(n-i+1)%mod)%mod;
           // printf("%d ",dp[j][i]);
        }
      //  printf("\n");
        
    }
    printf("%d\n",dp[n][n]);
}