#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
#include<stdio.h>
#include <cstdint>
#include <stdlib.h> 
#include <time.h>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define rrep(i,n) REP(i,1,n+1)
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define RNG(x, a, n) &((x)[a]), &((x)[n])
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> PII;
typedef vector<ll> Vl;
typedef vector<int> VI;
typedef tuple<int, int, int> TT;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define rall(v) v.rbegin(), v.rend()
#define dmp(x,y) make_pair(x,y)
#define dmt(x, y, z) make_tuple(x, y, z)
#define pb(x) push_back(x)
#define pf(x) push_front(x)
const int MAX = 5100000;
const int inf = 1e9 + 7;
const int mod = 1e9 + 7;
const ll longinf = 1LL << 60;
const long double PI = (acos(-1));
const long double EPS = 0.0000000001;


//UF木
struct UnionFind {
private:
	vector<int> par, ran, sz;
public:
	UnionFind(int n) {
		par.resize(n, 0);
		ran.resize(n, 0);
		sz.resize(n, 1);
		rep(i, n) {
			par[i] = i;
		}
	}
	int find(int x) {
		if (par[x] == x)return x;
		else return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y)return;
		if (ran[x] < ran[y]) {
			par[x] = y; sz[y] += sz[x];
		}
		else {
			par[y] = x; sz[x] += sz[y];
			if (ran[x] == ran[y])ran[x]++;
		}
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	int num(int x) { return sz[find(x)]; }
};

int n, k, l;


int main() {

	cin >> n >> k >> l;

	UnionFind uf1(n), uf2(n);

	rep(i, k) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		uf1.unite(a, b);
	}
	rep(i, l) {
		int c, d;
		cin >> c >> d;
		c--; d--;
		uf2.unite(c, d);
	}

	map<PII, int> mp;

	rep(i, n) {
		PII p = dmp(uf1.find(i), uf2.find(i));
		mp[p]++;
	}

	rep(i, n) {
		PII p = dmp(uf1.find(i), uf2.find(i));
		cout << mp[p] << " ";
	}
	cout << endl;

	return 0;
}