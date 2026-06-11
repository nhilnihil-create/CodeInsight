#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;


int main(void) {
	int n, i, a[300003] = {}, t;
	ll asmax[100005] = {}, asmin[100005] = {}, ans = -1e18;
	priority_queue<int, vector<int>, greater<int>> pq1;
	priority_queue<int> pq2;

	cin >> n;
	for (i = 0; i < n * 3; i++) {
		cin >> a[i];
	}

	for (i = 0; i < n; i++) {
		asmax[0] += a[i];
		pq1.push(a[i]);
	}

	for (i = n; i < n * 2; i++) {
		pq1.push(a[i]);
		t = pq1.top();
		pq1.pop();
		asmax[i - n + 1] = asmax[i - n] + a[i] - t;
	}

	for (i = n * 2; i < n * 3; i++) {
		asmin[n] += a[i];
		pq2.push(a[i]);
	}

	for (i = n * 2 - 1; i >= n; i--) {
		pq2.push(a[i]);
		t = pq2.top();
		pq2.pop();
		asmin[i - n] = asmin[i - n + 1] + a[i] - t;
	}

	for (i = 0; i <= n; i++) {
		ans = max(ans, asmax[i] - asmin[i]);
	}

	cout << ans << endl;

	return 0;
}