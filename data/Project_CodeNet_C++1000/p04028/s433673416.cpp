#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3fLL
#define rep(i,a,b) for(register ll i=(a);i<=(b);i++)
#define dep(i,a,b) for(register ll i=(a);i>=(b);i--)
using namespace std;
const int maxn=310+5;
const int maxm=5000+5;
//const double pi=acos(-1.0);
//const double eps=1e-9;
const ll mo=1e9+7;
int n,m,k;
ll a[maxn];
ll ans,tmp,cnt;
ll dp[maxm][maxm];
char s[maxn];
ll po[maxm];
ll power(ll a,ll n)
{
    ll sum=1;
    while(n)
    {
        if(n&1) sum=sum*a%mo;
        n>>=1;
        a=a*a%mo;
    }
    return sum;
}
int main()
{
    dp[0][0]=1;
    rep(i,0,5000)
    {
        rep(j,0,i)
        {
            dp[i+1][j+1]=(dp[i+1][j+1]+2*dp[i][j])%mo;
            dp[i+1][max(j-1,0LL)]=(dp[i+1][max(j-1,0LL)]+dp[i][j])%mo;
        }
    }
    po[0]=1;
    rep(i,1,5000) po[i]=po[i-1]*2%mo;
    rep(i,1,5000) po[i]=power(po[i],mo-2);
    while(scanf("%d%s",&m,s)!=EOF)
    {
        n=strlen(s);
        printf("%lld\n",dp[m][n]*po[n]%mo);
    }
    return 0;
}
