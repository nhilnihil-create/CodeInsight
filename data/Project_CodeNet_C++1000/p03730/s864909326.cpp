#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int A,B,C;
	cin>>A>>B>>C;
	int ans=A;
	for(int i=1;i<=B;i++)
	{
		if((ans*i)%B==C)
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
