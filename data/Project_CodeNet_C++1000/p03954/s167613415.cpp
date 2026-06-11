#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<stack>
#include<cmath>
using namespace std;
int a[200001];
int p[200001];
int n;
bool win()
{
	for(int i=0;i<n-1;i++)
	{
		if(p[n-i]==p[n-i-1])
			return p[n-i];
		if(p[n+i]==p[n+i+1])
			return p[n+i];
	}
	return p[1];
}
bool judge(int x)
{
	for(int i=1;i<=2*n-1;i++)
		if(a[i]>=x)
			p[i]=1;
		else
			p[i]=0;
	return win();
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n-1;i++)
		scanf("%d",&a[i]);
	int l=0,r=2*n;
	while(l+1<r)
	{
		int mid=(l+r)/2;
		if(judge(mid))
			l=mid;
		else
			r=mid;
	}
	printf("%d",l);
	return 0;
}
