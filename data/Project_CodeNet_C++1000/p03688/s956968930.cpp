#include<bits/stdc++.h>
using namespace std;

int num[100010],n;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	int mn=n+1,mx=0;
	for (int i=1;i<=n;i++) mn=min(mn,num[i]),mx=max(mx,num[i]);
	if (mx-mn>1) { puts("No");return 0; }
	if (mn==mx)
	{
		int h1=1,h2=n/2;
		if ((mn>=h1&&mn<=h2)||mn==n-1) puts("Yes");
		else puts("No");
	}
	else
	{
		int sum=0;
		for (int i=1;i<=n;i++) if (num[i]==mx) sum++;
		int h1=1,h2=sum/2;
		if (mx>=h1+n-sum&&mx<=h2+n-sum) puts("Yes");
		else puts("No");
	}
	return 0;
}