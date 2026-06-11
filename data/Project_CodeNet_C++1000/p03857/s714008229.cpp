#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n)  RFOR(i,0,n)
#define VSORT(v) sort(v.begin(), v.end())
#define DVSORT(v) sort(v.begin(), v.end(),greater<int>())
#define SORT(v, n) sort(v, v+n)
#define DSORT(v,n) sort(v, v+n,greater<int>())
#define vi vector<int>
#define pb push_back
 
template <class T> void chmin(T&a,const T&b) { a = min(a,b); }
template <class T> void chmax(T&a,const T&b) { a = max(a,b); }
 
void print(){cout<<endl;}
template <class Head, class... Tail>
void print(Head&& h,Tail&&... t){ 
	if(sizeof...(t)==0)
		cout<<h;
	else
		cout<<h<<' ';
	print(move(t)...);
}
 
const double EPS =1e-9;
const long INF =2147483647;//32bit 2*1e+9
const long MOD =1e+9+7;
#define PI 3.14159265258979
#define P pair<int,int>
#define PPi pair<P,int>
 
int dy[]={0, 0, 1, -1, 1, 1, -1, -1};
int dx[]={1, -1, 0, 0, 1, -1, -1, 1};

struct UnionFind{
	vector<int> par; //データiが属する親の番号
	vector<int> sizes; //根ノードiの木に含まれるデータの数

	// 最初は全てのデータiがグループiに存在するものとして初期化
	UnionFind(int n):par(n),sizes(n, 1){
		REP(i,n) par[i] = i;
	}

	// 根を張り替えながら再帰的に根ノードを探す
	int find(int x){
		if(x==par[x]) return x;
		return par[x]=find(par[x]);
	}

	// 2つのデータx, yが属する木をマージする
	void unite(int x, int y) {
		// データの根ノードを得る
		x = find(x);
		y = find(y);

		// 既に同じ木に属しているならマージしない
		if (x == y) return;

		// xの木がyの木より大きくなるようにする
		if (sizes[x] < sizes[y]) swap(x, y);

		// xがyの親になるように連結する
		par[y] = x;
		sizes[x] += sizes[y];
		sizes[y] = 0;  // sizes[y]は無意味な値となるため
	}

	// 2つのデータx, yが属する木が同じならtrueを返す
	bool same(int x, int y) {
		return find(x) == find(y);
	}

	// データxが含まれる木の大きさを返す
	int size(int x) {
		return sizes[find(x)];
	}
};

int main(void){
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N,K,L,p,q;
	cin>>N>>K>>L;
	UnionFind road(N),train(N);
	REP(i,K){
		cin>>p>>q;
		road.unite(p-1,q-1);
	}
	REP(i,L){
		cin>>p>>q;
		train.unite(p-1,q-1);
	}

	map<P,int> mp;
	REP(i,N) mp[P(road.find(i),train.find(i))]++;

	REP(i,N) 
		printf("%d%c",mp[P(road.find(i),train.find(i))],i!=N-1 ?' ' :'\n');
	return 0;
}


