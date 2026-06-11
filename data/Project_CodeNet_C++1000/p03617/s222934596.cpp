#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	ll Q,H,S,D;
	cin>>Q>>H>>S>>D;
	ll N;
	cin>>N;
	vector<ll> bottle(3);
	bottle[0]=min(Q*2,H);
	bottle[1]=min(bottle[0]*2,S);
	bottle[2]=min(bottle[1]*2,D);
	cout<<N/2*bottle[2]+(N%2)*bottle[1]<<endl;
	return 0;
}
