#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <numeric>
#include <string>
#include <cmath>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	int n, k;
	cin >> n;
	cin >> k;
	vector<int> x(n);
	vector<int> gap(n);

	int dist = 0;

	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}

	for (int i = 0; i < n; i++) {
		if (x[i] <= std::abs(k - x[i])) {
			dist += 2 * x[i];
		}
		else {
			dist += 2 * std::abs(k - x[i]);
		}
	}

	cout << dist;
	return 0;
}
