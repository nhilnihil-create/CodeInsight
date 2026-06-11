#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	string a,s;
	int g=0;
	cin>>a;
	s="CODEFESTIVAL2016";
	for(int i=0;i<=15;i++)
		if(a[i]!=s[i])
			g++;
	cout<<g<<endl;
	return 0;
}