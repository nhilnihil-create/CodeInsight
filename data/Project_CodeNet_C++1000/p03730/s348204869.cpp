#include <iostream>
#include <utility>
using namespace std;

int main() {

	int A, B, C;
	int remainder[110] = {0};
	bool flag = false;

	cin >> A >> B >> C;

	for (int i = 1; true; i++) {
		remainder[i] = (i * A) % B;
		if (remainder[0] == (i * A) % B)break;
	}

	for (int i = 0; i < 100; i++) {
		if (remainder[i] == C) {
			flag = true;
			break;
		}
	}

	cout << ((flag) ? "YES" : "NO");

	return 0;
}