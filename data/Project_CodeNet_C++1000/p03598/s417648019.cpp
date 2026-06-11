#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int n,k;
	cin>>n>>k;
	long int i,c,a[n],s=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		
	}
	for(i=0;i<n;i++)
	{
		c=abs(k-a[i]);
		if(c<=a[i])
		{
			s=s+c;
		}
		else
		{
			s=s+a[i];
		}
	}
	cout<<s*2<<endl;
}