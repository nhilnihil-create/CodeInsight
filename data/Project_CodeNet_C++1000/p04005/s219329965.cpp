#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	ll A,B,C;
	cin>>A>>B>>C;
	if(A%2==0||B%2==0||C%2==0)
	{
		cout<<0<<endl;
	}
	else
	{
		cout<<min(min(B*C,A*C),A*B)<<endl;
	}
	return 0;
}
