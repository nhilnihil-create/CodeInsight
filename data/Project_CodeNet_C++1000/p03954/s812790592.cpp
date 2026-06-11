#include<stdio.h>
#include<math.h> 
using namespace std;
long long a[200001],i,n;
bool pd(long long h)
{
	if (a[n]<=h&&(a[n-1]<=h||a[n+1]<=h)) return true;
	if (a[n]>h&&(a[n-1]>h||a[n+1]>h)) return false;
	for (long long i=1;i<n-1;i++)
	{
		if (a[n+i]<=h&&a[n+i+1]<=h||a[n-i-1]<=h&&a[n-i]<=h) return true;
		if (a[n+i]>h&&a[n+i+1]>h||a[n-i-1]>h&&a[n-i]>h) return false;
	}
	return a[1]<=h;
}
long long erfen(long long l,long long r)
{
	if (l==r) return l;
	long long mid=(l+r)/2;
	if (pd(mid)) return erfen(l,mid);
	else return erfen(mid+1,r);
}
int main()
{
	scanf("%lld",&n);
	for (i=1;i<n*2;i++)
		scanf("%lld",&a[i]);
	printf("%lld",erfen(1,n*2-1));
	return 0;
}