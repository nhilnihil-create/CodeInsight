#include<iostream>
#include<algorithm>
using namespace std;
long long b[3];
int main ()
{
	cin>>b[0]>>b[1]>>b[2];
	sort(b, b+3);
	if(b[0]%2 == 0 || b[1]%2==0 || b[2]%2 == 0)	cout<<0<<endl;
	else
	{
		cout<<b[0]*b[1]<<endl;
	} 
	return 0;
} 