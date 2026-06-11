#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int c,n;
	cin>>n;
	c=n*3;
	long long int i,a[c],s=0,x=0;
	for(i=0;i<c;i++)
	{
		cin>>a[i];
	}
	sort(a,a+c);
	for(i=c-2;i>=0;i=i-2)
	{
		s=s+a[i];
		x++;
		if(x>=n)
		{
			break;
		}
	}
	cout<<s<<endl;
	
}