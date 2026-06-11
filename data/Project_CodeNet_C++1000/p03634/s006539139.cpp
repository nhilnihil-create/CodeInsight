#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <array>
#include <string>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define eb emplace_back
#define f first
#define s second
#define sz(x) (ll)x.size()
#define lnt(s) (ll)s.length()
#define mt(cnt) cnt.empty()
using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> osSet;

using pll = pair<ll, ll>;
using pl = pair<ll, pll>;
using tll = tuple<ll, ll, ll>;

const ll maxN = 1e5;
const ll INF = 1e17;
const ll MOD = 1e9 + 7;

ll xs[] = {-1, 1, 0, 0, -1, 1, 1, -1};
ll ys[] = {0, 0, -1, 1, -1, 1, -1, 1};

ll segtree[maxN << 2];
ll lazy[maxN << 2];
ll A[maxN];

inline ll left(ll x){
	return x << 1;
}

inline ll right(ll x){
	return (x<<1) + 1;
}

ll func(ll x){
	return (x*(x+1))/2;
}

ll _pow(ll b, ll p){
	if(p == 0) return 1;
	if(p == 1) return b;
	ll exB = b*b;
	if(p&1) return b*_pow(exB, p/2);
	return _pow(exB, p/2);
}

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vector<pll> adjlist[n+1];
	ll x, y, w;
	for(ll i=0; i<n-1; i++){
		cin >> x >> y >> w;
		adjlist[x].emplace_back(mp(y, w));
		adjlist[y].emplace_back(mp(x, w));
	}
	ll q, k;
	cin >> q >> k;
	vector<ll> dst(n+1, INF);
	dst[k] = 0;
	priority_queue<pll, vector<pll>, greater<pll>> pql;
	pql.push(mp(dst[k], k));
	while(!pql.empty()){
		pll tp = pql.top();
		pql.pop();
		for(auto edge : adjlist[tp.s]){
			ll to = edge.f;
			ll len = edge.s;
			if(dst[to] > len + dst[tp.s]){
				dst[to] = len + dst[tp.s];
				pql.push(mp(dst[to],to));
			}
		}
	}
	while(q--){
		cin >> x >> y;
		cout << dst[x]+dst[y] << "\n";
	}
	return 0;
}