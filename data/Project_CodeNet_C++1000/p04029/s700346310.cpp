#include <iostream>

using namespace std;

int main(void) {
	int N;
	int ans = 0;

	cin >> N;
	for (int i = 0; i <= N; i++) {
		ans += i;
	}
	cout << ans << endl;

	return 0;
}