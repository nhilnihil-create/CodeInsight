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
#include <iomanip>
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

int main() {
	int h, w, n;
	cin >> h >> w >> n;
	set <pair<int, int>> st, black;
	auto addPoints = [&] (int a, int b) {
		int x1 = max(1, a - 2);
		int y1 = max(1, b - 2);
		int x2 = min(h, a + 2);
		int y2 = min(w, b + 2);
		for (int i = x1; i <= x2; i++) {
			for (int j = y1; j <= y2; j++) {
				st.insert({i, j});
			}
		}
	};
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		addPoints(a, b);
		black.insert({a, b});
	}
	auto calcPoints = [&](int x, int y) {
		int c = 0;
		for (int i = x; i < x + 3; i++) {
			for (int j = y; j < y + 3; j++) {
				if (black.find({i, j}) != black.end()) {
					c++;
				}
			}
		}
		return c;
	};
	vector <ll> ans(10);
	for (auto g : st) {
		if (g.ff + 2 <= h && g.ss + 2 <= w) {
			int val = calcPoints(g.ff, g.ss);
			ans[val]++;
		}
	}
	ll sum = 0;
	for (int i = 1; i < 10; i++) {
		sum += ans[i];
	}
	ans[0] = 1LL * (h - 2) * (w - 2) - sum;
	for (int i = 0; i < 10; i++) {
		cout << ans[i] << "\n";
	}
}
		
