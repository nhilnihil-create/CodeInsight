#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
int L,x[MN+5],w[MN+5],a[MN+5],an,b[MN+5],bn,z[MN+5];
ll calx(int x){return a[x%an]-1LL*x/an*L;}
ll caly(int x){return b[x%bn]+1LL*x/bn*L;}
int main()
{
	int n,t,i;ll l,r,mid,res;
	n=read();L=read();t=read();
	for(i=1;i<=n;++i)x[i]=read(),w[i]=read(),z[i]=((x[i]+(w[i]<2?1:-1)*t)%L+L)%L;
	sort(z+1,z+n+1);
	if(w[1]<2)++an;else ++bn;
	for(i=n;i>1;--i)if(w[i]<2)a[an++]=x[i]-L-x[1];
	for(i=2;i<=n;++i)if(w[i]>1)b[bn++]=x[i]-x[1];
	if(w[1]<2)
	{
		if(!bn){for(i=1;i<=n;++i)printf("%d\n",(x[i]+t)%L);return 0;}
		for(l=1,r=3e9;l<=r;)
		{
			mid=l+r>>1;
			if(caly(mid-1>>1)-calx(mid>>1)>2*t)res=r=mid-1;
			else l=mid+1;
		}
		if(res)l=calx(res>>1),r=caly(res-1>>1);else l=r=0;
		x[1]=((x[1]+(r+l+(res&1?-1:1)*(2*t-r+l)>>1))%L+L)%L;
		if(res&1)for(i=1;i<=n;++i){if(z[i]==x[1])break;}
		else for(i=n;i;--i)if(z[i]==x[1])break;
	}
	else
	{
		if(!an){for(i=1;i<=n;++i)printf("%d\n",((x[i]-t)%L+L)%L);return 0;}
		for(l=1,r=3e9;l<=r;)
		{
			mid=l+r>>1;
			if(caly(mid>>1)-calx(mid-1>>1)>2*t)res=r=mid-1;
			else l=mid+1;
		}
		if(res)l=calx(res-1>>1),r=caly(res>>1);else l=r=0;
		x[1]=((x[1]+(r+l+(res&1?1:-1)*(2*t-r+l)>>1))%L+L)%L;
		if(res&1)for(i=n;i;--i){if(z[i]==x[1])break;}
		else for(i=1;i<=n;++i)if(z[i]==x[1])break;
	}
	for(l=i;l<=n;++l)printf("%d\n",z[l]);
	for(l=1;l<i;++l)printf("%d\n",z[l]);
}