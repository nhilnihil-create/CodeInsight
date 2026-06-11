#include <iostream>
using namespace std;
int main()
{
	unsigned long long n,a,s,g=0,q[100001];
	cin>>n>>a>>s;
	for(int i=1;i<=n;i++)
		cin>>q[i];
	for(int i=2;i<=n;i++)
		if((q[i]-q[i-1])*a>s)
			g+=s;
		else
			g+=(q[i]-q[i-1])*a;
	cout<<g<<endl;
	return 0;
}