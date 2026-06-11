#include <queue>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <map>
#include <stdio.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for(int i = (a); i < (int)(b); i++)
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vint;
typedef vector<string> vstr;
typedef pair<ll, ll> pint;
unsigned long long inf = (1LL << 62);
ll mod = 998244353;
pint dx[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

ll min(ll a, ll b) {
	if (a < b)
		return a;


	return b;
}

ll max(ll a, ll b) {
	if (a < b)
		return b;

	return a;
}

ll d[100005], vis[100005];

ll N, K;
vector<ll> a;
vector<ll> child[100005];
ll parent[100005];


void dfs(ll s, ll dist) {
	rep(i, child[s].size()){
	
		if (child[s][i] != s) {
			d[child[s][i]] = dist + 1;
			dfs(child[s][i], dist + 1);
		}
	}

}

bool cut(ll s, ll dist) {

	if (vis[s] == 1)
		return false;

	vis[s] = 1;
	if (dist == K-1) {
		return true;
	}
	else {
		cut(a[s], dist + 1);
	}

}

int main() {
	cin >> N >> K;
	a.resize(N);
	rep(i, N) {
		cin >> a[i];
		a[i]--;

	}
	ll ans = 0;
	if(a[0] != 0){
		ans += 1;
		a[0] = 0;
	}


	rep(i, N) {
		child[a[i]].push_back(i);
	}

	dfs(0, 0);

	priority_queue<pint> q;
	rep(i, N) {
		q.push({ d[i], i });
	}

	rep(i, N) {
		if (q.top().first > K && vis[q.top().second] == 0) {

			if (cut(q.top().second, 0))
				ans += 1;

			
		}

		q.pop();
		
	}

	cout << ans << endl;
	return 0;
}
