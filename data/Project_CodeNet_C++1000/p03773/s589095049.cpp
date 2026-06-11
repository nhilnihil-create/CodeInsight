#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,sum=0;
	cin>>a>>b;
	sum =a+b;
	if(sum>=24)
	{
		cout<<(sum-24);
	}
	else
	{
		cout<<sum;
	}
	return 0;
}