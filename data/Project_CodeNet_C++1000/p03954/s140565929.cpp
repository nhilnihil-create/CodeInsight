#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],p[N],n;
int check(int mid)
{
	for(int i=1;i<=2*n-1;i++)
		p[i]=(a[i]>=mid);
	for(int i=n;i>=2;i--)
	{
		if(p[i]==p[i-1])
			return p[i];
		int j=2*n-i;
		if(p[j]==p[j+1])
			return p[j];
	}
	return p[1];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n-1;i++)
		scanf("%d",&a[i]);
	int l=1,r=2*n-1;
	while(l<r)
	{
		int mid=l+r+1>>1;
		if(check(mid))
			l=mid;
		else
			r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}
