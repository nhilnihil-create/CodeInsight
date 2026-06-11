#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	map<int, int>a;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		a[tmp]++; a[tmp - 1]++; a[tmp + 1]++;
	}

	int ans = 0;
	for (auto&& x : a) {
		ans = max(ans, x.second);
	}
	cout << ans << endl;

	return 0;
}