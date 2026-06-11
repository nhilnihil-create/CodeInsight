#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
const int mod=1e9+7,N=2e3+50;
inline int add(int x,int y) {return (x+y>=mod)?(x+y-mod):(x+y);}
inline int mul(int x,int y) {return (LL)x*y%mod;}
inline int power(int a,int b) {
    int rs=1;
    for(;b;b>>=1,a=mul(a,a)) if(b&1) rs=mul(rs,a);
    return rs;
}
int n,k,dp[N][N],fac[N*N*2],ifac[N*N*2];
inline int C(int x,int y) {return mul(ifac[x-y],mul(fac[x],ifac[y]));}
int main() {
    cin>>n>>k; int l=2*n*k;
    if(k==1) {puts("1"); return 0;}
    fac[0]=1;
    for(int i=1;i<=l;i++) fac[i]=mul(fac[i-1],i);
    ifac[l]=power(fac[l],mod-2);
    for(int i=l-1;~i;i--) ifac[i]=mul(ifac[i+1],i+1);
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=i;j++) {
            if(j==i) dp[i][j]=dp[i][j-1];
            else dp[i][j]=add(dp[i][j-1],mul(dp[i-1][j],C(k-2+(i-1)*k-(i-j-1),k-2)));
        }
    printf("%d\n",mul(dp[n][n],fac[n]));
}