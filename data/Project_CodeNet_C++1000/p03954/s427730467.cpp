#include<bits/stdc++.h>
#define maxl 200010

using namespace std;

int n,ans;
int a[maxl];

inline void prework()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n-1;i++)
		scanf("%d",&a[i]);
}

inline int small(int i,int j,int k)
{
	return a[i]<=k && a[j]<=k;
}

inline int big(int i,int j,int k)
{
	return a[i]>k && a[j]>k;
}

inline int jug(int mid)
{
	for(int i=0;i<=n-1;i++)
	{
		if(big(n+i,n+i+1,mid) || big(n-i,n-i-1,mid))
			return 0;
		if(small(n+i,n+i+1,mid) || small(n-i,n-i-1,mid))
		return 1;
	}
	return small(1,1,mid);
}

inline void mainwork()
{
	int l=1,r=2*n-1,mid;
	while(l+1<r)
	{
		mid=(l+r)>>1;
		if(jug(mid))
			r=mid;
		else
			l=mid;
	}
	if(jug(r))
		ans=r;
	else
		ans=r-1;
}

inline void print()
{
	printf("%d\n",ans);
}

int main()
{
	prework();
	mainwork();
	print();
	return 0;
}