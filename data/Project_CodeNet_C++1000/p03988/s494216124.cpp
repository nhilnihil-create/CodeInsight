#include<bits/stdc++.h>
using namespace std;
int n,a[110],s[110];
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		s[a[i]]++;
	}
	sort(a,a+n);
	if (s[a[0]]>2)
	{
		puts("Impossible");
		return 0;
	}
	for (int i=a[0]+1;i<=2*a[0]-s[a[0]]+1;i++)
	{
		if (s[i]<s[a[0]])
		{
			puts("Impossible");
			return 0;
		}
	}
	if (a[n-1]>2*a[0]-s[a[0]]+1)
	{
		puts("Impossible");
	}
	else
	{
		puts("Possible");
	}
	return 0;
}
