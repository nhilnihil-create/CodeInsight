#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<functional>
#include<utility>
#include<bitset>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<cstdlib>
#define maxn 100005
using namespace std;
long long n,b,a,h[maxn];
bool check(long long x)
{
	long long d=a-b;
	long long u=0,g=0;
	for(long long i=0;i<n;i++)
	{
		u=h[i]-b*x;
		if(u<=0)
			continue;
		else
		{
			g+=u/d;
			g+=(u%d!=0);
			if(g>x)
				return false;
		}
	}
	if(g>x)
		return false;
	return true;
}
int main()
{
	cin>>n>>a>>b;
	for(long long i=0;i<n;i++)
		cin>>h[i];
	long long lbound=0,ubound=1e9,ans=ubound;
	while(lbound<=ubound)
	{
		long long mid=(lbound+ubound)/2;
		if(check(mid))
		{
			ubound=mid-1;
			ans=min(ans,mid);
		}
		else
			lbound=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}