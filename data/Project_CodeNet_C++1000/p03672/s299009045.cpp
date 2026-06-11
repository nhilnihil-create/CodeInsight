#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	long int i,x,j,n;
	n=s.size();
	n=n-2;
for(j=0;;j++)
	{
		x=0;
		for(i=0;i<n/2;i++)
		{	
		if(s[i]==s[(n/2)+i])
		{
			x++;	
		}
		}
		if(x==n/2)
		{
			cout<<x*2<<endl;
			return 0;
		}
		else
		{
			n=n-2;
		}
	}
	
	
}