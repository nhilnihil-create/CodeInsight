#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const long long MAXN=200005;
long long n,N;
long long a[MAXN];
bool check(long long mid)
{
	for(long long i=0;i<n-1;i++)
	{
		long long s0=0,s1=0;
		if(a[n-i]>=mid&&a[n-i-1]>=mid)
			s1++;
		if(a[n-i]<mid&&a[n-i-1]<mid)
			s0++;
		if(a[n+i]>=mid&&a[n+i+1]>=mid)
			s1++;
		if(a[n+i]<mid&&a[n+i+1]<mid)
			s0++;
		if(s1)
			return 1;
		if(s0)
			return 0;
	}
	return a[1]>=mid;
}
int main()
{
	//freopen("mid.in","r",stdin);
	//freopen("mid.out","w",stdout);
	scanf("%lld",&n);
	N=2*n-1;
	for(long long i=1;i<=N;i++)
	{
		scanf("%lld",&a[i]);
	}
	long long l=2,r=N,ans=1;
	while(l<=r)
	{
		long long mid=(l+r)>>1;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
}