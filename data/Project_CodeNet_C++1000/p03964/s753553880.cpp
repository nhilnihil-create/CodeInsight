#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	long long x,y,a,b,c,d;
	cin>>n>>x>>y;
	for(int i=1;i<n;i++)
	{
		cin>>a>>b;
		c=(x+a-1)/a;
		d=(y+b-1)/b;
		x=max(c,d)*a;
		y=max(c,d)*b;
	}
	cout<<x+y;
	return 0;
}