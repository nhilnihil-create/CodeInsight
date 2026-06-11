#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int r[n];
	int l[n];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> r[i] >> l[i];
		ans += l[i] - r[i] + 1;
	}
	cout << ans << endl;
	return 0;
}