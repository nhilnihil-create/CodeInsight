#include<bits/stdc++.h>
using namespace std;
int function(long long x,long long y)
{
	long long s=1;
	for(long i=1;i<=y;i++)
	s*=x;
	return s;
}
int main()
{
	long a,b;
	cin>>a>>b;
	if(a%3==0||b%3==0||(a+b)%3==0)cout<<"Possible"<<endl;
	else cout<<"Impossible\n";
	return function(0,2147);
}