#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int n;
	cin>>n;
	long int i,x=0,a[n+1];
	for(i=1;i<n+1;i++)
	{
		cin>>a[i];
	}
	i=1;
	while(1)
	{
	
		if(i==2)
		{
			cout<<x<<endl;
			return 0;
		}
		if(x>n)
		{
			cout<<-1<<endl;
			return 0;
		}	
		x++;
		i=a[i];		
	}
}