#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; ++i) cin >> p[i];
	int cnt = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (i + 1 == p[i]) {
			swap(p[i], p[i + 1]);
			++cnt;
		}
	}
	if (p[n - 1] == n) ++cnt;
	cout << cnt << "\n";
	return 0;
}