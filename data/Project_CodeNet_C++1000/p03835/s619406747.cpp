#include <iostream>
using namespace std;

int main() {

	int k, s;
	cin >> k >> s;
	
	long long ans = 0;
	int diff = 0;
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j <= k; j++) {
			if (s - i - j < 0) {
				continue;
			}
			else if (s - i - j > k) {
				continue;
			}
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}