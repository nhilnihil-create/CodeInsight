#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll x[222222];
int w[222222];
int I[222222];
ll ans[222222];
const int LG = 31;
int st[LG][222222];

int getnxt(int p, int times)
{
	for(int i=0;i<LG;i++)
	{
		if(times&(1<<i))
		{
			p=st[i][p];
		}
	}
	return p;
}

int circles[222222];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,L,t; cin>>n>>L>>t;
	vector<ll> V[2];
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>w[i]; w[i]--;
		x[i+n]=x[i]+L; w[i+n]=w[i];
	}
	for(int i=0;i<n;i++)
	{
		V[w[i]].pb(x[i]-L); V[w[i]].pb(x[i]); V[w[i]].pb(x[i]+L);
	}
	sort(V[0].begin(),V[0].end()); sort(V[1].begin(),V[1].end());
	for(int i=0;i<n;i++)
	{
		int ty=w[i];
		int shift = V[ty^1].size()/3;
		if(ty) shift*=-1;
		shift+=i;
		shift%=n;
		if(shift<0) shift+=n;
		st[0][i]=shift;
	}
	for(int i=1;i<LG;i++)
	{
		for(int j=0;j<n;j++)
		{
			st[i][j]=st[i-1][st[i-1][j]];
		}
	}
	ll shiftcnt = ((2LL*t)/L);
	for(int i=0;i<n;i++)
	{
		circles[i] = getnxt(i,shiftcnt);
		//cerr<<circles[i]<<' '; 
	}
	//cerr<<'\n';
	for(int i=0;i<n;i++)
	{
		int ty=w[i];
		ll id = 0;
		ll rem = (2LL*t)%L;
		if(!ty)
		{
			int lb = lower_bound(V[ty^1].begin(),V[ty^1].end(),x[i])-V[ty^1].begin();
			int rb = upper_bound(V[ty^1].begin(),V[ty^1].end(),x[i]+rem)-V[ty^1].begin();
			rb--;
			id+=rb-lb+1;
			id%=n;
		}
		else
		{
			int lb = lower_bound(V[ty^1].begin(),V[ty^1].end(),x[i]-rem)-V[ty^1].begin();
			int rb = upper_bound(V[ty^1].begin(),V[ty^1].end(),x[i])-V[ty^1].begin();
			rb--;
			id+=rb-lb+1;
			id*=-1;
			id%=n;
		}
		while(id<0) id+=n;
		id=circles[(i+id)%n];
		I[i]=id;
		//cerr<<i<<' '<<id<<'\n';
	}
	for(int i=0;i<n;i++)
	{
		ans[I[i]] = x[i] + (w[i]?-t:t);
		ans[I[i]]%=L;
		if(ans[I[i]]<0) ans[I[i]]+=L;
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<'\n';
	}
}
