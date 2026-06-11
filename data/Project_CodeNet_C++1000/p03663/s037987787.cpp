#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long

bool bo[233];

inline bool read()
{
	char ch=getchar();
	while (ch!='Y'&&ch!='N') ch=getchar();
	return (ch=='Y');
}

int main()
{
	ll tot=0;
	for (ll i=1;i<=10000000000LL;i*=10)
	{
		cout<<"? "<<i<<endl;
		bo[++tot]=read();
	}
	if (bo[tot]==1)
	{
		for (ll s=10;;s*=10)
		{
			cout<<"? "<<s-1<<endl;
			if (read()) { cout<<"! "<<s/10;return 0; }
		}
	}
	for (ll i=0;i<tot;i++) if (!bo[i+1])
	{
		ll l=1,r=1,ans;
		for (ll j=1;j<=i;j++) r*=10;
		l=r/10;
		while (l<r)
		{
			ll mid=(l+r)>>1;
			cout<<"? "<<mid*10<<endl;
			if (read()) r=mid;
			else l=mid+1;
		}
		cout<<"! "<<l;
		return 0;
	}
	return 0;
}