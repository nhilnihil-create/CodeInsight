#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iomanip>


using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define REPO(i, n) for(int i = 1;i <= n;i++)
#define ll long long
#define INF 1999999999
#define MINF -1999999999
#define INF64 1999999999999999999
#define ALL(n) n.begin(),n.end()
#define MOD 1000000007

struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};
UnionFind tr(210000), ro(210000);
map<pair<ll, ll>, ll> m;
pair<ll, ll> s[210000];
ll n, k, l;
int main() {
	cin >> n >> k >> l;
	REP(i, k) { ll a, b; cin >> a >> b; a--; b--; tr.unionSet(a, b); }
	REP(i, l) { ll a, b; cin >> a >> b; a--; b--; ro.unionSet(a, b); }
	REP(i, n) {
		s[i] = make_pair(tr.root(i), ro.root(i));
		m[s[i]]++;
	}
	REP(i, n) {
		if (i != 0)cout << " ";
		cout << m[s[i]];
	}
	cout << endl;
}
