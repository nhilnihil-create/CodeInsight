#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int a_min = a[min_element(a.begin(), a.end()) - a.begin()];
	int a_max = a[max_element(a.begin(), a.end()) - a.begin()];
	int ans = 2147483647;;
	for (int i = a_min; i <= a_max; i++) {
		int tmp = 0;
		for (int j = 0; j < n; j++) {
			tmp += (a[j] - i) * (a[j] - i);
		}
		ans = min(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}