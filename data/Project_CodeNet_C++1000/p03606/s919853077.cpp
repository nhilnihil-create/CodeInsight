#include <iostream>
using namespace std;

int main(void) {
	int N;
	cin >> N;

	int ans = 0;

	for (int i = 0; i < N; i++) {
		int A, B;
		cin >> A >> B;
		ans += (B - A + 1);
	}

	cout << ans << endl;
}