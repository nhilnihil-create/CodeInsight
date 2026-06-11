#include <iostream>
#include <string>
using namespace std;
int main()
{
	string x,y,z;
	int a,b;
	cin>>x>>y>>z;
	a=x.size()-1;
	b=y.size()-1;
	if(x[a]==y[0] && y[b]==z[0]) cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}