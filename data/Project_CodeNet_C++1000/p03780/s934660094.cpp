#include <cstdio>
#include<bitset>
#include<algorithm>
#include<iostream>
#include<string>
#define ll long long 
using namespace std;
long long n,k;
ll a[5010];
bitset<5010> bs;
bool check(int x)
{
	bs.reset();
	bs[0]=1;
	for(int i=1;i<=n;i++)
	if(i!=x) bs|=(bs<<a[i]);
	for(int i=k-a[x];i<k;i++)
	if(bs[i]==1) return false;
	return true;
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int l=0,r=0,mid;
	for(int i=n;i>=1;i--)
	{
		if(a[i]<k) 
		{
			r=i;
			break;
		}
	}
	while(l<r)
	{
		mid=((l+r)>>1)+1;
		if(check(mid)) 
			l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
