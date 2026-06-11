#include<map>
#include<bitset>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<stack>
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

/*
struct point
{
long long dist; long long name;
bool operator<(const point& rhs) const {
return dist > rhs.dist;
}
};
*/

ll const MAX = 200005;
ll a[MAX];
vll G[MAX];
ll parent[MAX]={};
ll ord[MAX];

void bfs(ll n) {
	queue<ll> qu;
	qu.push(1);
	parent[1] = 1;
	ll cnt = 1;
	while (!qu.empty()) {
		ll cur = qu.front();
		qu.pop();
		ord[cnt] = cur;
		cnt++;
		REP(i, 0, SIZE(G[cur]) - 1) {
			ll next = G[cur][i];
			if (parent[next] != 0)continue;
			parent[next] = cur;
			qu.push(next);
		}
	}
}

bool judge(ll i, ll n) {
	if (i != 1 && SIZE(G[i]) == 1) {
		return true;
	}
	ll c = 0;
	ll max_c = 0;
	REP(j, 0, SIZE(G[i]) - 1) {
		ll chi = G[i][j];
		if (chi != parent[i]) {
			c += a[chi];
			max_c = max(max_c, a[chi]);
		}
	}
	ll s, t;
	s = c - a[i];
	t = a[i] - s;
	if (s < 0 || t < 0) return false;
	if (s > min(c - max_c, c / 2)) return false;
	a[i] = t;
	return true;
}

int main() {
	ll n;
	cin >> n;
	REP(i, 1, n) {
		cin >> a[i];
	}
	REP(i, 1, n - 1) {
		ll x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	ll orig = a[1];
	bfs(n);
	PER(i, n, 1) {
		ll cur = ord[i];
		if (!judge(cur, n)) {
			cout << "NO" << endl;
			return 0;
		}
	}	
	if (a[1] == 0 && G[1].size() != 1) {
		cout << "YES" << endl;
	}
	else if (a[1] == orig && G[1].size() == 1) {
		cout << "YES" << endl;
	}

	else {
		cout << "NO" << endl;
	}
}