#include<bits/stdc++.h>
#define N 2002
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,k;
ll dp[N][N],jie[N*N],ni[N*N];
inline ll rd(){
    ll x=0;char c=getchar();bool f=0;
    while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
    while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    return f?-x:x;
}
inline ll power(ll x,ll y){
    ll ans=1;
    while(y){
        if(y&1)ans=ans*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ans;
}
inline ll C(int n,int m){return jie[n]*ni[m]%mod*ni[n-m]%mod;}
int main(){
    n=rd();k=rd();
    if(k==1){puts("1");return 0;}
    int x=n*k;
    jie[0]=1;
    for(int i=1;i<=x;++i)jie[i]=jie[i-1]*i%mod;
    ni[x]=power(jie[x],mod-2);
    for(int i=x-1;i>=0;--i)ni[i]=ni[i+1]*(i+1)%mod;
    dp[0][0]=1;
    for(int i=1;i<=n;++i){
        dp[i][0]=1;
        for(int j=1;j<=i;++j){
            dp[i][j]=(dp[i-1][j]+dp[i][j-1]*(n-j+1)%mod*C(n*k-(j-1)*(k-1)-i-1,k-2))%mod;
        }
    }
    cout<<dp[n][n];
    return 0;
}