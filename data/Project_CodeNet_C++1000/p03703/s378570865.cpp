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
#define MOD 1000000000
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define uid uniform_int_distribution <int>
using namespace std;
// Read the question carefully and see all the given sample tests
// Think about the correctness before implementing

/*
 * 10 2 5 8 3 1
 * 10 12 17 25 28 29
 * 28 - 25 >= k*1 -> 28 >= 25 + k*1
 * 28 - 17 >= k*2 -> 28 >= 17 + k*2
 * 28 - 12 >= k*3
 * 28 - 10 >= k*4
 * 10, 12 - k, 17 - 2*k, 25 - 3*k
 */
const int N = 200 * 1000 + 5;
vector <int> tree(N);
void update(int id, int val) {
	while(id < N) {
		tree[id] += val;
		id += (id & -id);
	}
}
int getsum(int id) {
	int res = 0;
	while(id > 0) {
		res += tree[id];
		id -= (id & -id);
	}
	return res;
}
int main() {
	int n, k;
	cin >> n >> k;
	vector <ll> pre(n + 1);
	map <ll, int> mp;
	mp[0];
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		pre[i] = pre[i - 1] + x;
	}
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i] - 1LL*i*k;
		mp[pre[i]];
	}
	int x = 0;
	for (auto g : mp) {
		mp[g.ff] = ++x;
	}
	update(mp[0], 1);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		pre[i] = mp[pre[i]];
		ans += getsum((int)pre[i]);
		update((int)pre[i], 1);
	}
	cout << ans;
}
