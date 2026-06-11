#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;

LL n,t,n2=1,a[200010],sum[200010],dat[800010],ans=0;
vector <LL> v;
map <LL,LL> mp;

void upd(LL k)
{
	dat[k]++;
	while(k>0)
	{
		k=(k-1)/2;
		dat[k]++;
	}
}

LL query(LL k,LL lb,LL ub,LL tlb,LL tub)
{
	if(ub<tlb||tub<lb) return 0;
	if(tlb<=lb&&ub<=tub) return dat[k];
	return query(k*2+1,lb,(lb+ub)/2,tlb,tub)+query(k*2+2,(lb+ub)/2+1,ub,tlb,tub);
}

int main()
{
	cin>>n>>t;
	rep(i,n)
	{
		scanf("%lld",&a[i]);
		a[i]-=t;
	}
	v.pb(0);
	repn(i,n)
	{
		sum[i]=sum[i-1]+a[i-1];
		v.pb(sum[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	rep(i,v.size()) mp[v[i]]=i;
	while(n2<v.size()+1) n2*=2;
	upd(mp[0]+n2-1);
	repn(i,n)
	{
		ans+=query(0,0,n2-1,0,mp[sum[i]]);
		upd(mp[sum[i]]+n2-1);
	}
	cout<<ans<<endl;
	return 0;
}