#include <bits/stdc++.h>
#define int long long int
using namespace std;
signed main()
{
	int n, l, flag=0;
	cin>>n>>l;
	int total=0,  a[n+1];
	for (int i = 1; i <= n; ++i)
	{
		cin>>a[i];
		total += a[i];
	}
	if(total<l)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	for (int i = 1; i < n; ++i)
	{
		if(a[i]+a[i+1]>=l)
		{
			cout<<"Possible"<<endl;
			flag = i;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	for (int i = 1; i < flag; ++i)
	{
		cout<<i<<endl;
	}
	for (int i = n-1; i >= flag ; i--)
	{
		cout<<i<<endl;
	}
	return 0;
}