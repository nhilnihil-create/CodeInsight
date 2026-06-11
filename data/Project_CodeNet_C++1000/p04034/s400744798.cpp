#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int N,M;
	cin>>N>>M;
	vector<bool> boll(N,false);
	vector<ll> boll_cnt(N,1);
	boll[0]=true;
	rep(i,M)
	{
		int x,y;
		cin>>x>>y;
		x--;y--;
		if(boll[x])
		{
			boll[y]=true;
		}	
		boll_cnt[y]++;
		if(boll_cnt[x]==1) 
		{
			boll[x]=false;
		}
		boll_cnt[x]--;
	}
	ll ans=0;
	rep(i,N)
	{
		if(boll[i]) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
