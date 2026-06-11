#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <cstdint>

using namespace std;

int main() {
	int64_t a, b, x;
	cin >> a >> b >> x;
	int64_t cnt = 0;

	if (a == 0) {
		cnt = b / x + 1;
	}
	else {
		cnt = b / x - (a - 1) / x;
	}

	cout << cnt << endl;

	return 0;
}