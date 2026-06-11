#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define trav(t,a) for (auto& t: a)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;

#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()

const int MOD = 1000000007;
const double INF = 1e18;
const int MX = 100005;

int N,t;
vi adj[MX];
pi bound[MX];

int get(pi p) {
	int res = 0;
	FOR(i,p.f,p.s+1) res ^= 1<<i;
	return res;
}

map<int,bool> m;
vi ed;

int dfs(int x, int y) {
	int res = 0;
	bound[x].f = t++;
	trav(i,adj[x]) if (i != y) {
		int t = dfs(i,x)+1;
		res ^= t;
	}
	bound[x].s = t-1;
	return res;
}

bool win(int x) {
	if (m.count(x)) return m[x];
	trav(t,ed) if (x&t) if (!win(x^t)) return m[x] = 1;
	return m[x] = 0;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N;
	F0R(i,N-1) {
		int a,b; cin >> a >> b;
		adj[a].pb(b), adj[b].pb(a);
	}
	int x = dfs(1,0);
	if (x) cout << "Alice";
	else cout << "Bob";
}