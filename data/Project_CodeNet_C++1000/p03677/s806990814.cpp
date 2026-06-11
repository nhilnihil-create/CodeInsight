#include<bits/stdc++.h>
using namespace std;
const int N=100005;
long long a[N],b[N],c[N];
int main()
{
	int n,m;
	scanf("%d%d%lld",&n,&m,&a[1]);
	long long sum=0;
	for(int i=2;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]>a[i-1])
		{
			sum+=a[i]-a[i-1];
			b[a[i-1]+1]+=a[i-1]+1;
			b[a[i]+1]-=a[i-1]+1;
			c[a[i-1]+1]++;
			c[a[i]+1]--;
		}
		else
		{
			sum+=m-a[i-1]+a[i];
			b[a[i-1]+1]+=a[i-1]+1;
			c[a[i-1]+1]++;
            b[1]-=m-a[i-1]-1;
            c[1]++;
            b[a[i]+1]+=m-a[i-1]-1;
            c[a[i]+1]--;
		}
	}
	for(int i=1;i<=m;i++)
		b[i]+=b[i-1],c[i]+=c[i-1];
	long long ans=0;
	for(int i=1;i<=m;i++)
		ans=max(ans,i*c[i]-b[i]);
	printf("%lld\n",sum-ans);
	return 0;
}
