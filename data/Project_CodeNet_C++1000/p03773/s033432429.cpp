#include<bits/stdc++.h>
using namespace std;
int a,b,z;
int main()
{
	cin>>a>>b;
	z=a+b;
	if(b==0)
		cout<<a;

	else if(z>23)
		cout<<z-24;

	else
		cout<<z;

	return 0;
}

