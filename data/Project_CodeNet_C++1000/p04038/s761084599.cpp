#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define MAX 2010
#define MOD 1000000007
void add(int &x,int y){x+=y;if(x>=MOD)x-=MOD;}
inline int read()
{
    int x=0;bool t=false;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=true,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return t?-x:x;
}
int n,k,mx,f[MAX][MAX];
int jc[MAX*MAX],jv[MAX*MAX],inv[MAX*MAX];
int C(int n,int m){return 1ll*jc[n]*jv[m]%MOD*jv[n-m]%MOD;}
int main()
{
    n=read();k=read();mx=n*k;
    if(k==1){puts("1");return 0;}
    jc[0]=jv[0]=inv[0]=inv[1]=1;
    for(int i=1;i<=mx;++i)jc[i]=1ll*jc[i-1]*i%MOD;
    for(int i=2;i<=mx;++i)inv[i]=1ll*inv[MOD%i]*(MOD-MOD/i)%MOD;
    for(int i=1;i<=mx;++i)jv[i]=1ll*jv[i-1]*inv[i]%MOD;
    f[0][0]=1;
    for(int i=1;i<=n;++i)
        for(int j=0;j<=i;++j)
        {
            add(f[i][j],f[i-1][j]);
            if(j)add(f[i][j],1ll*f[i][j-1]*(n-j+1)%MOD*C((n-i)+(n-j+1)*(k-1)-1,k-2)%MOD);
        }
    printf("%d\n",f[n][n]);
    return 0;
}