#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MOD 1000000007
#define MAXN 2005
using namespace std;
typedef long long LL;
int d[MAXN][MAXN],num[MAXN][MAXN],inv[MAXN*MAXN],kinv,n,k;
void pre()
{
    inv[1]=1;kinv=1;
    for(int i=2;i<MAXN*MAXN;i++) inv[i]=(MOD-MOD/i)*(LL)inv[MOD%i]%MOD;
    for(int i=2;i<=k-2;i++) kinv=(LL)kinv*inv[i]%MOD;
    num[0][0]=1;
    for(int j=1;j<n;j++)
    {
        num[0][j]=1;
        for(int m=1;m<=k-2;m++) num[0][j]=(LL)num[0][j]*(j*k-j+m)%MOD;
        num[0][j]=(LL)num[0][j]*kinv%MOD;
        //cout<<j<<' '<<num[0][j]<<endl;
    }
    for(int j=1;j<n;j++)
        for(int i=1;i<=j;i++)
    {   num[i][j]=(LL)num[i-1][j]*(j*k-j+k+i-2)%MOD*inv[j*k-j+i]%MOD;
        //cout<<j*k-j+k-2+i<<' '<<k-2<<' '<<num[i][j]<<endl;
    }
}
int main()
{

    cin>>n>>k;
    if(k==1) {cout<<1<<endl;return 0;}
    pre();
    d[0][1]=1;
    for(int j=2;j<=n;j++)
        d[0][j]=(LL)d[0][j-1]*num[0][j-1]%MOD;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
    {
        d[i][j]=(d[i-1][j]+(LL)d[i][j-1]*num[i][j-1]%MOD)%MOD;
    }
    int ans=d[n][n];
    for(int i=2;i<=n;i++) ans=(LL)ans*i%MOD;
    cout<<ans<<endl;
    return 0;
}
