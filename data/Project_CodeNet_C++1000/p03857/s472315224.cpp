#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v)   (v).begin(),(v).end()
#define INF      (int)1e9
#define MOD      ((int)1e9+7)
using namespace std;
typedef long long     llong;
typedef pair<int,int> pii;
typedef vector<int>   vi;
typedef vector<vi >   vvi;
typedef vector<vvi >  vvvi;
template<class Type> void join(const Type &a){for(auto elem:a)cout<<elem<<' ';cout<<endl;}

struct UnionFind{
	vector<int> par;//xの親はpar[x].x自身が親ならpar[x]<0で、-par[x]がその集合のサイズ.
	
	UnionFind(int n):par(n,-1){}//コンストラクタ.
	
	void reset(int n){par.assign(n,-1);}
	int root(int x){return par[x]<0?x:par[x]=root(par[x]);}//再帰.
	int size(int x){return -par[root(x)];}
	bool same(int x,int y){return root(x)==root(y);}
	bool unite(int x,int y){
		x=root(x);
		y=root(y);
		if(x==y) return false;//do nothing.
		if(size(x)<size(y)) swap(x,y);//merge technique.
		par[x]+=par[y];
		par[y]=x;
		return true;
	}
};

int main(){
	int n,k,l;
	cin>>n>>k>>l;
	
	UnionFind uf(n),uff(n);
	REP(i,k){
		int p,q;
		scanf("%d%d",&p,&q);
		uf.unite(--p,--q);
	}
	REP(i,l){
		int r,s;
		scanf("%d%d",&r,&s);
		uff.unite(--r,--s);
	}
	
	map<pii,int> mp;
	REP(i,n){
		pii p(uf.root(i),uff.root(i));
		mp[p]++;
	}
	
	REP(i,n){
		pii p(uf.root(i),uff.root(i));
		cout<<mp[p]<<endl;
	}
	return 0;
}//解説参考.