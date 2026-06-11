#include<iostream>
using namespace std;
long long x[1000000];
int main()
{
	long long s=0,n,a,b;
	int i,j;
	cin>>n>>a>>b;
	for(i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	for(i=1;i<n;i++)
	{
		if((x[i+1]-x[i])*a<b)
		s+=(x[i+1]-x[i])*a;
		else
		s+=b;
	}
	cout<<s;
	return 0;
}