#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <cmath>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;

int main() {
	int n;
	cin >> n;
	int odd = 0, even = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a % 2 == 1) {
			odd++;
		} else {
			even++;
		}
	}
	while (odd > 1 || even > 1) {
		even += odd / 2;
		odd %= 2;
		even = even % 2 + even / 2;
	}
	if (odd + even == 1) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}




