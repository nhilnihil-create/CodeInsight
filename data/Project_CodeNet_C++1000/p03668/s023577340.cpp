#define _CRT_SECURE_NO_WARNINGS
#define TASK "C-large"
#pragma comment(linker, "/STACK:1710886400")
#include <stdio.h>
#include <iostream>
#include <iomanip> 
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <functional>
#include <assert.h>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <random>
#include <complex>
using namespace std;

const int MOD = 1000000007;
const int INF = 1000000007;
const long double EPS = 1e-6;
const int HASH_POW = 29;
const long double PI = acos(-1.0);
mt19937_64 rnd(1);

double workTime() {
	return double(clock()) / CLOCKS_PER_SEC;
}

void my_return(int code) {
#ifdef MYDEBUG
	cout << "\nTime = " << fixed << setprecision(3) << workTime() << endl;
#endif
	exit(code);
}

int n;
bool used[100010];
vector <int> G[100010];

int dfs(int v) {
	used[v] = true;
	int ans = 0;
	for (int i = 0; i < G[v].size(); ++i) {
		int to = G[v][i];
		if (!used[to]) {
			ans ^= dfs(to) + 1;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifdef MYDEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	/*freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);*/
#endif

	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}

	int res = dfs(1);
	if (res != 0) {
		printf("Alice\n");
	}
	else {
		printf("Bob\n");
	}

	my_return(0);
}