#include<iostream>
using namespace std;
int n;
main()
{
	cin>>n;
	int p=0;
	long cnt=0;
	for(;n--;)
	{
		long a;cin>>a;
		if(p+1>=a)
		{
			if(p<a)p=a;
			continue;
		}
		long now=a/(p+1);
		a%=p+1;
		if(a==0)
		{
			now--;
			a+=p+1;
		}
		if(p&&now>0)a=p;
		cnt+=now;
		if(p<a)p=a;
	}
	cout<<cnt<<endl;
}