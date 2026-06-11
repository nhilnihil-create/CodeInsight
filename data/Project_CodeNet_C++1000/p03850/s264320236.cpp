#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
char op[3];
long long a[100010],b[100010];
long long sum[100010];
int main()
{
	int n;
	scanf("%d",&n);
	int N=1;
	scanf("%d",&a[N]);
	for(int i=2;i<=n;i++)
	{
		scanf("%s",&op);
		int x;scanf("%d",&x);
		if(op[0]=='-'){
			N++;b[N]=x;
		}
		a[N]+=x;
	}
	for(int i=1;i<=N;i++)
		sum[i]=sum[i-1]+a[i]-2*b[i];
	long long ans=sum[N];
	long long cur=0;
	for(int i=N;i>1;i--)
	{
		ans=max(ans,sum[i-1]+cur-a[i]);
		cur+=a[i];
	}
	printf("%lld\n",ans);
	return 0;
}