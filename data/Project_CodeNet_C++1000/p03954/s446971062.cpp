#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
int ha1(int i,int j,int x)
{
	return a[i]>x&&a[j]>x;
}
int ha2(int i,int j,int x)
{
	return a[i]<=x&&a[j]<=x;
}
int haha(int x)
{
	for(int i=0;i<n;i++)
	{
		if(ha1(n+i,n+i+1,x)||ha1(n-i,n-i-1,x))//判断大的
			return 0;
		if(ha2(n+i,n+i+1,x)||ha2(n-i,n-i-1,x))
			return 1;
	}
	return ha2(1,1,x);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n*2-1;i++)
		scanf("%d",&a[i]);
	int l=1,r=2*n-1;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(haha(mid))
			r=mid;
		else
			l=mid+1;
	}
	printf("%d\n",r);
}