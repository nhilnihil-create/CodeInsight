#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;
ll MOD = 1e9 + 7;

vector<int> G[100000];

int grundy[100000];

int calc(int v, int p) {
	if (grundy[v] != -1) return grundy[v];
	int x = 0;
	for (int to : G[v]) {
		if (to == p) continue;
		x ^= calc(to, v) + 1;
	}
	return grundy[v] = x;
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		x--; y--;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	memset(grundy, -1, sizeof(grundy));
	if (calc(0, -1) == 0) printf("Bob\n");
	else printf("Alice\n");
}