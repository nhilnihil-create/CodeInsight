#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e2 + 5;

int N, M;
int a[MAXN][MAXN];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%d", a[i] + j);
}

int solve() {
	int sol = N;
	vector <bool> active(M + 1, true);
	for (int k = 0; k < M; k++) {
		vector <int> occ(M + 1, 0);
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				if (active[a[i][j]]) {
					occ[a[i][j]]++;
					break;
				}
		int maks = max_element(occ.begin(), occ.end()) - occ.begin();
		sol = min(sol, occ[maks]);
		active[maks] = false;
	}
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}