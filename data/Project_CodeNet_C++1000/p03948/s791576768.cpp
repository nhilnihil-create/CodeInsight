#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

const double PI = 3.1415926535897932384626433832795;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
int lcm(int x, int y) { return x / gcd(x, y) * y; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, t;
	cin >> n >> t;

	vector<int> a(n);
	for (auto &v : a) {
		cin >> v;
	}

	map<int, int> mp;
	int buy = INT_MAX;
	for (int i = 0; i < n; i++) {
		buy = min(buy, a[i]);
		mp[a[i] - buy]++;
	}

	cout << mp.rbegin()->second << endl;
	return 0;
}
