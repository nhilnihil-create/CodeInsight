#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
using namespace __gnu_pbds;
using namespace std;

int n,_n,k,res,cnt,a[200010],sum[200010];
int sm[800010],addv[800010];
map<int,int> mp,pm;

inline void init(int x)
{
	_n=1;
	while(_n<x) _n*=2;
	for(int i=1;i<=2*_n;i++){sm[i]=0;addv[i]=0;}
}

inline void maintain(int o,int l,int r)
{
	int lc=o*2,rc=o*2+1;
	sm[o]=0;
	if(r>l){
		sm[o]=sm[lc]+sm[rc];
	}
	sm[o]+=addv[o]*(r-l+1);
}

inline void update(int o,int l,int r,int xx,int yy,int v)
{
	int lc=o*2,rc=o*2+1;
	if(xx<=l&&yy>=r){
		addv[o]+=v;
	}
	else{
		int m=l+(r-l)/2;
		if(xx<=m) update(lc,l,m,xx,yy,v);
		if(yy>m) update(rc,m+1,r,xx,yy,v);
	}
	maintain(o,l,r);
}

inline void query(int o,int l,int r,int add,int xx,int yy)
{
	if(xx<=l&&yy>=r){
		res+=sm[o]+add;
	}else{
		int m=l+(r-l)/2;
		if(xx<=m) query(o*2,l,m,add+addv[o],xx,yy);
		if(yy>m) query(o*2+1,m+1,r,add+addv[o],xx,yy);
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];a[i]-=k;
	}
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=0;i<=n;i++) mp[sum[i]]=1;
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
		cnt++;
		pm[it->first]=cnt;
	}
	for(int i=0;i<=n;i++) sum[i]=pm[sum[i]];
	int ans=0ll;
	init(cnt);
	for(int i=0;i<=n;i++){
		res=0ll;query(1,1,_n,0,1,sum[i]);
		ans+=res;
		update(1,1,_n,sum[i],sum[i],1ll);
	}
	cout<<ans<<endl;
	return 0;
}