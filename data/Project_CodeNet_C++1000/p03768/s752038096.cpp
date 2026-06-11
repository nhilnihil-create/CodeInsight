#include<map>
#include<set>
#include<bitset>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<chrono>
#include<stack>
#include<fstream>
#include<list>
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define SIZE(a) ll(a.size())
#define vll vector<ll> 
#define MEMSET(a, n, m) for(ll i=0;i<=n;i++) a[i] = m
#define BIT(n) (ll(1)<<n)
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end()) 
#define UNIQUE_ARRAY(a,n) n = unique(a + 1, a + x + 1) - a - 1
#define SORT(a,n) sort(a+1,a+n+1)
#define SORT_O(a,n,order) sort(a+1,a+n+1,order)
#define PER(i,y,x) for(ll i=y;i>=x;i--)
typedef long long ll;
using namespace std;


struct edge
{
	long long to; long long len;
bool operator<(const edge& rhs) const {
return len > rhs.len;
}
};

ll const MAX = 300005;
vll G[MAX];
ll color[MAX] = {};
ll dis[MAX] = {};

void dfs(ll v, ll d, ll c) {
	if (dis[v] >= d) {
		return;
	}
	dis[v] = d;
	if (color[v] == 0) {
		color[v] = c;
	}
	REP(i, 0, SIZE(G[v]) - 1) {
		ll next = G[v][i];
		dfs(next, d - 1, c);
	}
}

ll v[MAX];
ll d[MAX];
ll c[MAX];

int main() {
	ll n, m;
	cin >> n >> m;
	REP(i, 0, MAX - 1) {
		dis[i] = -1;
	}
	REP(i, 1, m) {
		ll a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	ll q;
	cin >> q;
	REP(i, 1, q) {
		cin >> v[i] >> d[i] >> c[i];
	}
	PER(i, q, 1) {
		dfs(v[i], d[i], c[i]);
	}
	REP(i, 1, n) {
		cout << color[i] << endl;
	}
}