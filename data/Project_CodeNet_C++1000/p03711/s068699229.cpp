#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using V = vector<int>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VVVL = vector<vector<vector<ll>>>;
using pq = priority_queue<int>;
template<class T>
using P = pair<T, T>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define REP(i,k,n) for(int i=(k);i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define output(x,y) cout << fixed << setprecision(y) << x << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int under = (1 << 31);
int upper = under - 1;
ll UNDER = (1LL << 63);
ll UPPER = UNDER - 1;
const int MOD = 1e9 + 7;
const long double pi = 3.141592653589793;
struct UnionFind {
	vector<int> par;
	UnionFind(int n) : par(n) {
		rep(i, n) par[i] = i;
	}
	int root(int x) {
		if (par[x] == x) return x;
		else return par[x] = root(par[x]);
	}
	void unite(int x, int y) {
		int rx = root(x);
		int ry = root(y);
		if (rx == ry) return;
		par[rx] = ry;
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
};
int main(){
	UnionFind G(13);
	G.unite(1, 3);
	G.unite(1, 5);
	G.unite(1, 7);
	G.unite(1, 8);
	G.unite(1, 10);
	G.unite(1, 12);
	G.unite(4, 6);
	G.unite(4, 9);
	G.unite(4, 11);
	int a, b;
	cin >> a >> b;
	puts((G.same(a, b)) ? "Yes" : "No");
	return 0;
}