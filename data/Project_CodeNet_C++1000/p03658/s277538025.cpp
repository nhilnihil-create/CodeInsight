#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int sum=0;
	for(int i=n-1;i>=0&&k>0;i--)
	{
		sum+=a[i];
		k--;
	}
	cout<<sum;
}