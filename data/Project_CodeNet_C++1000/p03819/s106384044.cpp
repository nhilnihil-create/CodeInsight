#include <bits/stdc++.h>
using namespace std;

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define bg begin()
#define ed end()
#define all(x) (x).bg,(x).ed
#define si(x) int((x).size())
#define mp make_pair

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using ll=long long;
using pi=pair<int,int>;
using vi=vc<int>;

template<class t>
struct BIT{
	vc<t> buf;
	int s;
	BIT(int n=0){init(n);}
	void init(int n){buf.assign(s=n,0);}
	void add(int i,t v){
		for(;i<s;i+=(i+1)&(-i-1))
			buf[i]+=v;
	}
	t get(int i){
		t res=0;
		for(;i>=0;i-=(i+1)&(-i-1))
			res+=buf[i];
		return res;
	}
	t sum(int b,int e){
		return get(e-1)-get(b-1);
	}
	/*int kth(int k){
		int res=0;
		for(int i=topbit(s);i>=0;i--){
			int w=res+(1<<i);
			if(w<=s&&buf[w-1]<=k){
				k-=buf[w-1];
				res=w;
			}
		}
		return res;
	}*/
};

const int mmax=1.1e5;
vi rs[mmax];
vi facs[mmax];
int ans[mmax];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,m;cin>>n>>m;
	rep(i,n){
		int l,r;cin>>l>>r;
		rs[l].pb(r);
	}

	rng(i,1,m+1)for(int j=i;j<=m;j+=i)
		facs[j].pb(i);

	BIT<int> bit(m+1);
	rng(l,1,m+1){
		for(auto r:rs[l])
			bit.add(r,1);
		for(auto d:facs[l])
			ans[d]+=bit.sum(l,min(m+1,l+d));
	}

	rng(d,1,m+1)
		cout<<ans[d]<<'\n';
}
