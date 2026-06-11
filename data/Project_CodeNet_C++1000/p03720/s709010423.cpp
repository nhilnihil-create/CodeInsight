#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int i,a[m],b[m],c[n]={0};
	for(i=0;i<m;i++)
	{
		cin>>a[i]>>b[i];
		c[a[i]-1]++;
		c[b[i]-1]++;
	}
	for(i=0;i<n;i++)
	{
		cout<<c[i]<<endl;
	}
}