#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=200005;
int a[N],n;
bool big (int x,int y,int k)	{return a[x]>=k&&a[y]>=k;}
bool small (int x,int y,int k)	{return a[x]<k&&a[y]<k;}
bool check (int x)
{
	for (int u=0;u<n-1;u++)
	{
		if (big(n+u,n+u+1,x)||big(n-u,n-u-1,x)) return true;
		if (small(n+u,n+u+1,x)||small(n-u,n-u-1,x)) return false;
	}
	return big(1,1,x);
}
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n*2-1;u++) scanf("%d",&a[u]);
	int l=1,r=n*2-1;
	int lalal;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (check(mid)) {l=mid+1;lalal=mid;}
		else r=mid-1;
	}
	printf("%d\n",lalal);
	return 0;
}