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

bool tup[100010];
bool aup[100010];
bool use[100010];

void solv() {
	ll n;
	cin >> n;
	ll t[100010];
	ll a[100010];
	tup[0] = true;
	aup[n - 1] = true;
	
	for (size_t i = 0; i < n; i++)
	{
		cin >> t[i];
		if (i > 0) {
			if (t[i] > t[i - 1]) {
				tup[i] = true;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (i > 0) {
			if (a[i - 1] > a[i]) {
				aup[i - 1] = true;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (tup[i]) {
			if (t[i] > a[i]) {
				cout << 0 << endl;
				return;
			}
		}

		int ai = n - i - 1;
		if (aup[ai]) {
			if (t[ai] < a[ai]) {
				cout << 0 << endl;
				return;
			}
		}
	}

	ll res = 1;
	for (int i = 0; i < n; i++)
	{
		if (!tup[i] && !aup[i] && !use[i]) {
			if (t[i] <= a[i]) {
				res *= t[i];
				res %= INF;
				use[i] = true;
			}
		}

		int ai = n - i - 1;
		if (!tup[ai] && !aup[ai] && !use[ai]) {
			if (a[ai] <= t[ai]) {
				res *= a[ai];
				res %= INF;
				use[ai] = true;
			}
		}
	}
	cout << res << endl;
}


int main() {
	solv();

	return 0;
}
