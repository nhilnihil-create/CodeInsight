#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <cstdlib>
#include <cmath>
#include <functional>

#define INF 1000000000000000000
using namespace std;
typedef long long ll;

int n;
ll k;
ll a[5010];
bool dp[5010];

bool need(int m) {
	for (int i = 1; i < k; i++) {
		dp[i] = false;
	}
	dp[0] = true;
	for (int i = 0; i < n; i++) {
		if (i == m)continue;
		for (int j = k - 1; j >= 0; j--) {
			if (dp[j] && (j + a[i]) < k) {
				dp[j + a[i]] = true;
			}
		}
	}
	for (int i = max(0, (int)(k - a[m])); i < k; i++) {
		if (dp[i])return true;
	}
	return false;
}


int main(){
	cin >> n>>k;
	int lo, hi;
	lo = 0; hi = n - 1;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	if (!need(n - 1)) {
		cout << n << endl;
		return 0;
	}
	while (lo != hi) {
		int mid = (lo + hi) / 2;
		if (need(mid)) {
			hi = mid ;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << lo << endl;

	return 0;
}
