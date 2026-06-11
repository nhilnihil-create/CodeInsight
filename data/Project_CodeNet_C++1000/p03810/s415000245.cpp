#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=1e5+9;
int n;
int a[N];

inline int gcd(int a,int b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}

inline bool solve()
{
	int flag=0;
	int odds=0;
	for(int i=1;i<=n;i++)
		if(a[i]&1)odds++;

	if(!odds)
	{
		for(int i=1;i<=n;i++)
			a[i]>>=1;
		return solve();
	}

	if(odds==1 && n&1)
	{
		int gcds=0;
		for(int i=1;i<=n;i++)
			gcds=gcd(a[i],gcds);
		for(int i=1;i<=n;i++)
		{
			if(a[i]==gcds)
				return 0;
			if(a[i]&1)
				a[i]-=gcds;
		}
		return !solve();
	}

	for(int i=1;i<=n;i++)
		flag^=((a[i]+1)&1);
	return flag;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	printf("%s\n",solve()?"First":"Second");
	return 0;
}
