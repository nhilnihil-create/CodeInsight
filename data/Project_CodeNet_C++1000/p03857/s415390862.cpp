#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 1e9 + 7;
const int INF = 1e9;

typedef pair<int, int> P;
typedef pair<P, int> Pi;
typedef pair<P, P> PP;

int par[200000];
int Rank[200000];

void init(int n) {
	for(int i = 0; i < n; ++i) {
		par[i] = i;
		Rank[i] = 0;
	}
}

int find(int x) {
	if(par[x] == x) return x;
	return par[x] = find(par[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(Rank[x] < Rank[y]) par[x] = y;
	else {
		par[y] = x;
		if(Rank[x] == Rank[y]) ++Rank[x];
	}
}

bool same(int x, int y) {
	return find(x) == find(y);
}

int road[200000], rail[200000];
map<P, int> mp;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int N, K, L;
	cin >> N >> K >> L;
	init(N);
	for(int i = 0; i < K; ++i) {
		int p, q;
		cin >> p >> q;
		--p; --q;
		unite(p, q);
	}
	for(int i = 0; i < N; ++i) road[i] = find(i);
	init(N);
	for(int i = 0; i < L; ++i) {
		int r, s;
		cin >> r >> s;
		--r; --s;
		unite(r, s);	
	}
	for(int i = 0; i < N; ++i) rail[i] = find(i);
	for(int i = 0; i < N; ++i) ++mp[P(road[i], rail[i])];
	for(int i = 0; i < N; ++i) {
		cout << mp[P(road[i], rail[i])]	;
		cout << ((i == N - 1) ? "\n" : " ");
	}
	return 0;
}