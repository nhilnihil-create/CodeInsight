#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <cstdint>

using namespace std;

int main() {
	int64_t n;
	cin >> n;
	int64_t a = 1;

	for (int64_t i = 1; i <= n; i++) {
		a *= i;
		a %= 1000000007;
	}

	cout << a << endl;

	return 0;
}