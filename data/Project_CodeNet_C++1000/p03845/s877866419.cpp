#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int t[n],i,m,s=0;
	for(i=0;i<n;i++)
	{
		cin>>t[i];
		s=s+t[i];
	}
	cin>>m;
	int p[m],x[m],a[m];
	for(i=0;i<m;i++)
	{
		cin>>p[i]>>x[i];
		a[i]=s+(x[i]-t[p[i]-1]);
	}
	for(i=0;i<m;i++)
	{
		cout<<a[i]<<endl;
	}
	
}