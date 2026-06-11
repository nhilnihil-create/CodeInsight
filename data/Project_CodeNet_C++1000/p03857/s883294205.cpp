#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <numeric>
using namespace std;
typedef long long int ll;

struct UnionFind{
    vector<int> par,num;
    vector<bool> done;
    UnionFind(int n):par(n),num(n,1),done(n,false){
    	iota(par.begin(),par.end(),0);
    }
    int find(int v){
        return (par[v]==v)?v:(par[v]=find(par[v]));
    }
    void unite(int u,int v){
        u=find(u),v=find(v);
        if(u==v)return;
        if(num[u]<num[v])swap(u,v);
        num[u]+=num[v];
        par[v]=u;
        done[u]=done[u]|done[v];
    }
    bool same(int u,int v){
        return find(u) == find(v);
    }
    bool ispar(int v){
        return v=find(v);
    }
    int size(int v){
        return num[find(v)];
    }
};

int main(){
	int n,k,l; cin >> n >> k >> l;
	UnionFind uf(n),uf1(n);
	for(int i=0;i<k;i++){
		int p,q; cin >> p >> q;
		p--; q--;
		uf.unite(p,q);
	}
	for(int i=0;i<l;i++){
		int r,s; cin >> r >> s;
		r--; s--;
		uf1.unite(r,s);
	}
	vector<pair<int,int> > v;
	map<pair<int,int> ,int> mp;

	for(int i=0;i<n;i++){
		v.push_back(make_pair(uf.find(i),uf1.find(i)));
	}
	sort(v.begin(),v.end());
	int cnt=1;
	for(int i=0;i<v.size()-1;i++){
		if(v[i]==v[i+1])cnt++;
		else{
			mp[v[i]]=cnt;
			cnt=1;
		}
	}
	mp[v[v.size()-1]]=cnt;
	for(int i=0;i<n;i++){
		cout << mp[pair<int,int>(uf.find(i),uf1.find(i))] <<  " ";
	}
	cout << endl;
}
