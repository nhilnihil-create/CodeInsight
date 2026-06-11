#include <iostream>

using namespace std;

int main(void) {
	int N, K, X, Y;
	int ans = 0;
	int sab = 0;

	cin >> N >> K >> X >> Y;
	sab = N - K;
	if (sab < 0) {
		cout << N * X << endl;
	}
	else {
		ans = (K * X) + (sab * Y);

		cout << ans << endl;
	}

	return 0;
}