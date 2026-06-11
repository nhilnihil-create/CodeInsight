#include<iostream>
using namespace std;
int N;
main()
{
	int ans=0,pre=0;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		int a,b;cin>>a>>b;
		if(pre<a)
		{
			pre=a;
			ans=a+b;
		}
	}
	cout<<ans<<endl;
}
