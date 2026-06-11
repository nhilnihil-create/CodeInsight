#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int query(long long x)
{
	cout<<"? "<<x<<endl;
	fflush(stdout);
	char c=getchar();
	while(c!='Y' && c!='N') c=getchar();
	if(c=='Y') return 1;
	return 0;
}
void solve(int l,int r)
{
	int k;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(query(10ll*mid)) k=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<"! "<<k;
}
int main()
{
	if(query(1e9))
	{
		int now=2e8;
		while(now)
		{
			if(query(now)==0) {cout<<"! "<<5*now;return 0;}
			now/=10;
		}
		cout<<"! 1";
	}
	else
	{
		int now=1;
		while(1)
		{
			if(query(now)==0) {solve(now/10,now-1);return 0;}
			now*=10;
		}
	}
	return 0;
}