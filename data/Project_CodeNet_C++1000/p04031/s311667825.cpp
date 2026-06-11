#include <bits/stdc++.h>

using namespace std;

int main() {

	int n; scanf("%d", &n);

	vector<int> arr(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int m = 1e9;

	for (int i = -100; i <= 100; i++) {

		int cost = 0;

		for (int w : arr)
			cost += (w - i) * (w - i);

		m = min(m, cost);

	}

	printf("%d", m);

	return 0;

}