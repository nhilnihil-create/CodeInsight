#include <iostream>

using namespace std;

int main(void) {
	int A, B, H;
	int ans = 0;

	cin >> A >> B >> H;

	ans = ((A + B) * H) / 2;

	cout << ans << endl;

	return 0;
}