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

int mul(int x, int y) {
	return int((1LL * x * y) % MOD);
}
int add(int x, int y) {
	x += y;
	if (x > MOD) x -= MOD;
	return x;
}
int power(int a, int b) {
	int res = 1;
	while(b != 0) {
		if (b & 1)
			res = mul(res, a);
		a = mul(a, a);
		b /= 2;
	}
	return res;
}
int inv(int x) {
	return power(x, MOD - 2);
}
int C(int n, int r) {
	if (n < r)
		return 0;
	if (r > n - r)
		r = n - r;
	int res = 1;
	for (int i = 1; i <= r; i++) {
		res = mul(res, n - i + 1);
		res = mul(res, inv(i));
	}
	return res;
}
int main() {
	int h, w, a, b;
	cin >> h >> w >> a >> b;
	vector <int> pre(w + 1);
	pre[b] = C((h - a) - 1 + b - 1, b - 1);
	for (int y = b + 1; y <= w; y++) {
		int n = (h - a) - 1 + y - 1;
		int r = y - 1;
		int val = 1;
		if (n != 0 && r != 0) {
			val = mul(val, n);
			val = mul(val, inv(r));
		}
		pre[y] = mul(pre[y - 1], val);
	}
	int ans = 0; 
	int res = 1;
	for (int y = w; y >= b + 1; y--) {
		int n = a - 1 + (w - y + 1) - 1;
		int r = (w - y + 1) - 1;
		if (n != 0 && r != 0) { 
			res = mul(res, n);
			res = mul(res, inv(r));
		}
		ans = add(ans, mul(pre[y], res));
	}
	cout << ans;
}
		
