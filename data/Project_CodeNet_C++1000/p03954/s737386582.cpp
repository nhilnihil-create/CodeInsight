#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
bool check(int k)
{
	for (int i=1;i<n;i++)
	{
		if (a[n+i]>k && a[n+i-1]>k || a[n-i]>k && a[n-i+1]>k) return 0;
		if (a[n+i]<=k && a[n+i-1]<=k || a[n-i]<=k && a[n-i+1]<=k) return 1;
	}
	return a[1]<=k;
}
int main()
{
	//freopen("pyramid.in","r",stdin);
	//freopen("pyramid.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=2*n-1;i++) scanf("%d",&a[i]);
	int l=0,r=2*n-1;
	while (l<r)
	{
		int mid=(l+r)/2;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d",l);
	return 0;
}