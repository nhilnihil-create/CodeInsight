#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define SZ(a) (int)(a).size()
typedef long long ll;

bool iswin(vector<int>& a) {
	auto nodd = 0;
	for (auto x: a) {
		if (x & 1) {
			nodd++;
		}
	}
	auto neven = SZ(a)-nodd;
	if (neven & 1) {
		return true;
	}
	if (nodd > 1) {
		return false;
	}
	auto g = 0;
	for (auto& x: a) {
		if (x & 1) {
			if (x == 1) {
				return false;
			}
			x--;
		}
		g = __gcd(g, x);
	}
	for (auto& x: a) {
		x /= g;
	}
	return !iswin(a);
}

int main() {
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& x: a) {
		cin >> x;
	}
	auto ans = iswin(a);
	puts(ans ? "First" : "Second");
	return 0;
}
