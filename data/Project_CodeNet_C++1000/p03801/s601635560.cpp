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

/*
 * 2 3 3 3
 * 4 2 3 1
 * pos -> (cur - nextmin) * cnt(gr)
 */
int main() {
	int n;
	cin >> n;
	map <int, int> mp, first;
	set <int> st;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (first[x] == 0) {
			first[x] = i;
		}
		mp[x]++;
		st.insert(x);
	}
	vector<int> v(all(st));
	reverse(all(v));
	vector <ll> ans(n + 1);
	ll sum = 0;
	int mn = MOD;
	for (int i = 0; i < (int) v.size(); i++) {
		sum += mp[v[i]];
		mn = min(mn, first[v[i]]);
		if (i + 1 < (int) v.size()) {
			ans[mn] += sum * (v[i] - v[i + 1]);
		}
		else {
			ans[mn] += sum * (v[i]);
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << "\n";
	}
}
