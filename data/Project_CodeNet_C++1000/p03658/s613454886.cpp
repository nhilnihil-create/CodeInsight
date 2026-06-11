#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	int l[n];
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}
	sort(l, l + n);
	reverse(l, l + n);
	int sum = 0;
	for (int i = 0; i < k; i++) {
		sum += l[i];
	}
	cout << sum << '\n';
	
	return 0;
}
