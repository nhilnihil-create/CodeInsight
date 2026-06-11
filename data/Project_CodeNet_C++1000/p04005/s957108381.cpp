#include <iostream>
#include <algorithm>
using namespace std;

int a[10];

int main()
{
	for(int i=1;i<=3;i++)
		cin>>a[i];
	
	sort(a+1,a+4);
	if(a[1]%2==0||a[2]%2==0||a[3]%2==0)
		cout<<"0"<<"\n";
	else
	{
		int t=a[3];
		if(t%2==0)
			cout<<"0"<<"\n";
		else
		{
			long long tmp=(long long)a[1]*a[2];
			cout<<tmp<<"\n";
		}
	}
	return 0;
}