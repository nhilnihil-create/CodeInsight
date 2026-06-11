#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=2005;
const int MOD=1000000007;

int n,k,f[N][N],jc[N*N+N*2],ny[N*N+N*2];

void updata(int &x,int y)
{
    x+=y,x-=x>=MOD?MOD:0;
}

int C(int n,int m)
{
    return (LL)jc[n]*ny[m]%MOD*ny[n-m]%MOD;
}

int main()
{
    scanf("%d%d",&n,&k);k--;
    if (!k) {puts("1");return 0;}
    jc[0]=jc[1]=ny[0]=ny[1]=1;
    for (int i=2;i<=n*k+n+k;i++) jc[i]=(LL)jc[i-1]*i%MOD,ny[i]=(LL)(MOD-MOD/i)*ny[MOD%i]%MOD;
    for (int i=2;i<=n*k+n+k;i++) ny[i]=(LL)ny[i-1]*ny[i]%MOD;
    f[0][0]=1;
    for (int i=0;i<=n;i++)
        for (int j=i;j<=n;j++)
        {
            if (i) updata(f[i][j],f[i-1][j]);
            if (j) updata(f[i][j],(LL)f[i][j-1]*C(i+(j-1)*k+k-1,k-1)%MOD);
        }
    printf("%d",(LL)f[n][n]*jc[n]%MOD);
    return 0;
}
