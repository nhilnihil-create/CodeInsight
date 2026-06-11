#include<iostream>

using namespace std;
long long int n,a,b;
int main()
{
	cin>>n>>a>>b;
	if(n==1)
	{
		if(a==b)
			cout<<1;
		else cout<<0;
	}
	else 
	{
		if(a==b)cout<<1;
		else if(a>b)cout<<0;
		else
		{
			cout<<(n-1)*b+a-(n-1)*a-b+1;
		}
	}
}