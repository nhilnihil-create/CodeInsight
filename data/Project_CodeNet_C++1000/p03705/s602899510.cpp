#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,a,b;
	cin>>n>>a>>b;
	long long max,min;
	max=b*(n-1)+a;
	min=a*(n-1)+b;
	if(max<min)
	cout<<0<<endl;
	else
	cout<<max-min+1<<endl;
	return 0;
 } 