#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int i,x[n+1],c=0;
	string s;
	cin>>s;
	x[n]=0;
	for(i=0;i<n;i++)
	{ 	
		if(s[i]=='I')
		{
			c++;
		}
		else if(s[i]=='D')
		{
			c--;
		}
		x[i]=c;
	}
	sort(x,x+(n+1));
	cout<<x[n]<<endl;
	
}