#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;

#define ll long long
#define sz(s) (int)(s.size())
#define all(s) s.begin(), s.end()
#define mkp make_pair
#define eb emplace_back

const int N = 2e5 + 69;
const int NN = 2e3 + 69;
const int INF = 2e9 + 69;
const ll INF_LONG = 1e18;
const int mod = 1e9 + 7;
const int BLOCK = 174;

#define int ll

int h[N];

int a, b, n;

bool check(int x) {
	int cnt = 0;
	for (int i = 1; i <= n; ++ i) {
		int cur = h[i] - b * x;
		if (cur > 0) {
			if (cur % (a - b))
				cnt += cur / (a - b) + 1;
			else
				cnt += cur / (a - b);
		}
	}
	return (cnt <= x);
}

void solve() {
	cin >> n >> a >> b;
	for (int i = 1; i <= n; ++ i) {
		cin >> h[i];
	}
	int l = 0;
	int r = INF;
	while(r - l > 1) {
		int mid = (l + r) / 2;
		if (check(mid))
			r = mid;
		else
			l = mid;
	}
	cout << r << '\n';/*
	while(l < r) {
		int mid = (l + r) >> 1;
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	cout << l;*/
}

main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}
