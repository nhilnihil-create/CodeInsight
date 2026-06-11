#include<bits/stdc++.h>
#define LL long long
#define db double

using namespace std;
const int N=2000+10,mod=1e9+7;
int rd()
{
    int x=0,w=1;char ch=0;
    while(ch<'0'||ch>'9'){if(ch=='-') w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
    return x*w;
}
void ad(int &x,int y){x+=y,x-=x>=mod?mod:0;}
int fpow(int a,int b){int an=1;while(b){if(b&1) an=1ll*an*a%mod;a=1ll*a*a%mod,b>>=1;}return an;}
int ginv(int a){return fpow(a,mod-2);}
int n,k,fac[N*N],iac[N*N],f[2][N];
int C(int a,int b){return b<0||a<b?0:1ll*fac[a]*iac[b]%mod*iac[a-b]%mod;}

int main()
{
	n=rd(),k=rd();
	if(k==1){puts("1");exit(0);}
	fac[0]=1;
	for(int i=1;i<=n*k;++i) fac[i]=1ll*fac[i-1]*i%mod;
	iac[n*k]=ginv(fac[n*k]);
	for(int i=n*k;i;--i) iac[i-1]=1ll*iac[i]*i%mod;
	int nw=1,la=0;
	f[la][0]=1;
	for(int i=1;i<=n+n;++i)
	{
		for(int j=0;j<i&&j<=n;++j)
		{
			if(!f[la][j]) continue;
			if(j<=n) ad(f[nw][j+1],1ll*f[la][j]*C(i-1+(k-2)*(j+1),k-2)%mod);
			if(j>=i-j) ad(f[nw][j],f[la][j]);
			f[la][j]=0;
		}
		nw^=1,la^=1;
	}
	printf("%d\n",(int)(1ll*fac[n]*f[la][n]%mod));
	return 0;
}
