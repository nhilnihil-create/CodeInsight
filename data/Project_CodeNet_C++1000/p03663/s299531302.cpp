#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int lim=1e9;
int get_res()
{
	char c=getchar();while(c!='Y' && c!='N') c=getchar();
	if(c=='Y') return 1;
	return 0;
}
void solve(int l,int r)
{
	int k;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		cout<<"? "<<mid<<"0"<<endl;
		fflush(stdout);
		int t=get_res();
		if(t) k=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<"! "<<k;
	fflush(stdout);
}
bool check(long long x)
{
	if(x>lim) return 0;
	cout<<"? "<<x-1<<"0"<<endl;
	fflush(stdout);
	int t=get_res();
	if(t==0) return 1;
	return 0;
}
int main()
{
	int now=999999999;
	while(now)
	{
		cout<<"? "<<now<<endl;
		fflush(stdout);
		int t=get_res();
		if(t==0) {solve(now+1,min(10ll*now+9,(long long)lim));return 0;}
		else
		{
			if(check(10ll*now+9)) {cout<<"! "<<10ll*now+9;fflush(stdout);return 0;}
			else now/=10;
		}
	}
	solve(1,9);
	return 0;
}