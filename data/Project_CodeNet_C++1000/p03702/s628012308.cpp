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
 * sort everything in desc order
 * 6 5 3
 * 20 15 12 8 5 1
 * BS on the no of ops
 * and to decide on how many times to center a monster
 * x*A + (total - x)*B >= v[i]
 * x*(A - B) >= v[i] - total*B
 * x >= ceil((v[i] - total*B)/(A - B))
 */
int main() {
	int n, A, B;
	cin >> n >> A >> B;
	vector <int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	auto check = [&](ll mid) {
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			sum += max(0LL, (v[i] - mid * B + (A - B - 1)) / (A - B));
		}
		return (sum <= mid);
	};
	ll lo = 1, hi = MOD, ans = -1;
	while(lo <= hi) {
		ll mid = (lo + hi) / 2;
		if (check(mid)) {
			ans = mid;
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << ans;
}
