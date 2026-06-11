#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	vector<int> a(100009);
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		++a[x];
	}
	int ans = 0;
	for (int i = 0; i <= 100000; ++i) {
		ans = max(ans, a[i] + a[i + 1] + a[i + 2]);
	}
	cout << ans << '\n';	
	
	return 0;
}
