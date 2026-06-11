#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <cstdint>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a.at(i);
	}

	int b = 1;
	int cnt = 1;
	bool flag = false;
	for (int i = 1; i <= n; i++) {
		if (a.at(1) == 2) {
			flag = true;
			break;
		}
		b = a.at(b);
		++cnt;
		if (a.at(b) == 2) {
			flag = true;
			break;
		}
	}

	if (flag) {
		cout << cnt << endl;
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}