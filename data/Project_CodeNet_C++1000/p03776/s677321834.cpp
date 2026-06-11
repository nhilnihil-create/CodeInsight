#include<iostream>
#include<algorithm> 
using namespace std;
typedef long long ll;
const int N=51;
int n,a,b;
ll c[N][N],v[N],sum[N],ans;
ll son,par;
void init()
{
	for(int i=1;i<=50;++i)
	{
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;++j)
		c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
}
int main()
{
	init();
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;++i)
	scanf("%lld",&v[i]);
	sort(v+1,v+n+1,greater<ll>());
	son=par=1;
	for(int i=1;i<=n;++i)
		sum[i]=sum[i-1]+v[i];
	for(int i=a;i<=b;++i)
	{
		if(sum[i]*par>son*i)
		{
			son=sum[i];
			par=i;
		}
	}
	for(int i=a;i<=b;++i)
	{
		if(sum[i]*par==son*i)
		{
			int my=1,all=0;
			for(int j=i-1;j>=1;--j)
			if(v[j]==v[j+1])my++;
			else break;
			all=my;
			for(int j=i+1;j<=n;++j)
			if(v[j]==v[j-1])all++;
			else break;
			ans+=c[all][min(all-my,my)];
		}
	}
	printf("%.6lf\n",1.0*son/par);
	printf("%lld\n",ans);
	return 0;
}
