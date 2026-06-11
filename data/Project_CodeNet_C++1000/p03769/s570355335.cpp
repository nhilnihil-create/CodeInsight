#include<cstdio>
#include<cstdlib>
#define LL long long

int ans[210];
bool fec[110];

int main()
{
	LL n;
	scanf("%lld",&n);
	LL x=n;
	fec[0]=0;
	int mx=0,id,tot=0;
	for(int i=1;i<=40;i++) fec[i]=0;
	while(x)
	{
		if(x&1) fec[mx]=1;
		x>>=1;
		if(x) mx++;
	}
	id=mx;
	for(int i=0;i<=mx;i++)
	{
		if(i>0) ans[++tot]=i;
		if(fec[i]&&i!=mx) ans[++tot]=++id;
	}
	for(int i=1;i<=mx;i++) ans[++tot]=i;
	ans[++tot]=++id;ans[++tot]=id;
	for(int i=0;i<mx;i++) if(fec[i]) ans[++tot]=--id;
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++) printf("%d ",ans[i]);
	return 0;
}