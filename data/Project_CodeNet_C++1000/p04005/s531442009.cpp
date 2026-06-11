#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long t[10];
	for(int i=0;i<3;i++)
	cin>>t[i];
	for(int i=0;i<3;i++)
	{
		if(t[i]%2==0)
		{
			cout<<0<<endl;
			return 0;
		} 
	}
	sort(t,t+3);
	long long ans=t[0]*t[1];
	cout<<ans<<endl;
	
	return 0;
}  