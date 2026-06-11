#include<iostream>
using namespace std;
int main()
{
	long long a;
	cin>>a;
	for(long long i=1;i<10000000;i++)
	{
		if(((i+1)*i/2)>=a)
		{
			cout<<i;
			return 0;
		}
	}
 } 