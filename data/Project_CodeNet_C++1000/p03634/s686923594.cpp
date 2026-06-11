#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <math.h> 
#include <set>
#include <map>
#include <utility>
#include <deque>
#include <queue>


using namespace std;

#define ll long long int
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repp(i, n) for(int i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define riverse(v) reverse((v).begin(), (v).end())
#define pb push_back
#define mp make_pair
using vi = vector<int>;
using vs = vector<string>;
using vll = vector<ll>;
using vvi = vector<vi>;
const ll MOD = 1e9 + 7;


int main() {
	ll N;
	cin >> N;
	vector<vector<pair<int,int>>> g(N + 1);
	rep(i, N-1) {
		int a, b,c;
		cin >> a;
		cin >> b;
		cin >> c;
		g[a].pb(make_pair(b, c));
		g[b].push_back(mp(a, c));
	}
	int Q, K;
	cin >> Q >> K;
	vll distK(N + 1, -1);
	distK[K] = 0;
	queue<int> q;
	q.push(K);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (pair<int, int> u : g[v]) {
			if (distK[u.first] != -1) continue;
			distK[u.first] = distK[v] + u.second;
			q.push(u.first);
		}
	}
	vi x(Q);
	vi y(Q);
	rep(i, Q) {
		cin >> x[i];
		cin >> y[i];
	}
	rep(i, Q) {
		ll ans = 0;
		ans += distK[x[i]];
		ans += distK[y[i]];
		cout << ans << endl;
	}
}