#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,Max=0,T;
	cin>>n>>T;
	for(int i=1;i<=T;i++)
	{
		int x; cin>>x;
		Max=max(Max,x);
	}
	cout<<max(Max-1-(n-Max),0);
	return 0;
} 