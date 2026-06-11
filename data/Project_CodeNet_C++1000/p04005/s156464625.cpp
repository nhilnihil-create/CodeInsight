#include<cstdio>
#include<iostream>
using namespace std;
long long maxx(long long a,long long b,long long c)
{
	if(a>=b&&a>=c) return a;
	if(b>=a&&b>=c) return b;
	if(c>=a&&c>=b) return c;
}
int main()
{
	long long A,B,C,maxs;
	cin>>A>>B>>C;
	maxs=maxx(A,B,C);
	if(A%2==0||B%2==0||C%2==0) cout<<"0"<<endl;
	else
	{
		if(A==maxs) cout<<B*C<<endl;
		else if(B==maxs) cout<<A*C<<endl;
		else cout<<A*B<<endl;
	}
	return 0;
}