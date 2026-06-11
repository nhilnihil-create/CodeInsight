#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define inf (int)(3e18)
#define P pair<int,int>
#define mod (int)(1e9+7)

template<class T> inline void chmin(T &a, T b) {
	a = min(a, b);
}
template<class T> inline void chmax(T &a, T b) {
	a = max(a, b);
}

struct Query{
	int type;
	int a,b;
	bool operator<(const Query&c)const{
		return b-a<c.b-c.a;
	}
};
struct Segtree{
	vector<int>dat,lazy;
	int size=1;
	Segtree(int x){
		while(size<x)size*=2;
		dat.resize(size*2-1,0);
		lazy.resize(size*2-1,0);
	}
	void eval(int k,int l,int r){
		dat[k]+=lazy[k];
		if(r-l>1){
			lazy[k*2+1]+=lazy[k];
			lazy[k*2+2]+=lazy[k];
		}
		lazy[k]=0;
	}
	void update(int a,int b,int x,int k=0,int l=0,int r=-1){
		if(r==-1)r=size;
		eval(k,l,r);
		if(r<=a||b<=l)return;
		if(a<=l&&r<=b){
			lazy[k]+=x;
			eval(k,l,r);
			return;
		}
		update(a,b,x,k*2+1,l,(l+r)/2);
		update(a,b,x,k*2+2,(l+r)/2,r);
	}
	int query(int a,int k=0,int l=0,int r=-1){
		if(r==-1)r=size;
		eval(k,l,r);
		if(r-l==1)return dat[k];
		if(a<(l+r)/2)return query(a,k*2+1,l,(l+r)/2);
		return query(a,k*2+2,(l+r)/2,r);
	}
};
int N,M;
signed main() {
	cin>>N>>M;
	vector<Query>query;
	REP(i,M+1)query.push_back({true,0,i});
	rep(i,N){
		int l,r;cin>>l>>r;
		query.push_back({false,l,r+1});
	}
	sort(all(query));
	Segtree segtree(M+1);
	int cnt=0;
	rep(i,N+M){
		if(!query[i].type){
			segtree.update(query[i].a,query[i].b,1);
			cnt++;
		}else {
			int j=0,ans=0;
			while(j<=M){
				ans+=segtree.query(j);
				j+=query[i].b;
			}
			cout<<ans+N-cnt<<endl;
		}
	}
}
