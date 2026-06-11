#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,s,i;
	cin>>a>>b>>c;
	for(i=1;i<100;i++)
	{
		s=a*i;
		if(s%b==c)
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
}