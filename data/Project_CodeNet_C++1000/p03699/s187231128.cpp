#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int i,a[n],s=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		s=s+a[i];
	}
	sort(a,a+n);
	if(s%10==0)
	{
		for(i=0;i<n;i++)
		{
			s=s-a[i];
			if(s%10!=0)
			{
				cout<<s<<endl;
				return 0;
			}
			else
			{
				s=s+a[i];
			}
		}
	}
	else
	{
		cout<<s<<endl;
		return 0;
	}
	cout<<0<<endl;
	
	
}