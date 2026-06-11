#include<iostream>
using namespace std;

long long int n,a,b,c, rs;
int main()
{
	rs=0;
	cin>>n>>a>>b;
	if(n==1&a==b)rs=1;
	else if(n>1&&a<=b)
	{
		rs=(n-2)*(b-a)+1;
	}

	cout<<rs<<endl;
}