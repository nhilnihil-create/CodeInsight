// This code wrote by chtholly_micromaker(MicroMaker)
#include <bits/stdc++.h>
#define reg register
using namespace std;
template <class t> inline void read(t &s)
{
	s=0;
	reg int f=1;
	reg char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(isdigit(c))
		s=(s<<3)+(s<<1)+(c^48),c=getchar();
	s*=f;
	return;
}
int a[100050];
int n;
/*
inline bool all_same()
{
	for(int i=1;i<n;++i)
		if(a[i]!=a[i+1])
			return false;
	return true;
}
*/
inline void work()
{
	cin>>n;
	reg int mini=0x3f3f3f3f,maxi=0;
	for(int i=1;i<=n;++i)
		read(a[i]),mini=min(mini,a[i]),maxi=max(maxi,a[i]);
	if(mini>n-1)
	{
		puts("Yes");
		return;
	}
	// if(all_same())
	if(maxi==mini)
	{
		if(a[1]==1||a[1]==n-1)
		{
			puts("Yes");
			return;
		}
		if(a[1]<=n/2)
			puts("Yes");
		else
			puts("No");
		return;
	}
	if(maxi-mini>=2)
	{
		puts("No");
		return;
	}
	reg int cntmax=0,cntmin=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]==mini)
			++cntmin;
		if(a[i]==maxi)
			++cntmax;
	}
	if(mini<cntmin)
	{
		puts("No");
		return;
	}
	if(2*mini<n+cntmin-1)
	{
		puts("Yes");
		return;
	}
	puts("No");
	return;
}
signed main(void)
{
	// int t;cin>>t;
	// while(t--)
		work();
	return 0;
}

