#include<cstdio>
#include<iostream>
using namespace std;
const int N = 2e5+10;
int n,t,a[N];
int main()
{
	cin>>n>>t;
	for (int i = 0 ; i < n ; i++)
		scanf("%d",&a[i]);

	if (n == 1) { cout<< t<< endl; return 0;}

	int left = 0;
	long long curr = t;

	long long ans = 0;
	for (int i = 0; i < n ; i++)
	{
		if (a[i] <= curr) { curr = a[i] + t; continue; }

		ans += curr - a[left];
		left = i;
		curr = a[left] + t;
		if (i == n-1) ans+=t;
	}

	if (left != n-1)	ans += a[n-1] + t - a[left];
	cout<<ans<<endl;


return 0;
}