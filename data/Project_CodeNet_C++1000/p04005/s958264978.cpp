#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	long long a[3];
	for(int i=0;i<3;i++)
	{
		cin>>a[i];
	}
	sort(a,a+3);
	if(a[2]%2==0)
	{
		cout<<"0";
	}
	else
	{
		long long ans=a[0]*a[1];
		cout<<ans;
	}
}