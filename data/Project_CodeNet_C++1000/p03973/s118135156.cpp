#include <iostream>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	int cur = 0;
	long long ans = 0;
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		if (x == cur + 1) {
			++cur;
		}
		else if (x > cur) {
			ans += (x - 1) / (cur + 1);
		}
		if (cur == 0) cur = 1;
	}
	cout << ans << endl;
	return 0;
}