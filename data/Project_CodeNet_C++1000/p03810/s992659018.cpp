#include <bits/stdc++.h>
using namespace std;
int a[100005];
string out[]={"First","Second"};
int gcd(int a,int b)
{
	if (!a || !b)
	return (a^b);
	return __gcd(a,b);
}
int main()
{
	int n;
	cin >> n;
	for (int i=0;i<n;i++)
	cin >> a[i];
	for (int i=0;;i^=1)
	{
		int e=0;
		for (int j=0;j<n;j++)
		e+=(a[j]%2==0);
		if (e%2)
		{
			cout << out[i];
			return 0;
		}
		if (e!=n-1)
		{
			cout << out[!i];
			return 0;
		}
		int g=0;
		for (int j=0;j<n;j++)
		{
			if (a[j]==1)
			{
				cout << out[!i];
				return 0;
			}
			a[j]-=(a[j]%2);
			g=gcd(g,a[j]);
		}
		for (int j=0;j<n;j++)
		a[j]/=g;
	}
}