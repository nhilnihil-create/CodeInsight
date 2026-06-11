#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <stack>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <set>
#include <stdio.h>
#include <ctype.h>
#include <random>
#include <string.h>
#include <cmath>
#include <unordered_map>
#include <cstdio>
using namespace std;
#define all(vec) vec.begin(),vec.end()
typedef long long ll;

ll gcd(ll x, ll y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
ll lcm(ll x, ll y) {
	return x / gcd(x, y)*y;
}
ll kai(ll x, ll y, ll m) {
	ll res = 1;
	for (ll i = x - y + 1; i <= x; i++) {
		res *= i; res %= m;
	}
	return res;
}
ll mod_pow(ll x, ll y, ll m) {
	ll res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}

ll comb(ll x, ll y, ll m) {
	if (y > x)return 0;
	return kai(x, y, m) * mod_pow(kai(y, y, m), m - 2, m) % m;
}

int n;
pair<int, int> x[510];
int cnt[510];
vector<int> ans;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i].first;
		x[i].second = i;
		if (1 < i)que.push(make_pair(x[i].first - 1, i));
	}
	sort(x + 1, x + n + 1);
	int k = 1;
	for (int i = 1; i <= n * n; i++) {
		if (i == x[k].first) {
			cnt[x[k].second]++;
			if (cnt[x[k].second] < x[k].second) {
				cout << "No" << endl;
				return 0;
			}
			ans.push_back(x[k].second);
			que.push(make_pair(n*n, x[k].second));
			k++;
		}
		else {
			if (que.empty()) {
				cout << "No" << endl;
				return 0;
			}
			pair<int, int> p = que.top();
			if (p.first < i) {
				cout << "No" << endl;
				return 0;
			}
			cnt[p.second]++;
			ans.push_back(p.second);
			if (cnt[p.second] == p.second - 1 || cnt[p.second] == n)que.pop();
		}
	}
	for (int i = 1; i <= n; i++)if (cnt[i] != n) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	for (int i = 0; i < (int)ans.size(); i++)cout << ans[i] << " ";
	cout << endl;
}
