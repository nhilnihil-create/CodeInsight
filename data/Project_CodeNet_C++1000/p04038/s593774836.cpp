#include<bits/stdc++.h>
using namespace std;
typedef long long D;
const int maxn=2003,maxm=4000003,mod=1000000007;
int Plus(int x,int y){return (x+=y)>=mod?x-mod:x;}
void Pluseq(int &x,int y){if((x+=y)>=mod)x-=mod;}
int Minus(int x,int y){return Plus(x,mod-y);}
void Minuseq(int &x,int y){Pluseq(x,mod-y);}
int mul(D x,int y){return x*y%mod;}
void muleq(int &x,int y){x=mul(x,y);}
int qpow(int x,int y){
    int ans=1;
    while(y){
        if(y&1)muleq(ans,x);
        muleq(x,x);
        y>>=1;
    }
    return ans;
}
int fac[maxm],facinv[maxm],dp[maxn][maxn],n,k;
int C(int n,int m){return mul(mul(fac[n],facinv[m]),facinv[n-m]);}
int main(){
    fac[0]=1;
    for(int i=1;i<maxm;i++)fac[i]=mul(fac[i-1],i);
    facinv[maxm-1]=qpow(fac[maxm-1],mod-2);
    for(int i=maxm-2;i>=0;i--)facinv[i]=mul(facinv[i+1],i+1);
    scanf("%d%d",&n,&k);
    if(k==1){puts("1");return 0;}
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            dp[i][j]=Plus(dp[i-1][j],!j?0:mul(dp[i][j-1],mul(C(n*k-i-(j-1)*(k-1)-1,k-2),n-j+1)));
        }
    }
    printf("%d\n",dp[n][n]);
    return 0;
}