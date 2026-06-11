#include <bits/stdc++.h>

using namespace std;
int n;
int a[200005];
int f[200005];
int Check(int x)
{
	for(int i=1;i<=2*n-1;++i)
	{
		if(a[i]>=x)
		{
			f[i]=1;
		}
		else
		{
			f[i]=0;
		}
	}
	int nst=-1,nds=291433;
	for(int i=2;i<=2*n-1;++i)
	{
		if(f[i]==f[i-1])
		{
			if(min(abs(n-i+1),abs(n-i))<nds)
			{
				nds=min(abs(n-i),abs(n-i+1));
				nst=f[i];
			}
		}
	}
	if(nst==-1)
	{
		return f[1];
	}
	return nst;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n-1;++i)
	{
		scanf("%d",&a[i]);
	}
	int l=1,r=2*n-1;
	while(l+1<r)
	{
		int mid=(l+r)/2;
		if(Check(mid))
		{
			l=mid;
		}	
		else
		{
			r=mid;
		}
	}
	printf("%d",l);
	return 0;
}