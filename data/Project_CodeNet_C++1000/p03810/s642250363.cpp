#define _GLIBCXX_IOSTREAM
#include<bits/stdc++.h>

typedef long long ll;

int n,s[200000];

bool solve()
{
	ll sum=0;int c=0,co=0,c2=0;
	if(n==1)return s[0]!=1;
	for(int i=0;i<n;i++)
	{
		sum+=s[i];
		c+=s[i]==1;
		co+=s[i]&1;
		c2+=s[i]==2;
	}
	if(c||co>1)return(sum-n)&1;
	if(~(sum-n)&1)
	{
		if(co==0)return 0;
		int t=0;
		for(int i=0;i<n;i++)
		{
			int v=s[i]&~1;
			t=std::__gcd(t,v);
		}
		for(int i=0;i<n;i++)
			s[i]/=t;
		return !solve();
	}
	if(c2||co==1)return 1;
	int mv=2e9,po;
	for(int i=0;i<n;i++)
	{
		if(s[i]<mv)mv=s[i],po=i;
	}
	s[po]--;
	return !solve();
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",s+i);
	bool ans=solve();
	puts(ans?"First":"Second");
}