#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
bool v[N];
int n,a[N],l,r;
bool C(int k)
{
	for(int i=1;i<n+n;i++)
		v[i]=(a[i]>=k);
	for(int i=1;i<n;i++)
	{
		if(v[n+i]==v[n+i-1])
			return v[n+i];
		if(v[n-i]==v[n-i+1])
			return v[n-i];
	}
	return v[1];
}
int main()
{
	cin>>n;
	for(int i=1;i<n+n;i++)
		cin>>a[i];
	r=n+n;
	while(l<r)
		if(C((l+r+1)/2))
			l=(l+r+1)/2;
		else
			r=(l+r-1)/2;
	cout<<l;
	return 0;
}