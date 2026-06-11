#include<cstdio>
#include<algorithm>
const int N=1e5+2;
int i,n,m,a[N];
long long ans=1e12,k[N],b[N];
void wk(int s,int t)
{
	if(b[s]+=s,++k[t],--k[s],s<t)b[1]+=t-s,b[t]-=s;else
	b[1]+=t,b[t]+=m-s,--k[1];
}
int main()
{
	for(scanf("%d%d",&n,&m);i++<n;scanf("%d",a+i));
	for(i=0;++i<n;wk(a[i]+1,a[i+1]+1));
	for(i=0;i++<m;)
	{
		k[i]+=k[i-1],b[i]+=b[i-1];
		ans=std::min(ans,k[i]*i+b[i]);
	}
	printf("%lld",ans);
}
/////////////////////////////////////////////////////////////////