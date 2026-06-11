#pragma once
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1000000007;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int pr[100010];
void uini(int n) {
	for (size_t i = 0; i <= n; i++)
	{
		pr[i] = i;
	}
}

int parent(int x) {
	if (x == pr[x]) return x;
	return pr[x] = parent(pr[x]);
}

bool unit(int x, int y) {
	int px = parent(x);
	int py = parent(y);

	if (px == py) return false;
	if (px < py) {
		pr[py] = px;
	}
	else {
		pr[px] = py;
	}
	return true;
}

map<int, map<int, int>> mp;
map<int, map<int, set<int>>> armp;

int parent(int x, int c) {
	if (mp[c][x] == 0) {
		armp[c][x].insert(x);
		mp[c][x] = x;
		return x;
	}
	if (mp[c][x] == x) return x;
	int pi = parent(mp[c][x], c);
	set<int> my = armp[c][x];
	armp[c][pi].insert(my.begin(), my.end());
	armp[c][x].clear();
	return mp[c][x] = pi;
}
void unite(int p, int q, int c) {
	int pp = parent(p, c);
	int qp = parent(q, c);

	if (pp < qp) {
		mp[c][qp] = pp;
		armp[c][pp].insert(armp[c][qp].begin(), armp[c][qp].end());
		armp[c][qp].clear();
	}
	else if (pp > qp) {
		mp[c][pp] = qp;
		armp[c][qp].insert(armp[c][pp].begin(), armp[c][pp].end());
		armp[c][pp].clear();
	}
}
void solv() {

	ll n;
	cin >> n;
	ll a[100010];
	ll sum = 0;
	ll one = (n * (n + 1)) / 2;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	if (sum % one != 0) {
		cout << "NO" << endl;
		return;
	}
	ll b = sum / one;
	ll bs = 0;
	for (int i = 0; i < n; i++)
	{
		int nex = (i + 1) % n;
		ll f = a[i];
		ll t = a[nex];
		if ((t - b - f) % n != 0) {
			cout << "NO" << endl;
			return;
		}
		if ((t - b - f) > 0) {
			cout << "NO" << endl;
			return;
		}
		bs += (t - b - f) / (-n);
	}

	if (bs == b) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;

}




int main() {
	solv();

	return 0;
}
