#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<n;i++)
#define range(i,a,n) for(int i=a;i<n;i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define INF 1e9
#define EPS 1e-9
#define MOD (1e9+7)
void put(string d){}template<class H,class...T>void put(string d,H&h,T&...t){cout<<h;if(sizeof...(t))cout<<d;put(d,t...);}
template<class T>void puti(T&a,string d=" "){bool f=1;for(auto&_:a)cout<<(exchange(f,0)?"":d)<<_;cout<<endl;}
template<class T>void putii(T&a,string d=" "){for(auto&_:a)puti(_,d);}

struct UnionFind{
	int n;
	vi p;
	UnionFind(int N){
		n=N;
		p.resize(n);
		iota(all(p),0);
	}
	void unite(int a, int b) {p[root(a)]=root(b);}
	int root(int a){return p[a]=(p[a]==a?a:root(p[a]));}
};


int main(){
	int n,K,L; cin>>n>>K>>L;
	UnionFind k(n),l(n);
	rep(i,K){
		int p,q; cin>>p>>q;
		k.unite(p-1,q-1);
	}
	rep(i,L){
		int p,q; cin>>p>>q;
		l.unite(p-1,q-1);
	}
	vector<pii> node;
	map<pii,int> nodemap;
	rep(i,n) {
		node.emplace_back(k.root(i),l.root(i));
		if(nodemap.find(node[i])==nodemap.end()) nodemap[node[i]]=0;
		nodemap[node[i]]++;
	}
	rep(i,n){
		cout<<nodemap[node[i]]<<(i+1==n?"\n":" ");
	}	
	return 0;
}
