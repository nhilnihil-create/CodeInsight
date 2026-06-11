/************************************************
*Author        :  Modesty
*Created Time  :  2019.11.07.08:36
*Mail          :  modestyscholarly@gmail.com
*Problem       :  pyramid
************************************************/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int n,a[maxn];
int read()
{
	int s=0,f=1;
	char ch=getchar();
	while (!isdigit(ch))
	{
		if (ch==45) 
		{
			f=-1;
		}
		ch=getchar();
	}
	while (isdigit(ch))
	{
		s=s*10+ch-48; 
		ch=getchar(); 
	}
	return s*f; 
}
bool check(int k)
{
	if ((a[n-1]<=k&&a[n]<=k)||(a[n]<=k&&a[n+1]<=k))
	{
		return 1;
	}
	if ((a[n-1]>k&&a[n]>k)||(a[n]>k&&a[n+1]>k))
	{
		return 0;
	}
	for (int i=1;i<n-1;i++)
	{
		if ((a[n+i]<=k&&a[n+i+1]<=k)||(a[n-i]<=k&&a[n-i-1]<=k))
		{
			return 1;
		}
		if ((a[n+i]>k&&a[n+i+1]>k)||(a[n-i]>k&&a[n-i-1]>k))
		{
			return 0;
		}
	}
	return a[1]<=k;
}
int main()
{
//	freopen("pyramid.in","r",stdin);
//	freopen("pyramid.out","w",stdout);
	cin>>n;
	for (int i=1;i<n*2;i++)
	{
		a[i]=read();
	}
	int l=1,r=n*2-1;
	while (l<r)
	{
		int mid=(l+r)>>1;
		if (check(mid))
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	cout<<l<<endl;
	return 0;
}