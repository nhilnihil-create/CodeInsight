#include <iostream>
using namespace std;

int main() {
	int p[3];
	for (int i = 0; i < 3; i++) {
		cin >> p[i];
	}

	int num = 0;
	int ans = 1e6;
	for (int i = 0; i < 3-1; i++) {
		for (int j = i+1; j < 3; j++) {
			num = p[i] + p[j];
			if (num < ans) {
				ans = num;
			}
		}
	}
	cout << ans << endl;
	return 0;
}