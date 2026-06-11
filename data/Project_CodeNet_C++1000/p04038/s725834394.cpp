#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
using namespace std;
const int maxn=2010,P=1e9+7;
int n,k,fac[maxn*maxn],ifac[maxn*maxn],inv[maxn*maxn],dp[maxn][maxn];
inline int C(int n,int k){return 1ll*fac[n]*ifac[k]%P*ifac[n-k]%P;}
int main(){
    scanf("%d%d",&n,&k);int N=n*k;inv[1]=fac[0]=ifac[0]=1;
    if(k==1) return puts("1"),0;
    rep(i,2,n*k) inv[i]=1ll*(P-P/i)*inv[P%i]%P;
    rep(i,1,n*k) fac[i]=1ll*fac[i-1]*i%P,ifac[i]=1ll*ifac[i-1]*inv[i]%P;
    dp[0][0]=1;
    rep(i,1,n) rep(j,0,i){
        dp[i][j]=dp[i-1][j];
        if(j) dp[i][j]=(dp[i][j]+1ll*dp[i][j-1]*(n-j+1)%P*C(n*k-i-(j-1)*(k-1)-1,k-2)%P)%P;
    }
    printf("%d\n",dp[n][n]);
    return 0;
}