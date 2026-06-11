#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long 
using namespace std;
int main()
{
	int w,a,b;cin>>w>>a>>b;
	if(a==b)cout<<0;
	else 
	{
		if(b>a+w)
		{
			cout<<b-a-w;
		}
		else if(a>b+w)cout<<a-b-w;
		else cout<<0;
	}
	
}