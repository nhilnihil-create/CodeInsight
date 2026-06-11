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

/*
struct point
{
long long dist; long long name;
bool operator<(const point& rhs) const {
return dist > rhs.dist;
}
};
*/

ll const MAX = 100005;
ll tree[MAX];
ll parent[MAX];
ll n;
ll ord[MAX];
vll child[MAX];

void bfs() {
	queue<ll> qu;
	parent[1] = 1;
	qu.push(1);
	ll cnt = 1;
	while (!qu.empty()) {
		ll cur = qu.front();
		qu.pop();
		ord[cnt] = cur;
		cnt++;
		REP(i, 0, SIZE(child[cur]) - 1) {
			ll next = child[cur][i];
			if (next != parent[cur]) {
				qu.push(next);
			}
		}
	}
}

bool order(ll x, ll y) {
	return tree[x] > tree[y];
}

int main() {
	cin >> n;
	REP(i, 2, n) {
		cin >> parent[i];
		child[parent[i]].push_back(i);
	}
	bfs();
	PER(i, n, 1) {
		ll cur = ord[i];
		if (SIZE(child[cur]) == 0) {
			tree[cur] = 0;
		}
		else {
			sort(child[cur].begin(), child[cur].end(), order);
			ll cnt = -1;
			REP(j, 0, SIZE(child[cur]) - 1) {
				ll next = child[cur][j];
				cnt = max(cnt, tree[next] + j + 1);
			}
			tree[cur] = cnt;
		}
	}
	cout << tree[1] << endl;
}