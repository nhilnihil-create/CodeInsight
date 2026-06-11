#include<bits/stdc++.h>
using namespace std;
#define next Next
#define gc getchar
#define int long long
/*char buf[1<<21],*p1=buf,*p2=buf;
inline int gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}*/
inline int read()
{
    int ret=0,f=0;char c=gc();
    while(!isdigit(c)){if(c=='-')f=1;c=gc();}
    while(isdigit(c)){ret=ret*10+c-48;c=gc();}
    if(f)return -ret;return ret;
}
const int mod=1e9+7;
const int N=2005;
int n,k;
int f[N][N],jc[N*N],inv[N*N];
inline int C(int n,int m)
{
	return jc[n]*inv[m]%mod*inv[n-m]%mod;
}
signed main()
{
    n=read();k=read();
    if(k==1){cout<<1;return 0;}
    jc[0]=jc[1]=inv[0]=inv[1]=1;
	for(int i=2;i<=4000000;i++)jc[i]=jc[i-1]*i%mod;
    for(int i=2;i<=4000000;i++)inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    for(int i=2;i<=4000000;i++)inv[i]=inv[i]*inv[i-1]%mod;
    f[0][0]=1;
    for(int i=1;i<=n;i++)
	{
        for(int j=0;j<=i;j++)
		{
            f[i][j]=f[i-1][j];
            if(!j)continue;
            (f[i][j]+=f[i][j-1]*(n-j+1)%mod*C(n-i+(n-j+1)*(k-1)-1,k-2)%mod)%=mod;
        }
    }
    printf("%lld\n",f[n][n]);
    return 0;
}