#include <iostream>
#include <string>
using namespace std;
int main()
{
	string x,y,z;
	cin>>x>>y>>z;
	char a,b,c;
	a=x[0]-32;
	b=y[0]-32;
	c=z[0]-32;
	cout<<a<<b<<c<<endl;
	return 0;
}