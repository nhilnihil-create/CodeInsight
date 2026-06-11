#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
int n,m;
int a[500010];
int b[500010];

bool check(int x)
{
	int front1=(x<a[m]);
	int front2=front1;
	int now1,now2;
	int asd=-1;//优先最近 
	rep(i,1,m)
	{
//		if(x>a[i])
//		{
//			now=1;
//		}
//		else
//		now=0;
		now1=(x<a[m+i]);
		if(now1==front1)
		{
//			asd=i;
			asd=1;
			break;
//			if(asd==-1)
//			{
//				asd=i;
//			}
//			else
//			{
//				
//			}
		}
		else
		front1=now1;
		
		now2=(x<a[m-i]);
		if(now2==front2)
		{
			asd=2;
			break;
		}
		else
		front2=now2;
	}
	if(asd==-1)
	{
		return a[1]<=x;
	}
	else
	if(asd==1)
	return now1^1;
	else
	return now2^1;
}
int main()
{
	cin>>n;
	m=n;
	n=2*n-1;
	rep(i,1,n+1)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	int l=1,r=n,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(check(b[mid]))//成立 
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	cout<<b[l]<<"\n";
	return 0;
}
