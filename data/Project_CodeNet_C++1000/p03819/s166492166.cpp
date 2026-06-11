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

const int N = 100 * 1000 + 5;
vector <int> A[N];
vector <int> tree[4 * N];
vector<int> merge(vector<int> &x, vector<int> &y) {
	int a = 0, b = 0;
	vector <int> z;
	while(a < (int) x.size() && b < (int) y.size()) {
		if (x[a] < y[b]) {
			z.push_back(x[a++]);
		}
		else {
			z.push_back(y[b++]);
		}
	}
	
	while(a < (int) x.size())
		z.push_back(x[a++]);
	while(b < (int) y.size())
		z.push_back(y[b++]);
	
	return z;
}	
void build(int l, int r, int i) {
	if (l == r) {
		tree[i] = A[l];
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, 2 * i);
	build(mid + 1, r, 2 * i + 1);
	tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
}
int query(int ql, int qr, int l, int r, int i) {
	if (ql > r || qr < l)
		return 0;
	if (ql <= l && r <= qr) {
		int val = int(tree[i].end() - lower_bound(all(tree[i]), qr));
		return val;
	}
	int mid = (l + r) / 2;
	return query(ql, qr, l, mid, 2 * i) + query(ql, qr, mid + 1, r, 2 * i + 1);
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		A[l].push_back(r);
	}
	for (int i = 1; i <= m; i++) {
		sort(all(A[i]));
	}
	build(1, m, 1);
	for (int i = 1; i <= m; i++) {
		int ans = 0;
		for (int j = i; j <= m; j += i) {
			ans += query(j - i + 1, j, 1, m, 1);
		}
		cout << ans << "\n";
	}
}
