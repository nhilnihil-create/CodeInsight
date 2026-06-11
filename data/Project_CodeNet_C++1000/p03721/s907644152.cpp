#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	ll N,K;
	cin>>N>>K;
	vector<ll> kind(1e5+1,0);
	rep(i,N)
	{
		ll a,b;
		cin>>a>>b;
		kind[a]+=b;
	}
	rep(i,1e5+1)
	{
		K-=kind[i];
		if(K<=0)
		{
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
