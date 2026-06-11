#include <bits/stdc++.h>
#define INF 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

class segtree2{
public:
	static const int N=1<<17;
	int dp[1<<18];
	segtree2(){
		for(int i=0;i<N*2;i++){
			dp[i]=INF;
		}
	}
	void update(int k,int v){
		k+=N-1;
		dp[k]=v;
		while(k>0){
			k=(k-1)/2;
			dp[k]=min(dp[k*2+1],dp[k*2+2]);
		}
	}

	int query(int a,int b,int k=0,int l=0,int r=N){
		if(b<=l || r<=a)return INF;
		if(a<=l && r<=b)return dp[k];
		int mid=(l+r)/2;
		int vl=query(a,b,k*2+1,l,mid);
		int vr=query(a,b,k*2+2,mid,r);
		return min(vl,vr);
	}
};

segtree2 seg2;
int n;
ll t;
ll a[100001];
vector<ll> vec;
vector<int> xid[100001];
P p[500001];
map<P,int> mp;

int main(void){
	scanf("%d%lld",&n,&t);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		vec.push_back(a[i]);
		p[i]=P(a[i],i);
	}
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	sort(p,p+n);
	ll ans=0;
	for(int i=0;i<n;i++){
		a[i]=lower_bound(vec.begin(),vec.end(),a[i])-vec.begin();
		xid[a[i]].push_back(i);
	}
	for(int i=0;i<n;i++){
		seg2.update(p[i].second,p[i].first);
		int mi=seg2.query(0,p[i].second);
		if(mi>=p[i].first)continue;
		int g=lower_bound(vec.begin(),vec.end(),mi)-vec.begin();
		int g2=lower_bound(vec.begin(),vec.end(),p[i].first)-vec.begin();
		int ct=lower_bound(xid[g].begin(),xid[g].end(),p[i].second)-xid[g].begin();
		mp[P(p[i].first,vec[g])]=min((int)ct,(int)xid[g2].size());
	}
	ll biggest=0;
	for(map<P,int>::iterator it=mp.begin();it!=mp.end();it++){
		P p=(*it).first;
		if(p.first-p.second>biggest){
			ans=0;
			biggest=p.first-p.second;
		}
		if(p.first-p.second==biggest){
			ans+=(*it).second;
		}
	}
	printf("%lld\n",ans);
	return 0;
}