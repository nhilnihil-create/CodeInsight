#include <iostream>
using namespace std;

int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a+b<b+a&&a+b<a+c)
	{
		cout<<a+b;
	}
	else if(b+c<a+b&&b+c<a+c)
	{
		cout<<b+c;
	}
	else if(c+a<b+a&&c+a<c+b)
	{
		cout<<c+a;
	}
	else
	{
		cout<<a+b;
	}
	return 0;
}