#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <bitset>
#include <stack>
#include <chrono>
#include <random>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define ll long long
#define INF 1000000000000000000
#define MOD 1000000007
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define uid uniform_int_distribution <int>
using namespace std;
// Read the question carefully and see all the given sample tests
// Think about the correctness before implementing

// i, mx(i, n) diff -> highest
// then you need to reduce the highest or increse the lowest by 1
const int N = 100 * 1000 + 5; 
vector <int> v[N];
vector <bool> vis(N, false);
int ev = 0, od = 0;
void dfs(int s, int c) {
	vis[s] = true;
	ev += (c % 2 == 0);
	od += (c % 2 == 1);
	for (auto g: v[s]) {
		if (!vis[g]) {
			dfs(g, c + 1);
		}
	}
}
int main() {
	int n, t;
	cin >> n >> t;
	vector <int> A(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	int mx = 0, mxPos = 0;
	int diff = 0;
	vector <int> nxt(n + 1);
	for (int i = n; i >= 1; i--) {
		if (mx < A[i]) {
			mx = A[i];
			mxPos = i;
		}
		nxt[i] = mxPos;
		diff = max(diff, mx - A[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (A[nxt[i]] - A[i] == diff) {
			v[i].push_back(nxt[i]);
			v[nxt[i]].push_back(i);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			ev = 0;
			od = 0;
			dfs(i, 0);
			ans += min(ev, od);
		}
	}
	cout << ans;
}
