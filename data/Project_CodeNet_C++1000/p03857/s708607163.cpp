#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
using namespace std;

#define INF 1.1e9
#define LINF 1.1e18
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define BIT(x,n) bitset<n>(x)

typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,P> PP;

struct edge {
	int to,cost;
	edge(int t,ll c):to(t),cost(c) {}
};

int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int ddx[]={1,1,1,0,-1,-1,-1,0},ddy[]={1,0,-1,-1,-1,0,1,1};

ll mypow(ll x,ll n,ll m) {
	if(n==0) return 1;
	if(n%2==0) return mypow(x*x%m,n/2,m);
	else return x*mypow(x,n-1,m)%m;
}

//-----------------------------------------------------------------------------

int n,k,l;
map<P,int> mp;

struct UnionFind {
	vector<int> data;
	UnionFind(int size):data(size,-1){}
	bool unite(int x,int y) {
		x=root(x),y=root(y);
		if(x!=y) {
			if(data[y]<data[x]) swap(x,y);
			data[x]+=data[y],data[y]=x;
		}
		return x!=y;
	}
	bool same(int x,int y) {
		return root(x)==root(y);
	}
	int root(int x) {
		return data[x]<0?x:data[x]=root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin>>n>>k>>l;
	UnionFind road(n);
	REP(i,k) {
		int a,b; cin>>a>>b;
		a--,b--;
		road.unite(a,b);
	}
	UnionFind train(n);
	REP(i,l) {
		int a,b; cin>>a>>b;
		a--,b--;
		train.unite(a,b);
	}
	REP(i,n) {
		mp[P(road.root(i),train.root(i))]++;
	}
	REP(i,n) {
		cout<<mp[P(road.root(i),train.root(i))]<<' ';
	}
	cout<<endl;

	return 0;
}
