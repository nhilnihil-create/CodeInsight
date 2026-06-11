#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long
int n,m,w;
int a[500005];
int temp[500005];
bool check(int cm)
{
	for(int i=1;i<=2*n-1;i++)
	{
		temp[i]=0;
		if(a[i]>cm)
		{
			temp[i]=1;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(temp[n+i]==temp[n+i+1])
		{
			return temp[n+i];
		}
		else if(temp[n-i]==temp[n-i-1])
		{
			return temp[n-i];
		}
	}
	if(n%2==1)
	{
		return temp[n];
	}
	else
	{
		return 1-temp[n];
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n-1;i++)
	{
		scanf("%d",&a[i]);
	}
	int l=1,r=2*n-1;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid;
	}
	printf("%d",l);
    return 0;
}
