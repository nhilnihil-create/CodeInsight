#include<iostream>
using namespace std;
int main()
{
	int a,b,c,A;
	cin>>a>>b>>c;
	A=max(max(a,b),c);
	cout<<a+b+c-A;
	return 0;

 } 