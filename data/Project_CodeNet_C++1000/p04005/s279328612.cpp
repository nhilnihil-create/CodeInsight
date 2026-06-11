#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	long long a,b,c;
	cin>>a>>b>>c;
	if(a>c)
		swap(a,c);
	if(b>c)
		swap(b,c);
	if(c%2==0||a%2==0||b%2==0)
		a=0;
	cout<<a*b<<endl;
 } 