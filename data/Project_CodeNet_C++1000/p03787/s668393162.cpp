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
#define UNIQUE_ARRAY(a,x) unique(a + 1, a + x + 1) - a - 1
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
vll G[MAX];
ll color[MAX] = {};
ll isolate = 0;
ll conn = 0;
ll sigl = 0;

void dfs(ll start) {
	if (SIZE(G[start]) == 0) {
		isolate++;
		return;
	}
	bool flag = 0;
	color[start] = 0;
	stack<ll> st;
	st.push(start);
	while (!st.empty()) {
		ll cur = st.top();
		st.pop();
		for (auto nex : G[cur]) {
			if (color[nex] == -1) {
				color[nex] = !color[cur];
				st.push(nex);
			}
			else if (color[nex] == color[cur]) {
				flag = 1;
			}
		}
	}
	conn++;
	if (flag) {
		sigl++;
	}
}

int main() {
	ll n, m; cin >> n >> m;
	REP(i, 0, MAX - 1) {
		color[i] = -1;
	}
	REP(i, 1, m) {
		ll a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	REP(i, 1, n) {
		if (color[i] == -1) {
			dfs(i);
		}
	}
	ll ans = 0;
	ans = n * n - (n-isolate) * (n-isolate);
	ans += sigl * conn * 2 - sigl * sigl;
	ll semi = conn - sigl;
	ans += semi * semi * 2;
	cout << ans << endl;
}