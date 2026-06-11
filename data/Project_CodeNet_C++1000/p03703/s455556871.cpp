#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
using namespace __gnu_pbds;
using namespace std;

int n,k,cnt,a[200010],sum[200010],bit[200010];
map<int,int> mp,pm;

inline int sm(int p)
{
	int s=0ll;
	while(p>0){
		s+=bit[p];
		p-=p&(-p);
	}
	return s;
}

inline void add(int p)
{
	while(p<=cnt){
		bit[p]++;
		p+=p&(-p);
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
	for(int i=0;i<=n;i++){
		ans+=sm(sum[i]);
		add(sum[i]);
	}
	cout<<ans<<endl;
	return 0;
}