#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int N;
	cin>>N;
	int prev=0;
	ll ans=0;
	rep(i,N)
	{
		ll a;
		cin>>a;
		if(a==0)
		{
			prev=0;
		}
		ans+=(a+prev)/2;
		prev=(a+prev)%2;	
	}
	cout<<ans<<endl;
	return 0;
}
