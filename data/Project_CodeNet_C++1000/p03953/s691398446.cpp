#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<cmath>
#define LL long long 
using namespace std;
inline LL read() {
    LL d=0,f=1;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){d=d*10+s-'0';s=getchar();}
    return d*f;
}
LL x[100005],ans[100005],k[100005],bc[100005],ass[100005];
int main()
{
	LL n=read();
	for(LL i=1;i<=n;i++) x[ans[i]=k[i]=i]=read();
	LL m=read(),lun=read();
	for(LL i=1;i<=m;i++) 
	{
		LL a=read();
		swap(k[a],k[a+1]);
	}
	while(lun)
	{
		if(lun&1)
		{
			for(LL i=1;i<=n;i++) bc[i]=ans[k[i]];
			for(LL i=1;i<=n;i++) ans[i]=bc[i];
		}
		for(LL i=1;i<=n;i++) bc[i]=k[k[i]];
		for(LL i=1;i<=n;i++) k[i]=bc[i];
		lun>>=1;
	}
	for(LL i=1;i<=n;i++) ass[i]=x[ans[i]]-x[ans[i]-1];
	double s=0;
	for(LL i=1;i<=n;i++) {s+=ass[i];printf("%.1lf\n",s);}
	return 0;
}
